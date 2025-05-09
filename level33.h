#include <SFML/Graphics.hpp>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;
using namespace sf;


void shuffle_two_arrays(std::vector<std::string>& arr1, std::vector<std::string>& arr2,std::vector<int>& heh) {
    srand(time(0));
    int h = 0 ;

   for (int i = arr1.size() - 2; i >= 1; --i) {
    int h = rand() % (i + 1); 
    std::swap(arr1[i], arr1[h]);
    std::swap(arr2[i], arr2[h]);
    std::swap(heh[i], heh[h]);
}
}
void shuffleArrays(int arr1[], int size) {
    srand(time(0));

    for (int i = 0; i < size; i += 3) {
        std::random_shuffle(arr1 + i, arr1 + i + 3);

    }
}

void updateTimer(Text& timer, Clock& clock, int& timerSeconds, bool& cenok,bool& pen) {
    if (!cenok && timerSeconds > 0) {
        if (clock.getElapsedTime().asSeconds() >= 1) {
            clock.restart();
            timerSeconds--;
        }
        int minutes = timerSeconds / 60;
        int seconds = timerSeconds % 60;
        timer.setString(std::to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + std::to_string(seconds));
    } else if (timerSeconds == 0) {
        cenok = true;
        pen = true;
    }
}

void klick(View& view,RenderWindow& window,sf::RectangleShape& rectangle, Event& event,Text& texts,std::vector<std::string>& str,int i, int& randomIndex, std::vector<std::string>& str1,Text& otv,bool& dev,int& zighail,std::vector<int>& heh, bool& islam, bool& okno,int& S) {
	
	
	            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window), view);
			sf::Vector2f relativePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window), view);		
	
	
	if (rectangle.getGlobalBounds().contains(mousePos) )
{ 	islam = true;
        texts.setString(str[randomIndex]);
        rectangle.setFillColor(Color::Green);
if((i + 1) == heh[randomIndex]){
dev = true;
okno = true;

}
randomIndex++;
zighail++;
S++;	
//dev2 = true ;
	
                    }else{
rectangle.setFillColor(Color::White);
					}				
}

void handleEvents(RenderWindow& window, View& view, float scrollSpeed, Event& event) {
    if (event.type == Event::MouseWheelScrolled) {
        if (event.mouseWheelScroll.delta > 0) view.move(0, -scrollSpeed);
        else if (event.mouseWheelScroll.delta < 0) view.move(0, scrollSpeed);
    }
}

void render(RenderWindow& window, View& view) {
	   
    window.setView(view);
}

void createSpriteOnClick(RenderWindow& window, Text& text, Sprite& sprite, Vector2f offset, View& view, int otvet, int& ochko, bool& pen, int& an) {
    if (Mouse::isButtonPressed(Mouse::Left)) {
        Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window), view);
        sf::Vector2f relativePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window), view);
        if (text.getGlobalBounds().contains(relativePosition)) {
            sprite.setPosition(text.getPosition() - offset);
            if (otvet == 1) {
                ochko++;
                pen = true;
            } else {
                ochko--;
                pen = false;
            }
            if (ochko == 2) {
                ochko--;
            }
            if (ochko == -1) {
                ochko++;
            }
            an++;
        }
    }
}

void level3(RenderWindow& window,int& levelpoint,View& view){
	window.setFramerateLimit(60);
	setlocale(LC_ALL, "Russian");

	
	view.setCenter(1024/2,768/2);
//	view.setCenter(window.getSize().x/4, window.getSize().y/4);

view.setSize(window.getSize().x - (window.getSize().x/5) ,window.getSize().y - (window.getSize().y/5));	

    window.setView(view);



	bool penis[28];
//////����� ������� ������ ���
//	Texture akranTexture;
//	akranTexture.loadFromFile("vkr.jpg");
//    Sprite akran(akranTexture);
	Texture tests;
	tests.loadFromFile("images/x_Predmeny3.jpg");
    Sprite testik(tests);
    testik.setPosition(0,-20);
    testik.setScale(0.515f,0.4f);
    
    Texture okna;
	okna.loadFromFile("images/pov_ili_idi.jpg");
    Sprite okn(okna);
    okn.setPosition(240,240);
    okn.setScale(0.6f,0.4f);
    
    RectangleShape akno(Vector2f((okn.getGlobalBounds().width * 0.6f)+215, (okn.getGlobalBounds().height * 0.6f)+175));
    akno.setPosition(okn.getPosition());
    akno.setOutlineThickness(5);
    akno.setOutlineColor(Color::Black);
    akno.setFillColor(Color(128, 128, 128));
    
    okn.move(0.f, 25.f);
    
    Texture knopkaV;
	knopkaV.loadFromFile("knopka_pravo3.png");
    Sprite knopV(knopkaV);
    knopV.setPosition(660,430);
    knopV.setScale(0.12f,0.12f);
    
    Texture knopkaP;
	knopkaP.loadFromFile("knopka_povtora.png");
    Sprite knopP(knopkaP);
    knopP.setPosition(580,433);
    knopP.setScale(0.10f,0.10f);
    
    RectangleShape krest(sf::Vector2f(20,20));
    krest.setPosition(758,242);
    krest.setFillColor(Color::White);
    krest.setOutlineThickness(2.f);
    krest.setOutlineColor(Color::Red);
	Texture texture;
    if (!texture.loadFromFile("krestik1.png")) {
      
    }
	Sprite krestik(texture);
    krestik.setScale(0.025f, 0.025f);
    krestik.setPosition(krest.getPosition().x, krest.getPosition().y);

	bool test = false, vhod = true, test1 = false, islam[10],okno = false, cenok = false;
	int randomIndex = 0;
	const int numRows = 2;
    const int numCols = 9;
    const int cellWidth = (1024 - 20) / numCols;
    const int cellHeight = (170);
    bool dev[10], dev2[10];
 	int zighail = 0;
 	for(int i = 0 ; i < 10 ; i++){
 	 dev[i]	= false;
	 }
    Font font;
    font.loadFromFile("Oswald-VariableFont_wght.ttf");
    
    Texture cifr[10];

	for(int i = 1 ; i <=9;i++){
		stringstream ss;
		string str;
		ss << i;
		ss >> str;
	cifr[i].loadFromFile("cifri/"+ str + ".png");	
	}
    
    Text otv("",font,13);
    otv.setPosition(205,605);
    otv.setFillColor(Color::Black);
    
	Text texts[10]; // �������� ������� �� 5 ��������� ��������	

    for (int i = 1; i <= 9; ++i) {
        texts[i].setFont(font);
        texts[i].setString("");
        texts[i].setCharacterSize(12);
        texts[i].setFillColor(sf::Color::Black);
        texts[i].setPosition(i + 15 + ((i-1) * 110), 217); // ��������� ������� ������� ������
    }
    
    Text zagolovok("������� 3: ��� 1.",font,30);
    zagolovok.setPosition(30,20);
    zagolovok.setFillColor(Color::Black);
    
    Text shag("���������\n    ��� 1",font,12);
    shag.setPosition(705,20);
    shag.setFillColor(Color::Black);
    
    Text shag1(" �������\n   ��� 2",font,12);
    shag1.setPosition(775,20);
    shag1.setFillColor(Color::Black);
    
    Text pimos(" ������ ",font,12);
    pimos.setPosition(845,30);
    pimos.setFillColor(Color::Black);
    
    RectangleShape povtor;
    povtor.setSize(Vector2f(60, 35));
    povtor.setOutlineColor(Color::Black);
    povtor.setOutlineThickness(2);
    povtor.setPosition(700,20);
    
    RectangleShape otveti;
    otveti.setSize(Vector2f(600, 100));
    otveti.setOutlineColor(Color::Black);
    otveti.setOutlineThickness(2);
    otveti.setPosition(200,600);
    
    RectangleShape vpered;
    vpered.setSize(Vector2f(60, 35));
    vpered.setOutlineColor(Color::Black);
    vpered.setOutlineThickness(2);
    vpered.setPosition(770,20);
    
    RectangleShape pim;
    pim.setSize(Vector2f(60, 35));
    pim.setOutlineColor(Color::Black);
    pim.setOutlineThickness(2);
    pim.setPosition(840,20);
	
	RectangleShape rectangle;
    rectangle.setSize(Vector2f(30, 30));
    rectangle.setOutlineColor(Color::Black);
    rectangle.setOutlineThickness(2);
    rectangle.setPosition(900,600);
    rectangle.setTexture(&cifr[1]);
    
    RectangleShape rectangle1;
    rectangle1.setSize(Vector2f(30, 30));
    rectangle1.setOutlineColor(Color::Black);
    rectangle1.setOutlineThickness(2);
    rectangle1.setPosition(900+40,600);
    rectangle1.setTexture(&cifr[2]);
    
    RectangleShape rectangle2;
    rectangle2.setSize(Vector2f(30, 30));
    rectangle2.setOutlineColor(Color::Black);
    rectangle2.setOutlineThickness(2);
    rectangle2.setPosition(900+(40*2),600);
    rectangle2.setTexture(&cifr[3]);
    
    RectangleShape rectangle3;
    rectangle3.setSize(Vector2f(30, 30));
    rectangle3.setOutlineColor(Color::Black);
    rectangle3.setOutlineThickness(2);
    rectangle3.setPosition(900,600+40);
    rectangle3.setTexture(&cifr[4]);
    
    RectangleShape rectangle4;
    rectangle4.setSize(Vector2f(30, 30));
    rectangle4.setOutlineColor(Color::Black);
    rectangle4.setOutlineThickness(2);
    rectangle4.setPosition(900+40,600+40);
    rectangle4.setTexture(&cifr[5]);
    
    RectangleShape rectangle5;
    rectangle5.setSize(Vector2f(30, 30));
    rectangle5.setOutlineColor(Color::Black);
    rectangle5.setOutlineThickness(2);
    rectangle5.setPosition(900+(40*2),600+40);
    rectangle5.setTexture(&cifr[6]);
    
    RectangleShape rectangle6;
    rectangle6.setSize(Vector2f(30, 30));
    rectangle6.setOutlineColor(Color::Black);
    rectangle6.setOutlineThickness(2);
    rectangle6.setPosition(900,600+(40*2));
    rectangle6.setTexture(&cifr[7]);
    
    RectangleShape rectangle7;
    rectangle7.setSize(Vector2f(30, 30));
    rectangle7.setOutlineColor(Color::Black);
    rectangle7.setOutlineThickness(2);
    rectangle7.setPosition(900+40,600+(40*2));
    rectangle7.setTexture(&cifr[8]);
    
    RectangleShape rectangle8;
    rectangle8.setSize(Vector2f(30, 30));
    rectangle8.setOutlineColor(Color::Black);
    rectangle8.setOutlineThickness(2);
    rectangle8.setPosition(900+(40*2),600+(40*2));
    rectangle8.setTexture(&cifr[9]);
	
    RectangleShape cells[numRows][numCols];
    Text text[numRows][numCols];
    std::vector<int> heh{
	1,2,3,4,5,6,7,8,9,0
	};
	String str[10]{
	"1. ���� \n��������� \n(���������������) \n� ������� \n������������.",
	"2. ���� \n������������ � \n������������\n��������������� \n����������� � \n�������\n��������.",
	"3. ���� \n��������� ����� \n� ������� \n�����������.",
	"4. ���� ���������� \n������� ������ �� \n�����������.",
	"5. ���� ���������� \n������������\n�������.",
	"6. ���� ���������� \n����������� �\n���������������\n�� ������� ����.",
	"7. ���� \n���������������\n������ � ���������\n �� �������.",
	"8. ���� ��������� �\n������� ������\n� ����������.",
	"9. ���� ��������� \n������� \n������������ \n�� �����."
	};

	std::vector<std::string> str1{"���������� �� ��������� �������� ������ ���������� ���������� ���������� ����������� ���������� \n������� ������������.",
	"����������� �������� �������� � ����������� ��������� ��� ���������� ����������� � ���������� ������� \n�������� ������������ ������������ ������ �� ��� ��������������� ����������� � ������� ��������.",
	"������������ ������ ������������ ��������� �������� � �� ���� ������ ��������� ����� � ������� \n����������� ��������� ����, � ��� ������ ������� ��������������� �� ������, ������ ��� ������������.",
	"�������������� ���������� ����� ������� ������������ � �� ���� ������ - ����� ������� � ������� �� \n����������.",
	"������������ ���������� ������������ ������ ������� �������� � ������������ ������ ��� ��������� ��� \n��� ������� ������, ��������� �����������, ��� � ��� ������� ����� ������ ������ ��� ���� ������.",
	"������������ �������� ������������ ������ ������� �������� ��� ������� ������� �����.",
	"�������������� �������������� ������ ������� �������� � ��������������� ��������� (������������ � \n��������������) ���������� ���� �������� �������� ��������, ���������� ������ ������ � ������� ��������.",
	"����. � ��������� ����� ����. � ����. � �������� ����. ����. �����, ������� ������� ��������. ������ ��. � \n������� ���. ��� � ����. ����. ����� ������, ����. ������� ����������, �����. ��� ����������� �������������� \n�������������, �������������� ��������� ������ ������� �������� � ������� ������.",
	"������������ ���������� ������������ ����������� ����� ������� ������������, ��������� ������ \n���������� � ������ ���������� ������ ������� ��������."
	,""};
	std::vector<std::string> str2{
	"���������� �� \n��������� \n�������� \n������ ���������� \n���������� \n���������� \n����������� \n���������� \n������� \n������������.",
	"����������� \n�������� �������� \n� ����������� \n��������� ��� \n���������� \n����������� \n� ���������� \n������� �������� \n������������ \n������������ \n������ �� ��� \n��������������� \n����������� � \n������� ��������.",
	"������������ ������ \n������������ \n��������� �������� \n� �� ���� ������ \n��������� ����� \n� ������� \n����������� \n��������� \n����, � ��� \n������ ������� \n��������������� �� \n������, \n������ ��� \n������������.",
	"�������������� \n���������� ����� \n������� \n������������ \n� �� ���� ������ \n- ����� ������� \n� ������� �� \n����������.",
	"������������ \n���������� \n������������ \n������ \n������� �������� \n� ������������ \n������ \n��� ��������� ��� \n��� ������� ������, \n��������� \n�����������, \n��� � ��� ������� \n����� ������ \n������ ��� \n���� ������.",
	"������������ \n�������� \n������������ \n������ ������� \n�������� ��� \n������� ������� \n�����.",
	"�������������� \n�������������� \n������ ������� \n�������� � \n��������������� \n��������� \n(������������ � \n��������������) \n���������� ���� \n�������� �������� \n��������, \n���������� \n������ ������ \n� ������� ��������.",
	"����. � ��������� \n����� ����. � ����. \n� �������� ����. \n����. �����, \n������� ������� \n��������. ������ \n��. � ������� ���. \n��� � ����. ����. \n����� ������, ����. \n������� \n����������, \n�����. ��� \n����������� \n�������������� \n�������������, \n�������������� \n��������� ������ \n������� �������� \n� ������� ������.",
	"������������ \n���������� \n������������ \n����������� ����� \n������� \n������������, \n��������� ������ \n���������� � ������ \n���������� ������ \n������� ��������."
	,""};
	
    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numCols; ++j)
        {
            cells[i][j].setSize(sf::Vector2f(cellWidth, cellHeight*(i+1)));
            cells[i][j].setPosition(10 + j * cellWidth, 80 + i * cellHeight);
            if(i == 0 ){
             cells[i][j].setSize(sf::Vector2f(cellWidth, cellHeight*(i+0.8)));	
			}
			            if(i == 1 ){
            cells[i][j].setPosition(10 + j * cellWidth, 80 + i * cellHeight-33);
			}
            cells[i][j].setOutlineColor(sf::Color::Black);
            cells[i][j].setOutlineThickness(1.f);
			cells[i][j].setFillColor(Color::Transparent);
            text[i][j].setFont(font);
            if(i == 0 ){
			text[i][j].setString(str[j]);
			}
            text[i][j].setCharacterSize(12);
            text[i][j].setFillColor(Color::Black);
            text[i][j].setPosition(cells[i][j].getPosition().x + 5, cells[i][j].getPosition().y + 5);
            
        }
    }
shuffle_two_arrays(str1, str2,heh);

	CircleShape circle(15);
	circle.setOutlineColor(Color::Black);
	circle.setOutlineThickness(2);
	circle.setPosition(230,720); 
	circle.setFillColor(Color::White);
//////
////// ����� ����� ������ ���
	float scrollSpeed = 60.0f;
	Text kallla("������� 3: ��� 2. �������� ������, ��������������� ������� �� ������.",font,20);
    kallla.setPosition(170,20);
    kallla.setFillColor(Color::Black);
    
    String Atap[10]{
	"1.	���� ��������� (���������������) � ������� ������������.",
	"2.	���� ������������ � ������������ ��������������� ����������� � ������� ��������.",
	"3. ���� ��������� ����� � ������� �����������.",
	"4.	���� ���������� ������� ������ �� �����������.",
	"5.	���� ���������� ������������ �������.",
	"6. ���� ���������� ����������� � ��������������� �� ������� ����.",
	"7.	���� ��������������� ������ � ������������� �� ������",
	"8. ���� ��������� � ������� ������ � ����������.",
	"9. ���� ��������� ������� ������������ �� �����."	
	};
	
	Text atapi[10];
    for (int i = 0; i < 10; ++i) {
        atapi[i].setFont(font);
        atapi[i].setString(Atap[i]);
        atapi[i].setCharacterSize(20);
        atapi[i].setFillColor(sf::Color::Black);
        atapi[i].setPosition(90, 70 + (220 * (i / 9)) + (220 * (i % 9)));
    }
	
	RectangleShape vopros[9];
    	for (int i = 0; i < 9; ++i) {
        vopros[i].setSize(sf::Vector2f(750, 40));
        vopros[i].setPosition(80, 60 + (220 * i));
        vopros[i].setOutlineColor(Color::Black);
        vopros[i].setOutlineThickness(3);
        vopros[i].setFillColor(Color::White);
    }
	int jack = 0,schet = 0;
	String otvetikTest[28]{
	"���������� �� ��������� �������� ������ ���������� ���������� ���������� ����������� ���������� ������� ������������.",
	"���������� �� ��������� �������� ������ ���������� ���������� � ���������� ����������� ���������� ������������� ������������.",
	"���������� �� ��������� �������� ������ ���������� ���������� � ���������� ����������� ���������� ����������-������������� ������������.",
	"����������� �������� �������� � ����������� ��������� ��� ���������� ����������� � ���������� ������� �������� ������������ ������������ ������ \n�� ��� ��������������� ����������� � ������� ��������.",
	"����������� �������� ����������� � ��������� ��� ����������� � ��������� ������ ����������� � ����������� ������������.",
	"����������� �������� ����������� � ��������� ��� ����������� � �������� � ������������ ���������� � ��������� ������ ����������� � ������������.",
	"������������  ������ ������������ ��������� �������� � �� ���� ������ ��������� ����� � ������� ����������� ��������� ����, � ��� ������ ������� \n��������������� �� ������, ������ ��� ������������.",
	"������������ ��������� ����� � ������� ����������� ����������� � ���������� ��������� �������� ��������.",
	"���������� �� ��������� �������� ������ ���������� ���������� � ������������� ������, � ����� ��������� ����� � ������� ����������� \n����������� � ���������� ����������� ������.",
	"�������������� ���������� ����� ������� ������������ � �� ���� ������ - ����� ������� � ������� �� ����������.",
	"�������������� ���������� ����� ������������� ������������ � �� ���� ������ - ����� ������� � ������� �� ����������.",
	"�������������� ���������� ����� ������������� ������������ � �� ���� ������ - ����� ������� � ������� �� ����������.",
	"������������ ���������� ������������ ������ ������� �������� � ������������ ������ ��� ��������� ��� ��� ������� ������, ��������� �����������, \n��� � ��� ������� ����� ������ ������ ��� ���� ������.",
	"�������������� ����������� ��������� ������������ ����� ������ � ��������������� ������ � ����������� ������ ��������� ��������� ��������������� \n������� ��������.",
	"������������ ��������� ������������ ����� ������ � ����������� ������ � ����������� ������ ��������� ��������� ��������������� ������� ��������.",
	"������������ �������� ������������ ������ ������� �������� ��� ������� ������� �����.",
	"��������� ������� ��������, ��������� �����������.",
	"",
	"�������������� �������������� ������ ������� �������� � ��������������� ��������� (������������ � ��������������) ���������� ���� �������� �������� \n��������, ���������� ������ ������ � ������� ��������.",
	"�������������� �������������� �������� ��������, ��������� �����������, ������������ �� �������� �������������� ��������� ���������� ���� \n� �������� (�� �����������) �������� ������.",
	"",
	"��������� � ��������� ����� ���������� � ������������� � �������� ��������� �������� �����, ������� ������� ������������ ������ ������ \n� ������� ������������.",
	"��� � ������� ��������� ����� ������, ��������� ������� ����������, ����������� ��� ����������� �������������� �������������, \n�������������� ��������� ������ ������� �������� � ������� ������.",
	"��������� ������� ��������, ��������� �����������, ��������� � ��������� ����� ���������� � ������������� � �������� ��������� �������� \n����� ��������� � ��������� ����� �������, ������������� � �������� ��������� �������� �����.",
	"������������ ���������� ������������ ����������� ����� ������� ������������, ��������� ������ ���������� � ������ ���������� ������ ������� ��������.",
	"������������ ��������� ������������ ������ ����������� ����������� � ���������� ��� ����������� ����� ������������� (� � ������, ���� ������ \n�� ����, ���������������) ������������.",
	"������������ ���������� ����������� ����������-������������� ������������, ��������� ������ ����������� ����������� � ������������ � ��������� \n����������-������������� ������������."
	};
	
	int arr[27] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
	int otvet[27] = {1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0};
	int ochko[9]={0,0,0,0,0,0,0,0,0};
	int an[9]={0,0,0,0,0,0,0,0,0};
	bool pen = false;
	int didd = 0;
	shuffleArrays(arr,27);

	Text oT[28];
    for (int i = 0; i < 28; ++i) {
        oT[i].setFont(font);
        oT[i].setString(otvetikTest[arr[i]]);
        oT[i].setCharacterSize(15);
        oT[i].setFillColor(Color::Black);
        oT[i].setPosition(40, 20 + (220 * (i / 3)) + (55 * (i % 3)) + 100); // ������������ ������� ��� �����������
    }
    Texture gal;
    gal.loadFromFile("Gal.png");
    Sprite clickSprite[28];
        for (int i = 0; i < 28; ++i) {
clickSprite[i].setTexture(gal);
clickSprite[i].setPosition(0,-500);
clickSprite[i].setScale(0.2,0.2);
    }
	int currentStage = 0; // ������� ���� (�������� � 0)
    vector<int> selectedAnswers;
	
	Text timer;
    timer.setFont(font);
    timer.setCharacterSize(24);
    timer.setFillColor(sf::Color::Black);
    timer.setPosition(960,10);	
    
    Text podtverdit;
    podtverdit.setFont(font);
    podtverdit.setCharacterSize(12);
    podtverdit.setString("�����������");
    podtverdit.setFillColor(sf::Color::Black);
    podtverdit.setPosition(960,10);
    
    Clock clock;
    int vrema = 120,galki = 0;
    int timerSeconds = vrema;
	int totalScore = 0;
	RectangleShape timi(Vector2f(44, 30)); 
    timi.setFillColor(Color::White);
	timi.setOutlineColor(Color::Black);
	timi.setOutlineThickness(3);  
    timi.setPosition(950, 10);
    
    RectangleShape podtver(Vector2f(80, 30)); 
    podtver.setFillColor(Color::White);
	podtver.setOutlineColor(Color::Black);
	podtver.setOutlineThickness(3);  
    podtver.setPosition(840, 10);
	
	Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(Color::Black);
    scoreText.setPosition(320, 450);
    
    Texture knopkaN;
	knopkaN.loadFromFile("knopka_levo.png");
    Sprite knopN(knopkaN);
    knopN.setPosition(660,430);
    knopN.setScale(0.12f,0.12f);
    
    Texture knopkaPP;
	knopkaPP.loadFromFile("knopka_povtora.png");
    Sprite knopPP(knopkaPP);
    knopPP.setPosition(580,433);
    knopPP.setScale(0.10f,0.10f);
    
    int y = 0, x = 0;
    float zoomLevel = 1.0f;
    int S = 0;
//////
 Vector2f offset(30, 0); // Adjust as needed
	while (window.isOpen()) {
        Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (Keyboard::isKeyPressed(Keyboard::Space)) {
                vhod = false;
                test = true;
            }
            if (event.type == Event::MouseButtonPressed) {
            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window), view);
            if(povtor.getGlobalBounds().contains(mousePos)){
            randomIndex = 0;
            for (int i = 1; i <= 9; ++i) {
      		texts[i].setString("");
			  zighail = 0;
			  S = 0;
			  for(int i = 0; i < 9; i++){
			dev[i] = false;
		}  
    }
    shuffle_two_arrays(str1, str2,heh);
}   

			if(knopP.getGlobalBounds().contains(mousePos) && test == true && cenok == false){
            randomIndex = 0;
            for (int i = 1; i <= 9; ++i) {
      		texts[i].setString("");
			zighail = 0;
			S = 0;
				for(int i = 0; i < 9; i++){
			dev[i] = false;
		}
    }
    shuffle_two_arrays(str1, str2,heh);
} 

			
			if (event.type == sf::Event::MouseMoved) {
				        Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window), view);
        sf::Vector2f relativePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window), view);
                if (krest.getGlobalBounds().contains(sf::Vector2f(relativePosition))) {
                    krest.setFillColor(sf::Color::Red);
                } else {
                    krest.setFillColor(sf::Color::White);
                }
            }
  
}
  
            
        if (event.type == Event::MouseWheelScrolled)
        {
            if (event.mouseWheelScroll.delta > 0){
                view.move(0, -scrollSpeed);
			}
            else if (event.mouseWheelScroll.delta < 0){
                view.move(0, scrollSpeed);
			}
            if (view.getCenter().y <= 0 + 350)
    {
        view.setCenter(view.getCenter().x, 0 + 350);
    }
    else if (view.getCenter().y >= 2000 - 300)
    {
        view.setCenter(view.getCenter().x, 2000 - 300);
    }
    
//    
//                        if (event.type == sf::Event::MouseWheelScrolled && Keyboard::isKeyPressed(Keyboard::LControl) or event.type == sf::Event::MouseWheelScrolled && Keyboard::isKeyPressed(Keyboard::RControl)) {
//                if (event.mouseWheelScroll.delta > 0) {
//                	if(zoomLevel > 0.6)
//                    zoomLevel *= 0.9f; // Zoom in
//                    
//                } else {
//                	if(zoomLevel < 1.5)
//                    zoomLevel *= 1.1f; // Zoom out
//                    
//                }
//                view.setSize(window.getDefaultView().getSize() / zoomLevel);
//            }
//    view.setSize(window.getSize().x - (window.getSize().x/4) ,window.getSize().y - (window.getSize().y/4));	
    
    
        }
            if (event.type == Event::MouseButtonPressed) {

            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window), view);
			sf::Vector2f relativePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window), view);		
			if(vpered.getGlobalBounds().contains(relativePosition)){
            test = false;
			test1 = true;
    }
    		if(knopV.getGlobalBounds().contains(relativePosition)&& test == true && cenok == false){
            test = false;
			test1 = true;
	}
	

    if(knopN.getGlobalBounds().contains(relativePosition) && test1 == true && cenok == true){
            test = true;
			test1 = false;
			view.setCenter(1024/2,768/2);
			render(window, view);
			cenok = false; 
    }
    if(knopPP.getGlobalBounds().contains(relativePosition) && test1 == true && cenok == true){
		cenok = false;
		timerSeconds = vrema;
		updateTimer(timer, clock, timerSeconds, cenok, pen);
		for (int i = 0; i < 28; ++i) {
clickSprite[i].setTexture(gal);
clickSprite[i].setPosition(0,-500);
clickSprite[i].setScale(0.2,0.2);
    }
	totalScore = 0;
	for (int i = 0; i < 10; ++i) {
        ochko[i] = 0;
        an[i] = 0;
        }  
}
    if(podtver.getGlobalBounds().contains(relativePosition) && test1 == true && cenok == false && galki > 8 ){
cenok =  true;
}
    if (krest.getGlobalBounds().contains(sf::Vector2f(relativePosition)) && okno == true) {
                        okno = false;
    } 	
	if (krest.getGlobalBounds().contains(sf::Vector2f(relativePosition)) && cenok) {
                        cenok = false;
    } 	
            if (event.type == Event::MouseButtonPressed && test1) {
                if (event.mouseButton.button == Mouse::Left) {
                    Vector2f mousePos = Vector2f((mousePos.x), (mousePos.y + ((view.getCenter().y+(768/2))-768)));
                    // �������� �� ������� �� �����
                    for (int i = 0; i < 28; ++i) {
                    	                    	if(schet%3 == 0 ){
                    	jack++;	
						}
						schet ++ ;
if (!cenok) {        
    createSpriteOnClick(window,oT[i], clickSprite[jack], offset, view,otvet[arr[i]],ochko[jack],pen,an[jack]);
        }

                    }
              jack = 0,schet = 0;  }
            }
    
    		if(randomIndex < 9){
         	klick(view,window,rectangle,event,texts[heh[randomIndex]],str2,0,randomIndex,str1,otv,dev[zighail],zighail,heh,islam[zighail],okno,S);
            klick(view,window,rectangle1,event,texts[heh[randomIndex]],str2,1,randomIndex,str1,otv,dev[zighail],zighail,heh,islam[zighail],okno,S);
            klick(view,window,rectangle2,event,texts[heh[randomIndex]],str2,2,randomIndex,str1,otv,dev[zighail],zighail,heh,islam[zighail],okno,S);
            klick(view,window,rectangle3,event,texts[heh[randomIndex]],str2,3,randomIndex,str1,otv,dev[zighail],zighail,heh,islam[zighail],okno,S);
            klick(view,window,rectangle4,event,texts[heh[randomIndex]],str2,4,randomIndex,str1,otv,dev[zighail],zighail,heh,islam[zighail],okno,S);
            klick(view,window,rectangle5,event,texts[heh[randomIndex]],str2,5,randomIndex,str1,otv,dev[zighail],zighail,heh,islam[zighail],okno,S);
            klick(view,window,rectangle6,event,texts[heh[randomIndex]],str2,6,randomIndex,str1,otv,dev[zighail],zighail,heh,islam[zighail],okno,S);
            klick(view,window,rectangle7,event,texts[heh[randomIndex]],str2,7,randomIndex,str1,otv,dev[zighail],zighail,heh,islam[zighail],okno,S);
            klick(view,window,rectangle8,event,texts[heh[randomIndex]],str2,8,randomIndex,str1,otv,dev[zighail],zighail,heh,islam[zighail],okno,S);
			}
//			handleEvents(window, view, scrollSpeed,event);
}
		
	
}
        if(vhod){
        	window.clear(Color(245, 251, 165));
        	window.draw(testik);
		}
        if(test){
        	window.clear(Color::White);
//		 window.draw(akran);          
		 for (int i = 0; i < numRows; ++i)
        {
            for (int j = 0; j < numCols; ++j)
            {
                window.draw(cells[i][j]);
                window.draw(text[i][j]);
            }
        }
        otv.setString(str1[randomIndex]);
		window.draw(rectangle);
		window.draw(rectangle1);
		window.draw(rectangle2);
		window.draw(rectangle3);
		window.draw(rectangle4);
		window.draw(rectangle5);
		window.draw(rectangle6);
		window.draw(rectangle7);
		window.draw(rectangle8);
		window.draw(zagolovok);
		window.draw(povtor);
		window.draw(otveti);
		window.draw(otv);
		window.draw(vpered);
		window.draw(shag);
		window.draw(shag1);
		window.draw(pim);
		window.draw(pimos);
	for(int i = 0; i < 9; i++){
    circle.setPosition(230+(51*(i+1)),720);
    if(i >= zighail){
        circle.setFillColor(Color::White);    
    } else {
        if(dev[i] == true){
            circle.setFillColor(Color::Green);    
        } else {
            circle.setFillColor(Color::Red);    
        }
    }
    window.draw(circle);
}
	for(int i = 1;i <=9; i++){
	
window.draw(texts[i]);
	}
	if (S == 9 && okno == true){
		window.draw(akno);
		window.draw(okn);
		window.draw(knopV);
		window.draw(knopP);
		window.draw(krest);
		window.draw(krestik);
	}
		}
		if(test1){
			if(test1 == true){
	okna.loadFromFile("images/vernis.jpg");
	}
		window.clear(Color::White);
		render(window, view);
		window.draw(kallla);	
		for (int i = 0; i < 9; ++i) {
                window.draw(vopros[i]);
                window.draw(atapi[i]);
        }

        for (int i = 0; i < 27; ++i) {
                window.draw(clickSprite[i]);   
    }
        		for (int i = 0; i < 27; ++i) {
        			
                window.draw(oT[i]);   
        }
	updateTimer(timer, clock, timerSeconds, cenok, pen);

    Vector2f viewPosition = view.getCenter() - view.getSize() / 2.f;
    timi.setPosition(970, viewPosition.y + 10);
    timer.setPosition(975, viewPosition.y + 10);
    podtver.setPosition(890, viewPosition.y + 10);
    podtverdit.setPosition(897, viewPosition.y + 16);
    y = viewPosition.y;
    x = viewPosition.x;
    scoreText.setPosition(320+x, 450+y);
    okn.setPosition(240+x,240+y);
    knopPP.setPosition(580+x,433+y);
    knopN.setPosition(660+x,430+y);
    akno.setPosition(okn.getPosition());
    window.draw(timi);
    window.draw(podtver);
    window.draw(timer);
    window.draw(podtverdit);
  
    galki=0;
     for (int i = 0; i < 10; ++i) {
     	if(an[i] > 0){
     	   galki += 1;	
		 }
         
        }
    
    if (cenok && galki) {
        totalScore = 0;
        for (int i = 0; i < 10; ++i) {
            totalScore += ochko[i];
        }
        scoreText.setString("���� ���������� ������: " + to_string(totalScore));
        window.draw(akno);
        window.draw(okn);
        window.draw(scoreText);
        window.draw(knopPP);
        window.draw(knopN);
    }
		}
		levelpoint = totalScore;
		okn.setPosition(240,240);
		akno.setPosition(okn.getPosition());

        window.display();
                    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                break;
            }
    }
  

}
