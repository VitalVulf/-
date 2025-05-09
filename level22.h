#include <SFML/Graphics.hpp>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <random>
#include <ctime>
#include "Sosat.hpp"
#include "DraggableText.h"
using namespace std;
using namespace sf;

class DraggableText {
public:
    DraggableText(const std::string& text, const sf::Font& font, unsigned int characterSize, const sf::Color& color, const sf::Vector2f& position)
        : m_text(text, font, characterSize) {
        m_text.setFillColor(color);
        m_text.setPosition(position);
        m_isDragging = false;
        m_isGreen = false;
        m_wasGreen = false;
        
    }

    void draw(sf::RenderWindow& window) {
        window.draw(m_text);
    }

    void handleEvent(sf::Event event, sf::RenderWindow& window) {
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            if (m_text.getGlobalBounds().contains(mousePos)) {
                m_isDragging = true;
                m_offset = m_text.getPosition() - mousePos;
            }
        }
        else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
            m_isDragging = false;
            checkColorChange(); // Check if color change is needed
        }
        else if (event.type == sf::Event::MouseMoved && m_isDragging) {
            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            m_text.setPosition(mousePos + m_offset);
        }
    }

    void checkColorChange() {
        if (m_text.getGlobalBounds().intersects(m_colorChangeArea)) {
            if (!m_isGreen) {
                m_text.setFillColor(sf::Color::Green);
                m_isGreen = true;
                m_wasGreen = true;
                greenTextCount++;
            }
        } else if (m_text.getPosition().x < 650 && m_text.getPosition().y < 700) {
            if (m_isGreen && m_wasGreen) {
                m_text.setFillColor(sf::Color::Red); // Change color back to red if not in color change area
                m_wasGreen = false;
				m_isGreen = false;
                greenTextCount--;
            } else if (m_text.getFillColor() != sf::Color::Green) {
                m_text.setFillColor(sf::Color::Red);
				 // Change color back to black if not in color change area
            }
        } else {
            m_text.setFillColor(sf::Color::Black); // Change color back to black if not in color change area
            m_isGreen = false;
            m_wasGreen = false;
        }
    }

    void setColorChangeArea(const sf::FloatRect& area) {
        m_colorChangeArea = area;
    }

    static int getGreenTextCount() {
        return greenTextCount;
    }

public:
    sf::Text m_text;
    bool m_isDragging;
    sf::Vector2f m_offset;
    sf::FloatRect m_colorChangeArea;
    bool m_isGreen;
    bool m_wasGreen;
    static int greenTextCount;
};



int DraggableText::greenTextCount = 0;


void shuffleArray(int arr[], int size) {
    srand(time(0));

    for (int i = size - 1; i > 0; i--) {
        int g = rand() % size;
        int k = rand() % size;
        if (g != k) {
            int temp = arr[g];
            arr[g] = arr[k];
            arr[k] = temp;
        }
    }
}
template <typename T>
void shuffleArray1(T arr[], int size) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_int_distribution<> dist(0, size - 1);

    for (int i = size - 1; i > 0; i--) {
        int j = dist(g);
        std::swap(arr[i], arr[j]);
    }
}

void okno(RenderWindow& window, Text& text, Font& font, string& str){
	Texture okna;
	okna.loadFromFile("images/povtori.jpg");
    Sprite okn(okna);
    okn.setPosition(240,240);
    okn.setScale(0.6f,0.4f);
    
    RectangleShape akno(Vector2f((okn.getGlobalBounds().width * 0.6f)+215, (okn.getGlobalBounds().height * 0.6f)+175));
    akno.setPosition(okn.getPosition());
    akno.setOutlineThickness(5);
    akno.setOutlineColor(Color::Black);
    akno.setFillColor(Color(128, 128, 128));
    
    text.setFont(font);
    text.setCharacterSize(30);
    text.setString("������: " + str + "/80");
    text.setFillColor(sf::Color::Black);
    text.setPosition(350,450);
    
    window.draw(akno);
    window.draw(okn);
    window.draw(text);
}

void lvl2(RenderWindow& window){
    window.setFramerateLimit(60);

    setlocale(LC_ALL, "Russian");
    bool vhod = true;
    
    bool ak[3] = {false, false, false};
    
    bool str[6] = {false, false, false, false, false, false};
    bool dtr[4] = {false, false, false, false};
    bool btr[6] = {false, false, false, false, false, false};
    bool Buranya[3] = {false, false, false};
    bool oknoo = false;
    View view(FloatRect(0, 0, 1024, 768));
    window.setView(view);
    int scoreUR1 = 0 , scoreUR2 = 0 , scoreUR3 = 0;
    Font font;
    font.loadFromFile("Oswald-VariableFont_wght.ttf");
    
    Texture tests;
    tests.loadFromFile("images/z_Meny_3_urowen.jpg");
    Sprite testik(tests);
    testik.setPosition(0,-20);
    testik.setScale(0.64f,0.5f);
    
    Texture mos;
    mos.loadFromFile("musorka.png");
    Sprite musor(mos);
    musor.setPosition(970,680);
    musor.setScale(0.06f,0.06f);
    
    RectangleShape pud;
    pud.setSize(Vector2f(255, 200));
    pud.setOutlineColor(Color::Black);
    pud.setOutlineThickness(3);
    pud.setFillColor(Color::Transparent);
    pud.setPosition(6,100);
    
    RectangleShape kud;
    kud.setSize(Vector2f(272, 200));
    kud.setOutlineColor(Color::Black);
    kud.setOutlineThickness(3);
    kud.setFillColor(Color::Transparent);
    kud.setPosition(376,100);
    
    RectangleShape rud;
    rud.setSize(Vector2f(252, 200));
    rud.setOutlineColor(Color::Black);
    rud.setOutlineThickness(3);
    rud.setFillColor(Color::Transparent);
    rud.setPosition(756,100);
    
    Table table(1, 1, 250, 30, sf::Color::White, sf::Color::Black, sf::Vector2f(40, 50), window);
    Table table1(1, 1, 350, 30, sf::Color::White, sf::Color::Black, sf::Vector2f(290, 50), window);
    Table table2(1, 1, 250, 160, sf::Color::White, sf::Color::Black, sf::Vector2f(40, 80), window);
    Table table3(1, 1, 350, 160, sf::Color::White, sf::Color::Black, sf::Vector2f(290, 80), window);
    Table table4(1, 1, 250, 130, sf::Color::White, sf::Color::Black, sf::Vector2f(40, 240), window);
    Table table5(1, 1, 350, 130, sf::Color::White, sf::Color::Black, sf::Vector2f(290, 240), window);
    Table table6(1, 1, 250, 130, sf::Color::White, sf::Color::Black, sf::Vector2f(40, 370), window);
    Table table7(1, 1, 350, 130, sf::Color::White, sf::Color::Black, sf::Vector2f(290, 370), window);
    Table table8(1, 1, 250, 130, sf::Color::White, sf::Color::Black, sf::Vector2f(40, 500), window);
    Table table9(1, 1, 350, 130, sf::Color::White, sf::Color::Black, sf::Vector2f(290, 500), window);
    Table table10(1, 1, 250, 130, sf::Color::White, sf::Color::Black, sf::Vector2f(40, 630), window);
    Table table11(1, 1, 350, 130, sf::Color::White, sf::Color::Black, sf::Vector2f(290, 630), window);
     
    int ochkoBash = 0;
    int ochkoALL = 0;
    int stp = 0;
    
    Text shag;
    shag.setFont(font);
    shag.setCharacterSize(18);
    shag.setString("������� 2.��� 1.�������� 1.");
    shag.setFillColor(sf::Color::Black);
    shag.setPosition(400,10);
    
    Text shag1;
    shag1.setFont(font);
    shag1.setCharacterSize(18);
    shag1.setString("������� 2.��� 1.�������� 2.");
    shag1.setFillColor(sf::Color::Black);
    shag1.setPosition(400,10);
    
    Text shag2;
    shag2.setFont(font);
    shag2.setCharacterSize(18);
    shag2.setString("������� 2.��� 1.�������� 3.");
    shag2.setFillColor(sf::Color::Black);
    shag2.setPosition(400,10);
    
    Text poz;
    poz.setFont(font);
    poz.setCharacterSize(18);
    poz.setString("�������������� ���");
    poz.setFillColor(sf::Color::Black);
    poz.setPosition(45,52);
    
    Text vud;
    vud.setFont(font);
    vud.setCharacterSize(18);
    vud.setString("���� ������� ������������");
    vud.setFillColor(sf::Color::Black);
    vud.setPosition(295,52);
    
    Text prikol;
    prikol.setFont(font);
    prikol.setCharacterSize(18);
    prikol.setString("");
    prikol.setFillColor(sf::Color::Black);
    prikol.setPosition(45,52);
    bool stran = false;
    int time = 0 ;
    String haha[5] = {
	"���������� ����� � ������������ \n� ������� �������.",
	"���������� �������� � ��������� \n������ ����� � ������������ � \n������� �������.",
	"������������� ��������� ��� \n��������� ������, ���� \n(�� ������ �������).",
	"��������������� ����� �� \n�������� ���������."
	};
	String haha1[5] = {
	"��������� ������� ������� \n������ ������ ���������, ������ \n���������, ������� ���������, \n������ ��������� ������ ���� � \n�������� ������.",
	"��������� ��������� �������� \n������ �� ������������� \n�������� �������.",
	"��������� ����� � ������.",
	"������������� ������ � \n������������ ��������� � \n���������� ������� �����."
	};
	String haha2[6] = {
	"������������ ������� ��� \n���������������� �������������� \n������ ����.",
	"�������� �������� ��������� \n����������: �������� ��������� \n����� �� ���������������� \n��������� ��������.",
	"�������� �������� ��������� \n����������: �������� ����� \n�������� � ����� �� ������� \n����, �������������� � ��������.",
	"������������� ����������� \n���������� - ������ ��������� \n������� �����.",
	"�������������� ��������� \n������ ��������� ������� �����."
	};
	
	
	int heheOt[21]{1,1,1,0,0,0,2,2,2,2,2,0,0,3,3,3,0,4,4,0,0};
	int f = 0;
	   String hehe[21] = {"�������� � ����� �����: ������� � ���������, ������� � ����������",
	   "��������,  ��� ������ � ��� ���������� ����� ",
	   "������������ ������� �� ��������� ",
	   "�������� �� ��������� ������� ��� ��������� ",
	   "��������� ���������� ������ ",
	   "��������� ���� ������ ������� ",
	   "���������� �������� ������ ����� ",
	   "���������� ��������� ������ ����� ",
	   "��������,  ��� ������ � ��� ���������� �������� � ��������� ������ �����  ",
	   "������ ����� �� ����� ������������ ",
	   "������ ����� �� ������������� ������������ ",
	   "�������������� �������� ������ � ����������� ����� �/��� ��� �������������� ",
	   "���������� ���� ���� ��� ���������� ����������� ������� ",
	   "���������� ����� �� ������� ��� ������������ ���� � ������ ",
	   "���������� ����� � ������ ������, ������������ �� ������ ����������� ������� ",
	   "���������� ����� �� ��������� �� ������� � ����������� ",
	   "���������� ������������������ ������������ ��������� ��� ��������� ������ � ������ ",
	   "���� �������������� ������ �� ������������ ����� ",
	   "�������� � ���� �������������� ������ � ������ (��������, �����) ����. ",
	   "�������� � �������� ������ ��� ���������� ",
	   "��������� ��������� �� ������������ �������� "
	};
 
int arr[21] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};  
int length = sizeof(arr) / sizeof(arr[0]);
    shuffleArray(arr, length);
	int heheOt1[14]{1,1,0,0,2,2,2,0,3,3,0,4,0,0};
	 String hehe1[14] = {"��������� ������� ������",
	   "������������� ������� ������ ���� �����, ������",
	   "�������� ���������� ������ ��� ���������� ����, �����������",
	   "����������� ������ � ����� ��������",
	   "�������� ��������� ����� �������� ������",
	   "������ ����� �������� ������ ��� ��������� ������ �����",
	   "�������� ����� �������� ������ ��� ��������� ������ �����",
	   "�������� � �������� ������ ��� ����������",
	   "��������� ������ �� ������������ �������� ����� � �������",
	   "�������������� ����������� ����� � ������������ � ������������ �������",
	   "�������� � ������",
	   "������ ������������� � ������������ ��������� � ���������� ������� ����� � ������� �������",
	   "�������������� ���������� ����� � �������� ��������� � ���������� ������� �����",
	   "����������� ������ � �������� � ��������� ������� �����"
	};
	  
int arr1[14] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13}; 
int length1 = sizeof(arr1) / sizeof(arr1[0]);
    shuffleArray(arr1, length1);
	int heheOt2[17]{1,1,1,0,2,0,0,3,3,0,4,4,0,0,5,5,5};
	 String hehe2[17] = {"���������� ������� ���������� ������������ ���� � ���������� �������",
	   "�������������� ���������� �������� ��� �������������� ������ ����",
	   "������������ ������ ����� � ������ ����  � ���������",
	   "���������� ������� ��� ����������� ����",
	   "�������������� ���������� �������� ��� ��������� ��������� �����",
	   "�������� �������� ��� �������� ������",
	   "������� ����� � ��������������� �������",
	   "�������������� ���������� �������� ��� ��������� ����� �������� � ������",
	   "������������� ������� � ������� ������������ ����� � ������������ ���������",
	   "������������� ������� � ������� ����� ��������� ����",
	   "�������� ���������� ������, ������ � �������� ������ �����",
	   "���� ��������������  ����������� ����� � ������������ � ������ � ������ �����",
	   "���� ��������������  ���������� ����� � ������������ � ������ � ������ �����",
	   "�������� ���������� ���� � �������� ������ �����",
	   "�������������� ���������� ������ ��������� ������� ����� �� ��������� ��������",
	   "��������� ������� �������� ��� ����������� �������, ������ � ������ ��������� ",
	   "���������� ������� ���������� ��������, ������������ �����,  � ������������ � �������� ������"
	};
	   
int arr2[17] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
int length2 = sizeof(arr2) / sizeof(arr2[0]);
    shuffleArray(arr2, length2);
	   std::vector<DraggableText> draggableTexts;
	   std::vector<DraggableText> draggableTexts1;
	   std::vector<DraggableText> draggableTexts2;
	   
	   
	
	   
	for(int i = 0 ; i < 21; i++){
draggableTexts.emplace_back(hehe[arr[i]], font, 14, sf::Color::Black, sf::Vector2f(680, 60 + (30 * i)));
		
	}
	for(int i = 0 ; i < 14; i++){
draggableTexts1.emplace_back(hehe1[arr1[i]], font, 14, sf::Color::Black, sf::Vector2f(680, 60 + (30 * i)));		
	}
	for(int i = 0 ; i < 17; i++){
draggableTexts2.emplace_back(hehe2[arr2[i]], font, 14, sf::Color::Black, sf::Vector2f(680, 60 + (30 * i)));		
	}

vector<DraggableTextNoColor> draggableTextNoColor;
vector<DraggableTextNoColor> draggableTextNoColor1;
vector<DraggableTextNoColor> draggableTextNoColor2;
			
	for(int i = 0 ; i < 21; i++){
draggableTextNoColor.emplace_back(hehe[arr[i]], font, 14, sf::Color::Black, sf::Vector2f(680, 60 + (30 * i)));
		
	}
	for(int i = 0 ; i < 14; i++){
draggableTextNoColor1.emplace_back(hehe1[arr1[i]], font, 14, sf::Color::Black, sf::Vector2f(680, 60 + (30 * i)));		
	}
	for(int i = 0 ; i < 17; i++){
draggableTextNoColor2.emplace_back(hehe2[arr2[i]], font, 14, sf::Color::Black, sf::Vector2f(680, 60 + (30 * i)));		
	}
	    sf::Clock clock;
	
    sf::Text timerText;
    timerText.setFont(font);
    timerText.setCharacterSize(24);
    timerText.setFillColor(sf::Color::Black);
    timerText.setPosition(720, 10);
    
    Text Score1;
    Score1.setFont(font);
    Score1.setCharacterSize(16);
    Score1.setFillColor(sf::Color::Black);
    Score1.setPosition(650, 700);
	
    Text textt("�����", font, 20);
    textt.setFillColor(Color::Black);
    textt.setPosition(885, 15);
	 
    Text rerun("���������� �������", font, 20);
    rerun.setFillColor(Color::Black);
    rerun.setPosition(525, 425); 
    Text contin("������� �� ��������� �������", font, 20);
    contin.setFillColor(Color::Black);
    contin.setPosition(525, 475); 
    
    RectangleShape tt;
    tt.setSize(Vector2f(60, 40));
    tt.setOutlineColor(Color::Black);
    tt.setOutlineThickness(3);
    tt.setFillColor(Color::Transparent);
    tt.setPosition(880,10); 
    
    RectangleShape tt1;
    tt1.setSize(Vector2f(60, 40));
    tt1.setOutlineColor(Color::Black);
    tt1.setOutlineThickness(3);
    tt1.setFillColor(Color::Transparent);
    tt1.setPosition(880,10);
    
    Text textt1("��� 2", font, 20);
    textt1.setFillColor(Color::Black);
    textt1.setPosition(885, 15); 
    
    RectangleShape t;
    t.setSize(Vector2f(60, 40));
    t.setOutlineColor(Color::Black);
    t.setOutlineThickness(3);
    t.setFillColor(Color::Transparent);
    t.setPosition(880,10);
    
    RectangleShape t1;
    t1.setSize(Vector2f(60, 40));
    t1.setOutlineColor(Color::Black);
    t1.setOutlineThickness(3);
    t1.setFillColor(Color::Transparent);
    t1.setPosition(880,10);
    
    RectangleShape t2;
    t2.setSize(Vector2f(60, 40));
    t2.setOutlineColor(Color::Black);
    t2.setOutlineThickness(3);
    t2.setFillColor(Color::Transparent);
    t2.setPosition(880,10);
    
    Text text("�����", font, 20);
    text.setFillColor(Color::Black);
    text.setPosition(805,15);
    
    RectangleShape nz;
    nz.setSize(Vector2f(60, 40));
    nz.setOutlineColor(Color::Black);
    nz.setOutlineThickness(3);
    nz.setFillColor(Color::Transparent);
    nz.setPosition(800,10);
    
    RectangleShape nz1;
    nz1.setSize(Vector2f(60, 40));
    nz1.setOutlineColor(Color::Black);
    nz1.setOutlineThickness(3);
    nz1.setFillColor(Color::Transparent);
    nz1.setPosition(800,10);
    
    RectangleShape nz2;
    nz2.setSize(Vector2f(60, 40));
    nz2.setOutlineColor(Color::Black);
    nz2.setOutlineThickness(3);
    nz2.setFillColor(Color::Transparent);
    nz2.setPosition(800,10);
    
    int countdown;
//---------------------------------------------------------------------------------------- �������������� �.1


    String haha3[5] = {
	"������������ ��������.",
	"�������� ������  � \n������������ � ������ � \n��������� ������� � \n�������� �����.",
	"��������� ������������ \n��������� � ����������� \n��������� � �������� \n������� ����� �������� \n�������.",
	"��������� ������� ������� \n�������."
	};
	
	
		int UR2heheOt[15]={1,0,2,0,3,3,3,3,0,4,4,4,4,0,0};
	 String UR2hehe[15] = {
	"�������, �� ���������, �������������",
	"��������� ��������� �� �������� �������������",
	"�������� ������, ��������������� ������� ��������",
	"�������� � ������",
	"���������  ��������� ������ � ������������,  �������� �����������.",
	"��������� ��������� �������",
    "��������� ������� � ����� ������ ��������",
	"���������� � ��������� �����, ����������� �� ���������� �������� ���������",
	"������ �� ��������, ����������� ������� ���������",
	"����������� ������ � ������������, ������������� ������ �������� �������",
	"������� �����������, �� ��������� ���",
	"��������� ����������� ������������ � ���� �������",
	"������ ������� ������������ �� �������� ����������� �����",
	"�������������� �� ����� ���� ���������� ������������ ",
	"���������� ���� ����� ������",	 	
	};
	   
int UR2arr[15] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
int UR2length = sizeof(arr2) / sizeof(arr2[0]);
    shuffleArray(UR2arr, UR2length);
	
std::vector<DraggableText> UR2draggableTexts;

	for(int i = 0 ; i < 15; i++){
UR2draggableTexts.emplace_back(UR2hehe[UR2arr[i]], font, 14, sf::Color::Black, sf::Vector2f(680, 60 + (30 * i)));
		
	}

//---------------------------------------------------------------------------------------- �������������� �.2



    String UR2haha1[5] = {
	"������������ ������ ����� \n������ � �������� \n�������� �������.",
	"�������� �� ������� �� \n���������� ���������.",
	"������� ������ ������� \n������������ �� \n����������� ������ �������.",
	"������� ������ ������� \n������������ � �������� \n� ��������� ������� �����."
	};
	
	
		int UR2heheOt1[15]={1,1,1,0,0,2,2,0,3,0,0,4,4,4,0};
	 String UR2hehe1[15] = {
	"�����������  ������ ��������",
	"��������� ����� ������ � �������� �������� �������, �������� �� ������",
	"������������� ������ ����� ������",
	"��������� ������������ ��������",
	"�������� � ����",
	"��������� ���������� ��� ������",
    "�������� �� ������������ ������� �� ���������� ���������",
	"����������� ���� �������",
	"������ ������ ������������ �� ����������� ������ �������, ������������ ���� �����",
	"�������������� ��������� ������� �� ����������� ������ �������, �� ������� ������������������ ��������",
	"�������������� �������� ������ � ����������� ����� �/��� ��� ��������������",
	"������ ������ ������������ �� ����������� ������ �������, ���������� ��� ���������",
	"������ ������ ������������ ��� ������� ��������� ������� �����, ������������ ���� �����",
	"������ ������ ������������ ��� ������� ���������� ������� �����, ������������ ���� �����",
	"�������������� ���������� ������� �������� ��� ���������� ��������� ������� �����",	 	
	};
	   
int UR2arr1[15] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
int UR2length1 = sizeof(arr2) / sizeof(arr2[0]);
    shuffleArray(UR2arr1, UR2length1);
	
std::vector<DraggableText> UR2draggableTexts1;

	for(int i = 0 ; i < 15; i++){
UR2draggableTexts1.emplace_back(UR2hehe1[UR2arr1[i]], font, 14, sf::Color::Black, sf::Vector2f(680, 60 + (30 * i)));	
}
	
//-------------------------------------------------------------------------------��������������� ��� 2 ��� 1

vector<DraggableTextNoColor> draggableTextNoColorUR2;
for(int i = 0 ; i < 15; i++){
draggableTextNoColorUR2.emplace_back(UR2hehe[UR2arr[i]], font, 14, sf::Color::Black, sf::Vector2f(680, 60 + (30 * i)));	
	}
	
//-------------------------------------------------------------------------------��������������� ��� 2 ��� 2
vector<DraggableTextNoColor> draggableTextNoColor1UR2;
for(int i = 0 ; i < 15; i++){
draggableTextNoColor1UR2.emplace_back(UR2hehe1[UR2arr1[i]], font, 14, sf::Color::Black, sf::Vector2f(680, 60 + (30 * i)));	
	}
//-------------------------------------------------------------------------------������������ ��� ���1

	String haha4[5] = {
	"����������� ������������������ \n������� �������� ��� \n���������� ��������� \n������� �����.",
	"����������� ������������������ \n������� �������� ��� ����������.",
	"���������� ������� ������ \n��� ���������� ��������� �������.",
	"���������� ������� ������ \n���  ����������� ������  �������.",
	"���������� ������� ������ \n��� ���������� ������"
	};
	
	
	int UR2heheOt_1[15]={1,1,0,2,2,0,3,0,0,4,4,0,5,0,0};
	 String UR2hehe_1[15] = {
	"�������������� ���������� ������� �������� ��� ���������� ��������� ������� �����",
	"���������� ������������������ ��������� ������� ����� � ������� �������",
	"�������� ������������� ������������� ����� �������� � �������� ���������",
	"�������������� ���������� ������� �������� ��� ����������",
	"���������� �����������  �������� ��� ����������  � ������� �������",
	"���������, �������� ������� �������",
    "�������� ������� ������ �� ���������� ����� ������ ��� ���������� ��������� �������",
	"�������� ������� ������ ����� ��� ���������� ��������� ������� �����",
	"���������� ������� ������ ����� ����� ��� ���������� ��������� ������� �����",
	"�������� ������� ������ �� ���������� ����� ������ ��� ����������� ������ �������",
	"�������������� ��������� ������� �� ����������� ������ �������, �� ������� ������������������ ��������",
	"���������� ������� ������ ����� ����� ��� ����������� ������ �������",
	"�������������� ��������� �����, �������� �������",
	"���������� ������� ������ ����� ��� ���������� ������",
	"��������� �����",	 	
	};
	
int UR2arr_1[15] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
int UR2length_1 = sizeof(arr2) / sizeof(arr2[0]);
    shuffleArray(UR2arr_1, UR2length_1);
	
std::vector<DraggableText> UR2draggableTexts_1;

	for(int i = 0 ; i < 15; i++){
UR2draggableTexts_1.emplace_back(UR2hehe_1[i], font, 14, sf::Color::Black, sf::Vector2f(680, 60 + (30 * i)));
		
	}
//------------------------------------------------------------------------------������������ ��� ���2

String haha5[5] = {
	"����������  �������  ������ \n��� ������ ��� ��������.",
	"�������� ���������  ������, \n���������� ��� ���������� \n��������� �������.",
	"�������� ���������  ������, \n���������� ��� ������ \n��� ��������.",
	"�������� ���������  ������, \n���������� ��� ���������� \n����, �����������.",
	"��������� ������������ ��������� \n����, ���������� ����, \n����, �����������."
	};
int UR2heheOt_2[19]={1,1,0,2,2,0,3,0,0,4,4,0,5,0,0};
	 String UR2hehe_2[19] = {
	"����� ��� ��������, �� ������� ��������",
	"���������� ������� ������ ����� ����� ��� ������ ��� ��������",
	"���������  ������� ������������ ��� ������ ��� ��������",
	"�������������� �������� ������ � ����������� ����� �/��� ��� ��������������",
	"���������  ���������� ������",
	"����������� ����",
    "�������� �������� ���������� ������ ��� ��������",
	"���������� �����������, �����, �����, ��� �������� ������",
	"��������� ���� �������� � ���������� ����� ������",
	"�������� �������� ������ ����� ����������",
	"����������  ������ � ��������� ������, ������������",
	"���������� ������� ���������� ����, �����������",
	"����������  ������ � ���� ��������������",
	"�������� � �������� ������ ��� ����������",
	"���������� ��� ������ �������� � ������� �/��� �� �����",
	"���������� �������� (�����) ��� ������ ������������ ���������� �������",
	"���������� ��������� ���� ������, ������ �������������",
	"����������� ����������� ������ � ���� � ������� ��������",
	"�������������� �� ����� ������ ���������� ������������"
	};
int UR2arr_2[19] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
int UR2length_2 = sizeof(arr2) / sizeof(arr2[0]);
    shuffleArray(UR2arr_2, UR2length_2);
	
std::vector<DraggableText> UR2draggableTexts_2;

	for(int i = 0 ; i < 15; i++){
UR2draggableTexts_2.emplace_back(UR2hehe_2[UR2arr_2[i]], font, 14, sf::Color::Black, sf::Vector2f(680, 60 + (30 * i)));
		
	}

//------------------------------------------------------------------------------ ������������ ��� ��� 3

String haha6[4] = {
	"��������� ���� \n���������� ������������.",
	"����������� ������� ���� \n�������� �� ���������� ����.",
	"������������ ����, \n��������������,��������� \n�������� � ������ ���������� \n���������� ������.",
	"������������ ��������� \n���� ����� ������.",
	};
int UR2heheOt_3[16]={1,1,0,2,2,2,0,0,3,3,3,0,3,0,4,0};
	 String UR2hehe_3[16] = {
	"��������� ���� ������ �������",
	"�������������� �� ����� ���� ���������� ������������",
	"����������� ����������� ������ � ���� � ������� ��������",
	"���������� ������ ����� ���  ������� ������������ ������",
	"���������� ������� ���������� ������  ����� � ������",
	"����������� ������������������ ����� �������� ",
    "������������ ������ ����� �� �������",
	"������� ������ ������ �� �����",
	"���������� ���� ���� ��� ���������� ����������� �������",
	"�������������� ��� ������������� ����� ��� ���������� �������",
	"��������� ��������� ����� ����� ������",
	"�������� ����� ������ ��������� ����� ������",
	"��������� ���������� ������",
	"����� ������������ ���� � ������ ��� ���������� �������",
	"�������������� ��������� �������",
	"������������ ���� ������ � ������� �������������"
	};
int UR2arr_3[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
int UR2length_3 = sizeof(UR2arr_3) / sizeof(UR2arr_3[0]);
    shuffleArray(UR2arr_3, UR2length_3);
	
std::vector<DraggableText> UR2draggableTexts_3;

	for(int i = 0 ; i < 15; i++){
UR2draggableTexts_3.emplace_back(UR2hehe_3[UR2arr_3[i]], font, 14, sf::Color::Black, sf::Vector2f(680, 60 + (30 * i)));
		
	}
//---------------------------------------------------------------------------------------------------------------������������ ���2 ��� 1

vector<DraggableTextNoColor> draggableTextNoColorUR2_1;
for(int i = 0 ; i < 15; i++){
draggableTextNoColorUR2_1.emplace_back(UR2hehe_1[UR2arr_1[i]], font, 14, sf::Color::Black, sf::Vector2f(680, 60 + (30 * i)));	
	}
	
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------������������ ���2 ��� 2

vector<DraggableTextNoColor> draggableTextNoColorUR2_2;
for(int i = 0 ; i < 15; i++){
draggableTextNoColorUR2_2.emplace_back(UR2hehe_2[UR2arr_2[i]], font, 14, sf::Color::Black, sf::Vector2f(680, 60 + (30 * i)));	
	}
	
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------������������ ���2 ��� 3

vector<DraggableTextNoColor> draggableTextNoColorUR2_3;
for(int i = 0 ; i < 15; i++){
draggableTextNoColorUR2_3.emplace_back(UR2hehe_3[UR2arr_3[i]], font, 14, sf::Color::Black, sf::Vector2f(680, 60 + (30 * i)));	
	}
	
//---------------------------------------------------------------------------------------------------------
 
       while (window.isOpen()) {
    	time ++ ;
    	if(time > 60 ){
    	stran = true;
		time = 0;	
		}
//    	stp = DraggableTextNoColor::getGreenTextCount();
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                exit(0);
            }
            if (Keyboard::isKeyPressed(Keyboard::Q)) {
                if(ak[0] == true || ak[1] == true || ak[2] == true){ 
                    for(int i = 0; i < 3; i++){ 
                        ak[i] = false;
                    }
                    vhod = true;
                }
            }
            if(pud.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && vhod == true){
                vhod = false;
                ak[0] = true;
                if(ak[0] == true){
                	str[0] = true;
				}
            }
            if(kud.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && vhod == true){
                vhod = false;
                ak[1] = true;
                if(ak[1] == true){
                	dtr[0] = true;
				}
            }
            if(rud.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && vhod == true ){
                vhod = false;
                ak[2] = true;
                if(ak[2] == true){
                	btr[0] = true;
				}
            }
    
           	if(tt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && str[0] == true && stran == true){
         			str[0] = false;
         			str[1] = true;
         			stran = false;
			 }
			 if(tt1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) &&str[1] == true && stran == true){
					str[1] = false;
         			str[2] = true;
         			stran = false;
	
			 }
			 if(t.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) &&str[2] == true && stran == true){
				 	str[2] = false;
         			str[3] = true;
         			stran = false;
         			clock = sf::Clock();
         			countdown = (60 * 25);
			 }
			 if(t1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && str[3] == true && stran == true){
				 	str[3] = false;
         			str[4] = true;
         			stran = false;
         			clock = sf::Clock();
         			countdown = (60 * 25);
					 stp = 	DraggableTextNoColor::greenTextCount ;
         			scoreUR1 = scoreUR1 + stp;
         			cout << stp << endl;
					 DraggableTextNoColor::greenTextCount = 0;
			 }
			 if(t1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && str[4] == true && stran == true){
				 	str[4] = false;
         			str[5] = true;
         			stran = false;
         			clock = sf::Clock();
         			countdown = (60 * 25);
         			stp = DraggableTextNoColor::greenTextCount ;
         			scoreUR1 = scoreUR1 + stp;
					
         			cout << stp << endl;
					 DraggableTextNoColor::greenTextCount = 0;
			 }
			 if(t1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && str[5] == true && stran == true){
         			str[5] = false;
         			ak[0] = false;
         			ak[1] = true;
         			dtr[0] = true;
         			stran = false;
         			Buranya[0] = true;
         			clock = sf::Clock();
         			countdown = (60 * 25);
					stp = 	DraggableTextNoColor::greenTextCount ;
         			scoreUR1 = scoreUR1 + stp;
         			cout << stp << endl;
					DraggableTextNoColor::greenTextCount = 0;
			 }
			 if(nz.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && stran == true  && str[0] == true ){
         			ak[0] = false;
         			vhod = true;
         			stran = false;
			 }
			 if(nz1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && str[1] == true && stran == true){
         			str[1] = false;
         			str[0] = true;
         			stran = false;
			 }
			 if(nz2.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && str[2] == true && stran == true){
         			str[2] = false;
         			str[1] = true;
         			stran = false;
			 }
			 if(nz.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && stran == true && str[3] == true ){
         			str[3] = false;
         			str[2] = true;
         			stran = false;
			 }
			 if(nz.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && stran == true && str[4] == true ){
         			str[4] = false;
         			str[3] = true;
         			stran = false;
			 }
			 if(nz.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && stran == true && str[5] == true ){
         			str[5] = false;
         			str[4] = true;
         			stran = false;
			 }
			 //------------------------------------------------------------ �������������� 
			 	if(tt1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && dtr[0] == true && stran == true){
						dtr[0] = false;
						dtr[1] = true; 
						stran = false;
			 }
			 	if(nz.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && stran == true && dtr[0] == true ){
         			ak[1] = false;
         			vhod = true;
         			dtr[0] = false;
         			stran = false;
			 }
			 	if(tt1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && dtr[1] == true && stran == true){
					dtr[1] = false;
					dtr[2] = true; 
					stran = false;
					clock = sf::Clock();
         			countdown = (60 * 25);
			 }
			 	if(nz.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && stran == true && dtr[1] == true ){
         			dtr[1] = false;
         			dtr[0] = true;
         			stran = false;
			 }
			 if(tt1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && dtr[2] == true && stran == true){
					dtr[2] = false;
					dtr[3] = true; 
					stran = false;
					stp = 	DraggableTextNoColor::greenTextCount ;
					scoreUR2 = scoreUR2 + stp;
					DraggableTextNoColor::greenTextCount = 0;
					clock = sf::Clock();
         			countdown = (60 * 25);
			 }
			 	if(nz.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && stran == true && dtr[2] == true ){
         			dtr[2] = false;
         			dtr[1] = true;
         			stran = false;
			 }
			 
			 			 if(tt1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && dtr[3] == true && stran == true){
					dtr[3] = false;
					btr[0] = true;
					ak[1] = false;
					ak[2] = true;
					Buranya[1] = true; 
					stran = false;
					stp = 	DraggableTextNoColor::greenTextCount ;
					scoreUR2 = scoreUR2 + stp;
         			cout << stp << endl;
					DraggableTextNoColor::greenTextCount = 0;
					

			 }
			 //-------------------------------------------------------------------------------------������������
			 
			 if(tt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && btr[0] == true && stran == true){
         			btr[0] = false;
         			btr[1] = true;
         			stran = false;

			 }
			 if(nz.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && stran == true && btr[0] == true ){
         			btr[0] = false;
         			ak[2] = false;
         			vhod = true;
         			stran = false;
			 }
			 if(tt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && btr[1] == true && stran == true){
         			btr[1] = false;
         			btr[2] = true;
         			stran = false;

			 }
			 if(nz.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && stran == true && btr[1] == true ){
         			btr[1] = false;
         			btr[0] = true;
         			stran = false;
			 }
			 if(tt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && btr[2] == true && stran == true){
         			btr[2] = false;
         			btr[3] = true;
         			stran = false;
         			clock = sf::Clock();
         			countdown = (60 * 25);
			 }
			 if(nz.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && stran == true && btr[2] == true ){
         			btr[2] = false;
         			btr[1] = true;
         			stran = false;
			 }
			 
			 
			 if(tt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && btr[3] == true && stran == true){
					btr[3] = false;
					btr[4] = true; 
					stran = false;
					stp = 	DraggableTextNoColor::greenTextCount ;
					scoreUR3 = scoreUR3 + stp;
					DraggableTextNoColor::greenTextCount = 0;
					clock = sf::Clock();
         			countdown = (60 * 25);
			 }
			 if(nz.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && stran == true && btr[3] == true ){
         			btr[3] = false;
         			btr[2] = true;
         			stran = false;
			 }
			 if(tt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && btr[4] == true && stran == true){
					btr[4] = false;
					btr[5] = true; 
					stran = false;
					stp = 	DraggableTextNoColor::greenTextCount ;
					scoreUR3 = scoreUR3 + stp;
					DraggableTextNoColor::greenTextCount = 0;
					clock = sf::Clock();
         			countdown = (60 * 25);
			 }
			 if(nz.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && stran == true && btr[4] == true ){
         			btr[4] = false;
         			btr[3] = true;
         			stran = false;
			 }
			 
			 if(tt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && btr[5] == true && stran == true){
         			vhod = true;
                    ak[2] = false;
         			btr[5] = false;
         			stran = false;
					stp = 	DraggableTextNoColor::greenTextCount ;
					scoreUR3 = scoreUR3 + stp;
					DraggableTextNoColor::greenTextCount = 0;
					clock = sf::Clock();
         			countdown = (60 * 25);
         			oknoo = true;
			 }
			 if(nz.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && stran == true && btr[5] == true ){
         			btr[5] = false;
         			btr[4] = true;
         			stran = false;
			 }
//________________________________________________________________________________________________________________     	
			 
			 if(str[0] == true){
			 	
			            for (auto& text : draggableTexts) {
                text.handleEvent(event, window);
                if(heheOt[arr[f]] != 0){
   
					 if(heheOt[arr[f]] == 1){
					 
				 text.setColorChangeArea(sf::FloatRect(290, 80, 350,160));		
				
				 } 
				 			  if(heheOt[arr[f]] == 2){
				 text.setColorChangeArea(sf::FloatRect(290, 240, 350,130));
				
				 }
			  if(heheOt[arr[f]] == 3){
				 text.setColorChangeArea(sf::FloatRect(290, 370, 350,130));
				 	
				 }
				 			  if(heheOt[arr[f]] == 4){
				 text.setColorChangeArea(sf::FloatRect(290, 500, 350,130));	
				  	
				 }  
				}	
           f++;
    }
			f = 0; 	
			 	
			 }
		 
		  if(str[1] == true){
		 
        for (auto& text : draggableTexts1) {
                text.handleEvent(event, window);
				if(heheOt1[arr1[f]] != 0){
				 if(heheOt1[arr1[f]] == 1){
				 text.setColorChangeArea(sf::FloatRect(290, 80, 350,160));	
				 
				 } 
				 			  if(heheOt1[arr1[f]] == 2){
				 text.setColorChangeArea(sf::FloatRect(290, 240, 350,130));	
				 
				 }
			  if(heheOt1[arr1[f]] == 3){
				 text.setColorChangeArea(sf::FloatRect(290, 370, 350,130));	
				 
				 }
				 			  if(heheOt1[arr1[f]] == 4){
				 text.setColorChangeArea(sf::FloatRect(290, 500, 350,130));	
				  
				 }
				     
				}
           f++;
            }
			f = 0;	
			
		}
		if(str[2] == true){
		 
        for (auto& text : draggableTexts2) {
                text.handleEvent(event, window);
				if(heheOt2[arr2[f]] != 0){
				 if(heheOt2[arr2[f]] == 1){
				 text.setColorChangeArea(sf::FloatRect(290, 80, 350,160));
					
				 } 
				 			  if(heheOt2[arr2[f]] == 2){
				 text.setColorChangeArea(sf::FloatRect(290, 240, 350,130));	
				  
				 }
			  if(heheOt2[arr2[f]] == 3){
				 text.setColorChangeArea(sf::FloatRect(290, 370, 350,130));	
				
				 }
				 			  if(heheOt2[arr2[f]] == 4){
				 text.setColorChangeArea(sf::FloatRect(290, 500, 350,130));
					
				 }
				 if(heheOt2[arr2[f]] == 5){
				 text.setColorChangeArea(sf::FloatRect(290, 630, 350,130));	
				 
				 }      
				}
           f++;
            }
			f = 0;	
			
		}

			 if(str[3] == true){
			 	
			            for (auto& text : draggableTextNoColor) {
                text.handleEvent(event, window);
                if(heheOt[arr[f]] != 0){
   
					 if(heheOt[arr[f]] == 1){
					 
				 text.setColorChangeArea(sf::FloatRect(290, 80, 350,160));		
				
				 } 
				 			  if(heheOt[arr[f]] == 2){
				 text.setColorChangeArea(sf::FloatRect(290, 240, 350,130));
				
				 }
			  if(heheOt[arr[f]] == 3){
				 text.setColorChangeArea(sf::FloatRect(290, 370, 350,130));
				 	
				 }
				 			  if(heheOt[arr[f]] == 4){
				 text.setColorChangeArea(sf::FloatRect(290, 500, 350,130));	
				  	
				 }  
				}	
           f++;
    }
			f = 0; 	
			 	
			 }
			 if(str[4] == true){
		 
       for (auto& text : draggableTextNoColor1) {
                text.handleEvent(event, window);
				if(heheOt1[arr1[f]] != 0){
				 if(heheOt1[arr1[f]] == 1){
				 text.setColorChangeArea(sf::FloatRect(290, 80, 350,160));
					
				 } 
				 			  if(heheOt1[arr1[f]] == 2){
				 text.setColorChangeArea(sf::FloatRect(290, 240, 350,130));	
				  
				 }
			  if(heheOt1[arr1[f]] == 3){
				 text.setColorChangeArea(sf::FloatRect(290, 370, 350,130));	
				
				 }
				 			  if(heheOt1[arr1[f]] == 4){
				 text.setColorChangeArea(sf::FloatRect(290, 500, 350,130));
					
				 }
			     
				}
           f++;
            }
			f = 0;	
			
		}
			if(str[5] == true){
		 
        for (auto& text : draggableTextNoColor2) {
                text.handleEvent(event, window);
				if(heheOt2[arr2[f]] != 0){
				 if(heheOt2[arr2[f]] == 1){
				 text.setColorChangeArea(sf::FloatRect(290, 80, 350,160));
					
				 } 
				 			  if(heheOt2[arr2[f]] == 2){
				 text.setColorChangeArea(sf::FloatRect(290, 240, 350,130));	
				  
				 }
			  if(heheOt2[arr2[f]] == 3){
				 text.setColorChangeArea(sf::FloatRect(290, 370, 350,130));	
				
				 }
				 			  if(heheOt2[arr2[f]] == 4){
				 text.setColorChangeArea(sf::FloatRect(290, 500, 350,130));
					
				 }
				 if(heheOt2[arr2[f]] == 5){
				 text.setColorChangeArea(sf::FloatRect(290, 630, 350,130));	
				 
				 }      
				}
           f++;
            }
			f = 0;	
			
		}
		
		//------------------------------------�������������� �������������� ������
		
					if(dtr[0] == true){
		 
        for (auto& text : UR2draggableTexts) {
                text.handleEvent(event, window);
				if(UR2heheOt[UR2arr[f]] != 0){
				 if(UR2heheOt[UR2arr[f]] == 1){
				 text.setColorChangeArea(sf::FloatRect(290, 80, 350,160));	
				 
				 } 
				 			  if(UR2heheOt[UR2arr[f]] == 2){
				 text.setColorChangeArea(sf::FloatRect(290, 240, 350,130));	
				 
				 }
			  if(UR2heheOt[UR2arr[f]] == 3){
				 text.setColorChangeArea(sf::FloatRect(290, 370, 350,130));	
				 
				 }
				 			  if(UR2heheOt[UR2arr[f]] == 4){
				 text.setColorChangeArea(sf::FloatRect(290, 500, 350,130));	
				  
				 }
				     
				}
           f++;
            }
			f = 0;	
			
		}
		
							if(dtr[1] == true){
		 
        for (auto& text : UR2draggableTexts1) {
                text.handleEvent(event, window);
				if(UR2heheOt1[UR2arr1[f]] != 0){
				 if(UR2heheOt1[UR2arr1[f]] == 1){
				 text.setColorChangeArea(sf::FloatRect(290, 80, 350,160));	
				 
				 } 
				 			  if(UR2heheOt1[UR2arr1[f]] == 2){
				 text.setColorChangeArea(sf::FloatRect(290, 240, 350,130));	
				 
				 }
			  if(UR2heheOt1[UR2arr1[f]] == 3){
				 text.setColorChangeArea(sf::FloatRect(290, 370, 350,130));	
				 
				 }
				 			  if(UR2heheOt1[UR2arr1[f]] == 4){
				 text.setColorChangeArea(sf::FloatRect(290, 500, 350,130));	
				  
				 }
				     
				}
           f++;
            }
			f = 0;	
			
		}
			if(dtr[2] == true){
		 
        for (auto& text : draggableTextNoColorUR2) {
                text.handleEvent(event, window);
				if(UR2heheOt[UR2arr[f]] != 0){
				 if(UR2heheOt[UR2arr[f]] == 1){
				 text.setColorChangeArea(sf::FloatRect(290, 80, 350,160));	
				 
				 } 
				 			  if(UR2heheOt[UR2arr[f]] == 2){
				 text.setColorChangeArea(sf::FloatRect(290, 240, 350,130));	
				 
				 }
			  if(UR2heheOt[UR2arr[f]] == 3){
				 text.setColorChangeArea(sf::FloatRect(290, 370, 350,130));	
				 
				 }
				 			  if(UR2heheOt[UR2arr[f]] == 4){
				 text.setColorChangeArea(sf::FloatRect(290, 500, 350,130));	
				  
				 }
				     
				}
           f++;
            }
			f = 0;	
			
		}
		if(dtr[3] == true){
		 
        for (auto& text : draggableTextNoColor1UR2) {
                text.handleEvent(event, window);
				if(UR2heheOt1[UR2arr1[f]] != 0){
				 if(UR2heheOt1[UR2arr1[f]] == 1){
				 text.setColorChangeArea(sf::FloatRect(290, 80, 350,160));	
				 
				 } 
				 			  if(UR2heheOt1[UR2arr1[f]] == 2){
				 text.setColorChangeArea(sf::FloatRect(290, 240, 350,130));	
				 
				 }
			  if(UR2heheOt1[UR2arr1[f]] == 3){
				 text.setColorChangeArea(sf::FloatRect(290, 370, 350,130));	
				 
				 }
				 			  if(UR2heheOt1[UR2arr1[f]] == 4){
				 text.setColorChangeArea(sf::FloatRect(290, 500, 350,130));	
				  
				 }
				     
				}
           f++;
            }
			f = 0;	
			
		}
//----------------------------------------------------------------------------------------------------------------------------------------------������������ ��������������
		if(btr[0] == true){
		 
        for (auto& text : UR2draggableTexts_1) {
                text.handleEvent(event, window);
				if(UR2heheOt_1[f] != 0){
				 if(UR2heheOt_1[f] == 1){
				 text.setColorChangeArea(sf::FloatRect(290, 80, 350,160));	
				 
				 } 
				 			  if(UR2heheOt_1[f] == 2){
				 text.setColorChangeArea(sf::FloatRect(290, 240, 350,130));	
				 
				 }
			  if(UR2heheOt_1[f] == 3){
				 text.setColorChangeArea(sf::FloatRect(290, 370, 350,130));	
				 
				 }
				 			  if(UR2heheOt_1[f] == 4){
				 text.setColorChangeArea(sf::FloatRect(290, 500, 350,130));	
				  
				 }
				 if(UR2heheOt_1[f] == 5){
				 text.setColorChangeArea(sf::FloatRect(290, 630, 350,130));	
				 
				 }
				     
				}
           f++;
            }
			f = 0;	
			
		}
		if(btr[1] == true){
		 
        for (auto& text : UR2draggableTexts_2) {
                text.handleEvent(event, window);
				if(UR2heheOt_2[UR2arr_2[f]] != 0){
				 if(UR2heheOt_2[UR2arr_2[f]] == 1){
				 text.setColorChangeArea(sf::FloatRect(290, 80, 350,160));	
				 
				 } 
				 			  if(UR2heheOt_2[UR2arr_2[f]] == 2){
				 text.setColorChangeArea(sf::FloatRect(290, 240, 350,130));	
				 
				 }
			  if(UR2heheOt_2[UR2arr_2[f]] == 3){
				 text.setColorChangeArea(sf::FloatRect(290, 370, 350,130));	
				 
				 }
				 			  if(UR2heheOt_2[UR2arr_2[f]] == 4){
				 text.setColorChangeArea(sf::FloatRect(290, 500, 350,130));	
				  
				 }
				 if(UR2heheOt_2[UR2arr_2[f]] == 5){
				 text.setColorChangeArea(sf::FloatRect(290, 630, 350,130));	
				 
				 }
				    
				}
           f++;
            }
			f = 0;	
			
		}
		if(btr[2] == true){
		 
        for (auto& text : UR2draggableTexts_3) {
                text.handleEvent(event, window);
				if(UR2heheOt_3[UR2arr_3[f]] != 0){
				 if(UR2heheOt_3[UR2arr_3[f]] == 1){
				 text.setColorChangeArea(sf::FloatRect(290, 80, 350,160));	
				 
				 } 
				 			  if(UR2heheOt_3[UR2arr_3[f]] == 2){
				 text.setColorChangeArea(sf::FloatRect(290, 240, 350,130));	
				 
				 }
			  if(UR2heheOt_3[UR2arr_3[f]] == 3){
				 text.setColorChangeArea(sf::FloatRect(290, 370, 350,130));	
				 
				 }
				 			  if(UR2heheOt_3[UR2arr_3[f]] == 4){
				 text.setColorChangeArea(sf::FloatRect(290, 500, 350,130));	
				  
				 }
				    
				}
           f++;
            }
			f = 0;	
			
		}
			if(btr[3] == true){
		 
        for (auto& text : draggableTextNoColorUR2_1) {
                text.handleEvent(event, window);
				if(UR2heheOt_1[UR2arr_1[f]] != 0){
				 if(UR2heheOt_1[UR2arr_1[f]] == 1){
				 text.setColorChangeArea(sf::FloatRect(290, 80, 350,160));	
				 
				 } 
				 			  if(UR2heheOt_1[UR2arr_1[f]] == 2){
				 text.setColorChangeArea(sf::FloatRect(290, 240, 350,130));	
				 
				 }
			  if(UR2heheOt_1[UR2arr_1[f]] == 3){
				 text.setColorChangeArea(sf::FloatRect(290, 370, 350,130));	
				 
				 }
				 			  if(UR2heheOt_1[UR2arr_1[f]] == 4){
				 text.setColorChangeArea(sf::FloatRect(290, 500, 350,130));	
				  
				 }
				 if(UR2heheOt_1[UR2arr_1[f]] == 5){
				 text.setColorChangeArea(sf::FloatRect(290, 630, 350,130));	
				 
				 }
				     
				}
           f++;
            }
			f = 0;	
			
		}
	
		 ochkoBash = 0;
        }
        		if(btr[4] == true){
		 
        for (auto& text : draggableTextNoColorUR2_2) {
                text.handleEvent(event, window);
				if(UR2heheOt_2[UR2arr_2[f]] != 0){
				 if(UR2heheOt_2[UR2arr_2[f]] == 1){
				 text.setColorChangeArea(sf::FloatRect(290, 80, 350,160));	
				 
				 } 
				 			  if(UR2heheOt_2[UR2arr_2[f]] == 2){
				 text.setColorChangeArea(sf::FloatRect(290, 240, 350,130));	
				 
				 }
			  if(UR2heheOt_2[UR2arr_2[f]] == 3){
				 text.setColorChangeArea(sf::FloatRect(290, 370, 350,130));	
				 
				 }
				 			  if(UR2heheOt_2[UR2arr_2[f]] == 4){
				 text.setColorChangeArea(sf::FloatRect(290, 500, 350,130));	
				  
				 }
				 if(UR2heheOt_2[UR2arr_2[f]] == 5){
				 text.setColorChangeArea(sf::FloatRect(290, 630, 350,130));	
				 
				 }
				    
				}
           f++;
            }
			f = 0;	
			
		}
				if(btr[5] == true){
		 
        for (auto& text : draggableTextNoColorUR2_3) {
                text.handleEvent(event, window);
				if(UR2heheOt_3[UR2arr_3[f]] != 0){
				 if(UR2heheOt_3[UR2arr_3[f]] == 1){
				 text.setColorChangeArea(sf::FloatRect(290, 80, 350,160));	
				 
				 } 
				 			  if(UR2heheOt_3[UR2arr_3[f]] == 2){
				 text.setColorChangeArea(sf::FloatRect(290, 240, 350,130));	
				 
				 }
			  if(UR2heheOt_3[UR2arr_3[f]] == 3){
				 text.setColorChangeArea(sf::FloatRect(290, 370, 350,130));	
				 
				 }
				 			  if(UR2heheOt_3[UR2arr_3[f]] == 4){
				 text.setColorChangeArea(sf::FloatRect(290, 500, 350,130));	
				  
				 }
				    
				}
           f++;
            }
			f = 0;	
			
		}
//_____________________________________________________________________________________________________        
        if(vhod){
            window.clear(Color::White);
            window.draw(testik);
            window.draw(pud);
            window.draw(kud);
            window.draw(rud);
        }
        
        if(ak[0]){
		window.clear(Color::White);
        	if(str[0]){
			table.draw(window);
			table1.draw(window);
			table2.draw(window);
			table3.draw(window);
			table4.draw(window);
			table5.draw(window);
			table6.draw(window);
			table7.draw(window);
			table8.draw(window);
			table9.draw(window);  
			window.draw(shag);
			poz.setString("�������������� ���");    
			window.draw(poz);
			window.draw(vud);
			window.draw(musor);
			window.draw(text);
			window.draw(textt);
		for (int i = 0; i < 5; i++){
		prikol.setString(haha[i]);
		prikol.setPosition(45,90+(160*i));
		if(i == 3){
		prikol.setPosition(45,90+(140*i));	
		}
		window.draw(prikol);
		}
        for (auto& text : draggableTexts) {
            text.draw(window);
        }
        window.draw(tt);
        if(str[0] == true){
		nz.setPosition(800,10);	
		window.draw(nz);
		}
		}else if(str[1]){
			window.clear(Color::White);
			table.draw(window);
			table1.draw(window);
			table2.draw(window);
			table3.draw(window);
			table4.draw(window);
			table5.draw(window);
			table6.draw(window);
			table7.draw(window);
			table8.draw(window);
			table9.draw(window);
			window.draw(shag1);    
			window.draw(poz);
			window.draw(vud);
			window.draw(nz1);
			window.draw(tt1);
			window.draw(text);
			window.draw(musor);
			window.draw(textt);
			if(str[1] == true){
			nz.setPosition(720,10);	
			window.draw(nz);
			}
		if(str[1] == true){
		prikol.setString("");
		for (int i = 0; i < 5; i++){
		prikol.setString(haha1[i]);
		prikol.setPosition(45,90+(160*i));
		if(i == 3){
		prikol.setPosition(45,90+(140*i));	
		}
		window.draw(prikol);
		} 
		}
		for (auto& text : draggableTexts1) {
            text.draw(window);
        }	
		}else if(str[2]){
			window.clear(Color::White);
			table.draw(window);
			table1.draw(window);
			table2.draw(window);
			table3.draw(window);
			table4.draw(window);
			table5.draw(window);
			table6.draw(window);
			table7.draw(window);
			table8.draw(window);
			table9.draw(window);
			table10.draw(window);
			table11.draw(window);
			window.draw(shag2);    
			window.draw(poz);
			window.draw(vud);
			window.draw(nz2);
			window.draw(text);
			window.draw(musor);
			window.draw(t);
			window.draw(textt1);
			if(str[2] == true){
			nz.setPosition(800,10);	
			window.draw(nz);
			}
			if(str[2] == true){
		prikol.setString("");
		for (int i = 0; i < 6; i++){
		prikol.setString(haha2[i]);
		prikol.setPosition(45,90+(160*i));
		if(i > 1){
		prikol.setPosition(45,90+(140*i));	
		}
		window.draw(prikol);
		} 
		}
		for (auto& text : draggableTexts2) {
            text.draw(window);
        }
		}else if(str[3] == true){
			window.clear(Color::White);
			table.draw(window);
			table1.draw(window);
			table2.draw(window);
			table3.draw(window);
			table4.draw(window);
			table5.draw(window);
			table6.draw(window);
			table7.draw(window);
			table8.draw(window);
			table9.draw(window);
			window.draw(poz);
			window.draw(vud);
			window.draw(t1);
			window.draw(nz);
			if(str[3] == true){
				shag1.setString("������� 2.��� 2.�������� 1");
			}
			window.draw(shag1);  
			for (int i = 0; i < 5; i++){
		prikol.setString(haha[i]);
		prikol.setPosition(45,90+(160*i));
		if(i == 3){
		prikol.setPosition(45,90+(140*i));	
		}
		window.draw(prikol);
		}
        for (auto& text : draggableTextNoColor) {
            text.draw(window);
        }
        startTimer(window,event,font,clock,countdown,timerText);
		}else if(str[4] == true){
			window.clear(Color::White);
			table.draw(window);
			table1.draw(window);
			table2.draw(window);
			table3.draw(window);
			table4.draw(window);
			table5.draw(window);
			table6.draw(window);
			table7.draw(window);
			table8.draw(window);
			table9.draw(window);
			window.draw(poz);
			window.draw(vud);
			window.draw(musor);
			window.draw(t2);
			window.draw(nz);
			if(str[4] == true){
				shag1.setString("������� 2.��� 2.�������� 2");
			}
			window.draw(shag1);    
		if(str[4] == true){
		prikol.setString("");
		for (int i = 0; i < 5; i++){
		prikol.setString(haha1[i]);
		prikol.setPosition(45,90+(160*i));
		if(i == 3){
		prikol.setPosition(45,90+(140*i));	
		}
		window.draw(prikol);
		} 
		}
		for (auto& text : draggableTextNoColor1) {
            text.draw(window);
        }
		startTimer(window,event,font,clock,countdown,timerText);	
		}else if(str[5] == true){
			window.clear(Color::White);
			table.draw(window);
			table1.draw(window);
			table2.draw(window);
			table3.draw(window);
			table4.draw(window);
			table5.draw(window);
			table6.draw(window);
			table7.draw(window);
			table8.draw(window);
			table9.draw(window);
			table10.draw(window);
			table11.draw(window);
			window.draw(poz);
			window.draw(vud);
			window.draw(musor);
			window.draw(nz);
			window.draw(t1);
			if(str[5] == true){
				shag1.setString("������� 2.��� 2.�������� 3");
			}
			window.draw(shag1);
			if(str[5] == true){
		prikol.setString("");
		for (int i = 0; i < 6; i++){
		prikol.setString(haha2[i]);
		prikol.setPosition(45,90+(160*i));
		if(i > 1){
		prikol.setPosition(45,90+(140*i));	
		}
		window.draw(prikol);
		} 
		}
		for (auto& text : draggableTextNoColor2) {
            text.draw(window);
        }
        startTimer(window,event,font,clock,countdown,timerText);
		}
			
     //------------------------ ��������������    
        }
        if(ak[1]){
            window.clear(Color::White);
         	if(dtr[0] == true){
         	table.draw(window);
			table1.draw(window);
			table2.draw(window);
			table3.draw(window);
			table4.draw(window);
			table5.draw(window);
			table6.draw(window);
			table7.draw(window);
			table8.draw(window);
			table9.draw(window);
			window.draw(shag1);
			poz.setString("��������������� ���");
			window.draw(poz);
			window.draw(vud);
			window.draw(musor);
			window.draw(text);
			window.draw(textt);
			window.draw(tt);
			window.draw(nz);
			shag1.setString("������� 2.��� 1.�������� 1");
			prikol.setString("");
		for (int i = 0; i < 5; i++){
		prikol.setString(haha3[i]);
		prikol.setPosition(45,90+(160*i));
		if(i > 1){
		prikol.setPosition(45,90+(140*i));	
		}
		window.draw(prikol);
		} 
		for (auto& text : UR2draggableTexts) {
            text.draw(window);
        }
			 }
			 
			 //----------------------------
			 
			if(dtr[1] == true){
			table.draw(window);
			table1.draw(window);
			table2.draw(window);
			table3.draw(window);
			table4.draw(window);
			table5.draw(window);
			table6.draw(window);
			table7.draw(window);
			table8.draw(window);
			table9.draw(window);
			window.draw(shag1);
			window.draw(poz);
			window.draw(vud);
			window.draw(musor);
			window.draw(text);
			window.draw(textt);
			window.draw(tt);
			window.draw(nz);	
			shag1.setString("������� 2.��� 1.�������� 2");
			prikol.setString("");
		for (int i = 0; i < 5; i++){
		prikol.setString(UR2haha1[i]);
		prikol.setPosition(45,90+(160*i));
		if(i > 1){
		prikol.setPosition(45,90+(140*i));	
		}
		window.draw(prikol);
		} 
		for (auto& text : UR2draggableTexts1) {
            text.draw(window);
        }
			 	}
			 	
			if(dtr[2] == true){
         	table.draw(window);
			table1.draw(window);
			table2.draw(window);
			table3.draw(window);
			table4.draw(window);
			table5.draw(window);
			table6.draw(window);
			table7.draw(window);
			table8.draw(window);
			table9.draw(window);
			window.draw(shag1);
			window.draw(poz);
			window.draw(vud);
			window.draw(musor);
			window.draw(text);
			window.draw(textt);
			window.draw(tt);
			window.draw(nz);
			shag1.setString("������� 2.��� 2.�������� 1");
			prikol.setString("");
		for (int i = 0; i < 5; i++){
		prikol.setString(haha3[i]);
		prikol.setPosition(45,90+(160*i));
		if(i > 1){
		prikol.setPosition(45,90+(140*i));	
		}
		window.draw(prikol);
		} 
		for (auto& text : draggableTextNoColorUR2) {
            text.draw(window);
        }
		startTimer(window,event,font,clock,countdown,timerText);
			 }
			if(dtr[3] == true){
			table.draw(window);
			table1.draw(window);
			table2.draw(window);
			table3.draw(window);
			table4.draw(window);
			table5.draw(window);
			table6.draw(window);
			table7.draw(window);
			table8.draw(window);
			table9.draw(window);
			window.draw(shag1);
			window.draw(poz);
			window.draw(vud);
			window.draw(musor);
			window.draw(tt1);
			shag1.setString("������� 2.��� 2.�������� 2");
			prikol.setString("");
		for (int i = 0; i < 5; i++){
		prikol.setString(UR2haha1[i]);
		prikol.setPosition(45,90+(160*i));
		if(i > 1){
		prikol.setPosition(45,90+(140*i));	
		}
		window.draw(prikol);
		} 
		for (auto& text : draggableTextNoColor1UR2) {
            text.draw(window);
        }	
		startTimer(window,event,font,clock,countdown,timerText);	 	 
			}
        }
        
        if(ak[2]){
            window.clear(Color::White);
			if(btr[0] == true){
			table.draw(window);
			table1.draw(window);
			table2.draw(window);
			table3.draw(window);
			table4.draw(window);
			table5.draw(window);
			table6.draw(window);
			table7.draw(window);
			table8.draw(window);
			table9.draw(window);
			table10.draw(window);
			table11.draw(window);	
			window.draw(shag1);
			poz.setString("������������ ���");
			window.draw(poz);
			window.draw(vud);
			window.draw(musor);
			window.draw(text);
			window.draw(textt);
			window.draw(tt);
			window.draw(nz);
			shag1.setString("������� 2.��� 1.�������� 1");
			prikol.setString("");
		for (int i = 0; i < 5; i++){
		prikol.setString(haha4[i]);
		prikol.setPosition(45,90+(160*i));
		if(i > 1){
		prikol.setPosition(45,90+(140*i));	
		}
		window.draw(prikol);
		} 
		for (auto& text : UR2draggableTexts_1) {
            text.draw(window);
        } 
			}
		
		
			if(btr[1] == true){
			table.draw(window);
			table1.draw(window);
			table2.draw(window);
			table3.draw(window);
			table4.draw(window);
			table5.draw(window);
			table6.draw(window);
			table7.draw(window);
			table8.draw(window);
			table9.draw(window);
			table10.draw(window);
			table11.draw(window);	
			window.draw(shag1);
			window.draw(poz);
			window.draw(vud);
			window.draw(musor);
			window.draw(text);
			window.draw(textt);
			window.draw(tt);
			window.draw(nz);
			shag1.setString("������� 2.��� 1.�������� 2");
			prikol.setString("");
		for (int i = 0; i < 5; i++){
		prikol.setString(haha5[i]);
		prikol.setPosition(45,90+(160*i));
		if(i > 1){
		prikol.setPosition(45,90+(140*i));	
		}
		window.draw(prikol);
		} 
		for (auto& text : UR2draggableTexts_2) {
            text.draw(window);
        } 	
			}
			
				if(btr[2] == true){
			table.draw(window);
			table1.draw(window);
			table2.draw(window);
			table3.draw(window);
			table4.draw(window);
			table5.draw(window);
			table6.draw(window);
			table7.draw(window);
			table8.draw(window);
			table9.draw(window);
			window.draw(shag1);
			window.draw(poz);
			window.draw(vud);
			window.draw(musor);
			window.draw(text);
			window.draw(textt);
			window.draw(tt);
			window.draw(nz);
			shag1.setString("������� 2.��� 1.�������� 3");
			prikol.setString("");
		for (int i = 0; i < 4; i++){
		prikol.setString(haha6[i]);
		prikol.setPosition(45,90+(160*i));
		if(i > 1){
		prikol.setPosition(45,90+(140*i));	
		}
		window.draw(prikol);
		} 
		for (auto& text : UR2draggableTexts_3) {
            text.draw(window);
        } 	
			}
		if(btr[3] == true){
			table.draw(window);
			table1.draw(window);
			table2.draw(window);
			table3.draw(window);
			table4.draw(window);
			table5.draw(window);
			table6.draw(window);
			table7.draw(window);
			table8.draw(window);
			table9.draw(window);
			table10.draw(window);
			table11.draw(window);	
			window.draw(shag1);
			window.draw(poz);
			window.draw(vud);
			window.draw(musor);
			window.draw(text);
			window.draw(textt);
			window.draw(tt);
			window.draw(nz);
			shag1.setString("������� 2.��� 2.�������� 1");
			prikol.setString("");
		for (int i = 0; i < 5; i++){
		prikol.setString(haha4[i]);
		prikol.setPosition(45,90+(160*i));
		if(i > 1){
		prikol.setPosition(45,90+(140*i));	
		}
		window.draw(prikol);
		} 
		for (auto& text : draggableTextNoColorUR2_1) {
            text.draw(window);
        }
		startTimer(window,event,font,clock,countdown,timerText); 
		}
		
				if(btr[4] == true){
			table.draw(window);
			table1.draw(window);
			table2.draw(window);
			table3.draw(window);
			table4.draw(window);
			table5.draw(window);
			table6.draw(window);
			table7.draw(window);
			table8.draw(window);
			table9.draw(window);
			table10.draw(window);
			table11.draw(window);	
			window.draw(shag1);
			window.draw(poz);
			window.draw(vud);
			window.draw(musor);
			window.draw(text);
			window.draw(textt);
			window.draw(tt);
			window.draw(nz);
			shag1.setString("������� 2.��� 2.�������� 2");
			prikol.setString("");
		for (int i = 0; i < 5; i++){
		prikol.setString(haha4[i]);
		prikol.setPosition(45,90+(160*i));
		if(i > 1){
		prikol.setPosition(45,90+(140*i));	
		}
		window.draw(prikol);
		} 
		for (auto& text : draggableTextNoColorUR2_2) {
            text.draw(window);
        }
		startTimer(window,event,font,clock,countdown,timerText); 
		}
		
						if(btr[5] == true){
			table.draw(window);
			table1.draw(window);
			table2.draw(window);
			table3.draw(window);
			table4.draw(window);
			table5.draw(window);
			table6.draw(window);
			table7.draw(window);
			table8.draw(window);
			table9.draw(window);
			table10.draw(window);
			table11.draw(window);	
			window.draw(shag1);
			window.draw(poz);
			window.draw(vud);
			window.draw(musor);
			window.draw(text);
			window.draw(textt);
			textt.setString("���������");
			tt.setScale(1.5,1);
			window.draw(tt);
			window.draw(nz);
			shag1.setString("������� 2.��� 2.�������� 3");
			prikol.setString("");
		for (int i = 0; i < 5; i++){
		prikol.setString(haha4[i]);
		prikol.setPosition(45,90+(160*i));
		if(i > 1){
		prikol.setPosition(45,90+(140*i));	
		}
		window.draw(prikol);
		} 
		for (auto& text : draggableTextNoColorUR2_3) {
            text.draw(window);
        }
		startTimer(window,event,font,clock,countdown,timerText); 
		}	  
        }
		if(btr[5] == false){
			textt.setString("�����");
			tt.setScale(1,1);
		} 
        stringstream ss;
        ss << stp;
        string trusi;
        ss >> trusi;
        Score1.setString("");
		 if(str[4] == true){
		 Score1.setString("������ �� �������� 1: " + trusi + " / 13");
		 }
		 if(str[5]== true){
		 Score1.setString("������ �� �������� 2: " + trusi + " / 9");
		 }  
		if(Buranya[0] == true){
		stringstream ss;
        ss << scoreUR1;
        string trusi2;
        ss >> trusi2;
		 Score1.setString("������ �� �������� 3: " + trusi + " / 11" + "\n���������� ������ �� �������������� ��� : " +trusi2 +" / 33");
		}

		 if(dtr[3]== true){
		 Score1.setString("������ �� �������� 1: " + trusi + " / 10");
		 }  
		if(Buranya[1] == true){
		stringstream ss;
        ss << scoreUR2;
        string trusi2;
        ss >> trusi2;
		 Score1.setString("������ �� �������� 2: " + trusi + " / 9" + "\n���������� ������ �� �������������� ��� : " +trusi2 +" / 19");
		 Score1.setPosition(620, 700);
		}
				 if(btr[4] == true){
		 Score1.setString("������ �� �������� 1: " + trusi + " / 13");
		 }
		 if(btr[5]== true){
		 Score1.setString("������ �� �������� 2: " + trusi + " / 9");
		 }  
		if(Buranya[2] == true){
		stringstream ss;
        ss << scoreUR3;
        string trusi2;
        ss >> trusi2;
		Score1.setString("������ �� �������� 3: " + trusi + " / 6" + "\n���������� ������ �� ������������ ��� : " +trusi2 +" / 28");
		}
		if(vhod == true){
		Score1.setString(" ");
		int all = 0 ;
		all = scoreUR1+scoreUR2+scoreUR3;
        stringstream ss ;
        ss << all;
        string trusi2;
        ss >> trusi2;
		Score1.setString(trusi2);
		}
		Score1.setPosition(650, 700);
        if(oknoo == true){
        	int all = 0 ;
		all = scoreUR1+scoreUR2+scoreUR3;
        stringstream ss ;
        ss << all;
        string trusi2;
        ss >> trusi2;
		okno(window,Score1,font,trusi2);
		window.draw(rerun);
		window.draw(contin);
			}
		window.draw(Score1);	
        window.display();

//      std::cout << "Number of green text objects: " << stp << std::endl;
    }
    
  
}
