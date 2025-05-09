#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
#include<sstream>
#include<locale>
#include <string> 
using namespace sf;
using namespace std;

void level1(RenderWindow& window,int& levelpoint)
{

	const int screenWidth = 1024;
    const int screenHeight = 768;
	window.setFramerateLimit(30);
start:   // переход в начало программы
///	// Переменные таймера/////////////////////////
 	Clock clock;                              ///
    int Time1=0, Time2=0,prov=1,Time3,Time4; ////
////////////////////////////////////////////////   
    // для проверки очков
 float chek=100, chek1=0;
   // музыка //////////////////////////////////
    Music music;                         //////
    music.openFromFile("music/fon.ogg"); /////
    music.play();                        /////
/////////////////////////////////////////////
    // Загрузка текстур для картинок//////////////////////
    Texture image1;                                   //
    if (!image1.loadFromFile("images/titul0.jpg")) {   //
                                       //
                                                     //
    Texture image2;                                  //
    if (!image2.loadFromFile("images/titul1.jpg")){   //
       
    
    Texture image3;
    if (!image3.loadFromFile("images/titul2.jpg")){
	}
        
        
    Texture image4;
    if (!image4.loadFromFile("images/Posle1.jpg")){
	}
        

    Texture image5;
    if (!image5.loadFromFile("images/urov1.jpg")){
	}
        
        
         Texture image6;
    if (!image6.loadFromFile("images/fon.jpg")){
	}
        
        
        Texture image7;
    if (!image7.loadFromFile("images/okno.jpg")){
	}
    
    	 
    	    Texture image8;
    if (!image8.loadFromFile("images/vernis.jpg")){
	}
    	 
    	 
    	    Texture image9;
    if (!image9.loadFromFile("images/okno1.jpg")){
	}
    	
   ///////////////// подключение шрифта //////////////
                                                  ///
        Font font;                                ///
    if (!font.loadFromFile("arial.ttf")){         //
                              //
    }                                              //
    ////////////////////////////////////////////////
    // кнопки 1 и 2 шаг
    RectangleShape rectangle(sf::Vector2f(40, 25));
    rectangle.setPosition(760,10);
    rectangle.setOutlineThickness(3);
    rectangle.setOutlineColor(Color::Black);
    rectangle.setFillColor(Color(128, 128, 128));
    
    RectangleShape rectangle1(sf::Vector2f(40, 25));
    rectangle1.setPosition(850,10);
    rectangle1.setOutlineThickness(3);
    rectangle1.setOutlineColor(Color::Black);
    rectangle1.setFillColor(Color(128, 128, 128));
    
    // часы
    RectangleShape rectangle2(sf::Vector2f(50,25));
    rectangle2.setPosition(640,12);
    rectangle2.setFillColor(Color::Black);
    
    // окошко в конце 1 шага
    RectangleShape rectangle3(sf::Vector2f(360, 160));
    rectangle3.setPosition(250,350);
    rectangle3.setFillColor(Color(128, 128, 128));
    // Кнопки в окошке
     RectangleShape rectangle4(sf::Vector2f(50, 35));
    rectangle4.setPosition(300,450);
    rectangle4.setOutlineThickness(3);
    rectangle4.setOutlineColor(Color::Black);
    
    RectangleShape rectangle5(sf::Vector2f(50, 35));
    rectangle5.setPosition(500,450);
    rectangle5.setOutlineThickness(3);
    rectangle5.setOutlineColor(Color::Black);
    
    RectangleShape rectangle6(sf::Vector2f(70, 25));
    rectangle6.setPosition(930,10);
    rectangle6.setOutlineThickness(3);
    rectangle6.setOutlineColor(Color::Black);
    rectangle6.setFillColor(Color(128, 128, 128));
    
    // текст 
    setlocale(LC_ALL, "Russian");
    
    Text proverka("Проверка", font, 12);
    proverka.setFillColor(Color::Black);
    proverka.setPosition(940,15);
    
    Text text("Уровень 1. Шаг 1", font, 10);
    text.setFillColor(Color::Black);
    text.setPosition(350,5);
    
    Text text1("Виды УУД", font, 12);
    text1.setFillColor(Color::Black);
    text1.setPosition(45,30);
        
    Text text2("Характеристики", font, 12);
    text2.setFillColor(Color::Black);
    text2.setPosition(350,30);
    
    Text text3("Познавательные УУД", font, 12);
    text3.setFillColor(Color::Black);
    text3.setPosition(15,150);
    
    Text text4("Коммуникативные УУД", font, 12);
    text4.setFillColor(Color::Black);
    text4.setPosition(15,400);
    
    Text text5("Регулятивные УУД", font, 12);
    text5.setFillColor(Color::Black);
    text5.setPosition(15,650);
    
    Text text6("Соблюдать правила ведения диалога", font, 12);
    text6.setFillColor(Color::Black);
    text6.setPosition(620,190);
    
    Text text7("Проводить изменения звуковой модели по \nпредложенному учителем правилу",font,12) ;
    text7.setFillColor(Color::Black);
    text7.setPosition(620,70);
    
    Text text8("Подбирать слова к модели",font,12) ;
    text8.setFillColor(Color::Black);
    text8.setPosition(620,110);
    
    Text text12("Характеризовать звуки по заданным признакам",font,12) ;
    text12.setFillColor(Color::Black);
    text12.setPosition(620,150);
 
    Text text13("Отвечать на вопросы по изученному материалу",font,12) ;
    text13.setFillColor(Color::Black);
    text13.setPosition(620,50);
    
    Text text14("Оценивать правильность выполненного задания",font,12) ;
    text14.setFillColor(Color::Black);
    text14.setPosition(620,230);
    
    Text text15("Сравнивать звуки, звуковой и буквенный \nсостав слова в соответствии с учебной задачей",font,12) ;
    text15.setFillColor(Color::Black);
    text15.setPosition(620,270);
    
    Text text16("Воспринимать суждения",font,12) ;
    text16.setFillColor(Color::Black);
    text16.setPosition(620,310);
    
    Text text17("Устанавливать основания для сравнения звуков, \nслов(на основе образца)",font,12) ;
    text17.setFillColor(Color::Black);
    text17.setPosition(620,340);
    
    Text text18("Строить устное речевое высказывание",font,12) ;
    text18.setFillColor(Color::Black);
    text18.setPosition(620,390);
    
    Text text19("Удерживать учебную задачу, поставленную учителем",font,12) ;
    text19.setFillColor(Color::Black);
    text19.setPosition(620,420);
    
    Text text20("Воспринимать разные точки зрения в процессе учебного диалога",font,12) ;
    text20.setFillColor(Color::Black);
    text20.setPosition(620,460);
    
    Text text21("Приводить примеры в соответствии с учебной задачей",font,12) ;
    text21.setFillColor(Color::Black);
    text21.setPosition(620,490);
    
    Text text22("Выражать эмоции в соответствии с целями и \nусловиями общения в знакомой среде",font,12) ;
    text22.setFillColor(Color::Black);
    text22.setPosition(620,520);
    
     Text text23("Формулировать выводы в соответствии с задачей",font,12) ;
    text23.setFillColor(Color::Black);
    text23.setPosition(620,560);
    
    Text text24("Выстраивать последовательность учебных операций",font,12) ;
    text24.setFillColor(Color::Black);
    text24.setPosition(620,590);
    
     Text text25("Проявлять уважительное отношение к собеседнику \nсоблюдать в процессе общения нормы речевого этикета",font,12) ;
    text25.setFillColor(Color::Black);
    text25.setPosition(620,630);
    
      Text text26("Анализировать графическую информуцию - модели \nзвукового состава слова",font,12) ;
    text26.setFillColor(Color::Black);
    text26.setPosition(620,670);
    
     Text text27("Находить указанную ошибку",font,12) ;
    text27.setFillColor(Color::Black);
    text27.setPosition(620,710);
     
       Text text28("Самостоятельно создавать модели звукового состава слова",font,12) ;
    text28.setFillColor(Color::Black);
    text28.setPosition(620,730);
    
      Text text29("Шаг-1",font,12) ;
    text29.setFillColor(Color::Black);
    text29.setPosition(762,15);
    
      Text text30("Шаг-2",font,12) ;
    text30.setFillColor(Color::Black);
    text30.setPosition(852,15);
    
      Text text31("Использовать алфавит для самосотоятельного \nупорядочивания списка слов", font, 12);
    text31.setFillColor(Color::Black);
    text31.setPosition(620,50);
    
      Text text32("Выбирать источник получения информации",font,12) ;
    text32.setFillColor(Color::Black);
    text32.setPosition(620,90);
    
    Text text33("Ответственно выполнять свою часть работы",font,12) ;
    text33.setFillColor(Color::Black);
    text33.setPosition(620,120);
    
    Text text34("Принимать цель совместной деятельности",font,12) ;
    text34.setFillColor(Color::Black);
    text34.setPosition(620,150);
 
    Text text35("Распределять роли, договариваться, учитывать интересы и мнения",font,12) ;
    text35.setFillColor(Color::Black);
    text35.setPosition(620,180);
    
    Text text36("Коллективно строить план действия по достижению цели",font,12) ;
    text36.setFillColor(Color::Black);
    text36.setPosition(620,210);
    
    Text text37("Да",font,15) ;
    text37.setFillColor(Color::Black);
    text37.setPosition(315,455);
    
    Text text38("Нет",font,15) ;
    text38.setFillColor(Color::Black);
    text38.setPosition(515,455);
    
    // Тест 2 шага
         Text text39("", font, 12);
    text39.setFillColor(Color::Black);
    text39.setPosition(0,0);
    
    Text text40("",font,12) ;
    text40.setFillColor(Color::Black);
    text40.setPosition(0,0);
    
    Text text41("",font,12) ;
    text41.setFillColor(Color::Black);
    text41.setPosition(0,0);
    
    Text text42("",font,12) ;
    text42.setFillColor(Color::Black);
    text42.setPosition(0,0);
 
    Text text43("",font,12) ;
    text43.setFillColor(Color::Black);
    text43.setPosition(0,0);
    
    Text text44("",font,12) ;
    text44.setFillColor(Color::Black);
    text44.setPosition(0,0);
    
    Text text45("",font,12) ;
    text45.setFillColor(Color::Black);
    text45.setPosition(0,0);
    
    Text text46("",font,12) ;
    text46.setFillColor(Color::Black);
    text46.setPosition(0,0);
    
    Text text47("",font,12) ;
    text47.setFillColor(Color::Black);
    text47.setPosition(0,0);
    
    Text text48("",font,12) ;
    text48.setFillColor(Color::Black);
    text48.setPosition(0,0);
    
    Text text49("",font,12) ;
    text49.setFillColor(Color::Black);
    text49.setPosition(0,0);
    
    Text text50("",font,12) ;
    text50.setFillColor(Color::Black);
    text50.setPosition(0,0);
    
    Text text51("",font,12) ;
    text51.setFillColor(Color::Black);
    text51.setPosition(0,0);
    
    Text text52("",font,12) ;
    text52.setFillColor(Color::Black);
    text52.setPosition(0,0);
    
     Text text53("",font,12) ;
    text53.setFillColor(Color::Black);
    text53.setPosition(620,560);
    
    Text text54("",font,12) ;
    text54.setFillColor(Color::Black);
    text54.setPosition(0,0);
    
     Text text55("",font,12) ;
    text55.setFillColor(Color::Black);
    text55.setPosition(620,630);
    
      Text text56("",font,12) ;
    text56.setFillColor(Color::Black);
    text56.setPosition(0,0);
    
     Text text57("",font,12) ;
    text57.setFillColor(Color::Black);
    text57.setPosition(0,0);
     
       Text text58("",font,12) ;
    text58.setFillColor(Color::Black);
    text58.setPosition(0,0);
 
    
      Text text59("", font, 12);
    text59.setFillColor(Color::Black);
    text59.setPosition(0,0);
    
      Text text60("",font,12) ;
    text60.setFillColor(Color::Black);
    text60.setPosition(0,0);
    
    Text text61("",font,12) ;
    text61.setFillColor(Color::Black);
    text61.setPosition(0,0);
    
    Text text62("",font,12) ;
    text62.setFillColor(Color::Black);
    text62.setPosition(0,0);
 
    Text text63("Распределять роли, договариваться, учитывать интересы и мнения",font,12) ;
    text63.setFillColor(Color::Black);
    text63.setPosition(620,180);
    
    Text text64("Коллективно строить план действия по достижению цели",font,12) ;
    text64.setFillColor(Color::Black);
    text64.setPosition(620,210);
    
    Text text65("Вы набрали:      из 26 ",font,15) ;
    text65.setFillColor(Color::Black);
    text65.setPosition(260,400);

    
    int x=0,y=0;
    Text exitWin("",font,12);
   
    
    Sprite sprite;
    // очки 1 шаг
    int currentImage = 1,a=0,i=0,count1=0,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0,count8=0,count9=0,count10=0,count11=0,count12=0,count13=0,count14=0;
    int count15=0 ,count16=0, count17=0,count18=0,count19=0, count20=0,count21=0,count22=0,count23=0,count24=0,count25=0,count26=0, count27=0;
    // очки 2 шага
    int point=0,point1=0,point2=0,point3=0,point4=0,point5=0,point6=0,point7=0,point8=0,point9=0,point10=0,point11=0,point12=0,point13=0,point14=0,point15=0,point16=0;
    int point17=0,point18=0,point19=0,point20=0,point21=0,point22=0,point23=0,point24=0,point25=0, sum1;
    
    // позиция слов 2 шаг
     int position=0,position1=0,position2=0,position3=0,position4=0,position5=0,position6=0,position7=0,position8=0,position9=0,position10=0,position11=0,position12=0,position13=0;
     int position14=0, position15=0,position16=0,position17=0,position18=0,position19=0,position20=0,position21=0,position22=0,position23=0,position24=0,position25=0;
  
  	sprite.setTexture(image1);
  	Sprite okno;
  	okno.setTexture(image7);
  	Sprite okno1;
  	okno1.setTexture(image8);
  	// окно после проверки с результатом > 19
  	Sprite okno2;
  	okno2.setTexture(image9);
  	 // Флаг, указывающий, была ли нажата левая кнопка мыши
    bool isText6Pressed = false;
    bool isText7Pressed = false;
    bool isText8Pressed = false;
    bool isText12Pressed = false;    bool isText13Pressed = false;    bool isText14Pressed = false;   bool isText15Pressed = false; bool isText31Pressed = false; bool isText34Pressed = false;
    bool isText16Pressed = false;    bool isText17Pressed = false;    bool isText18Pressed = false;   bool isText19Pressed = false; bool isText32Pressed = false; bool isText35Pressed = false;
    bool isText20Pressed = false;    bool isText21Pressed = false;    bool isText22Pressed = false;   bool isText23Pressed = false; bool isText33Pressed = false; bool isText36Pressed = false;
    bool isText24Pressed = false;	 bool isText25Pressed = false;    bool isText26Pressed = false;   bool isText27Pressed = false; bool isText28Pressed = false; bool isText39Pressed = false;
    bool isText40Pressed = false; 	 bool isText41Pressed = false;	  bool isText42Pressed = false;	  bool isText43Pressed = false; bool isText44Pressed = false; bool isText45Pressed = false;
    bool isText46Pressed = false;	 bool isText47Pressed = false;    bool isText48Pressed = false;   bool isText49Pressed = false; bool isText50Pressed = false; bool isText51Pressed = false;
    bool isText52Pressed = false;	 bool isText53Pressed = false;	 bool isText54Pressed = false;    bool isText55Pressed = false; bool isText64Pressed = false; bool isText56Pressed = false;
    bool isText57Pressed = false;	 bool isText58Pressed = false;   bool isText59Pressed = false;    bool isText60Pressed = false; bool isText61Pressed = false; bool isText62Pressed = false; bool isText63Pressed = false;

    while (window.isOpen())
    {
        Event event;
        // Воспроизведение музыки, когда она закончится
         music.setLoop(true);
         
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
                
              
             
           ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Движение мышью
               // Проверка нажатия левой кнопки мыши
    	 	else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        // Проверка, была ли нажата левая кнопка мыши на text6
        
          	if (text6.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
           	 isText6Pressed = true; }
            
        // Проверка, была ли нажата левая кнопка мыши на text7
       	 else if (text7.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText7Pressed = true;}
            // Проверка, была ли нажата левая кнопка мыши на text7
       	 else if (text8.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText8Pressed = true;}
            
             else if (text12.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText12Pressed = true;}
            
             else if (text13.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText13Pressed = true;}
            
             else if (text14.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText14Pressed = true;}
            
             else if (text15.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText15Pressed = true;}
            
             else if (text16.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText16Pressed = true;}
            
             else if (text17.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText17Pressed = true;}
            
             else if (text18.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText18Pressed = true;}
            
             else if (text19.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText19Pressed = true;}
            
             else if (text20.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText20Pressed = true;}
            
             else if (text21.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText21Pressed = true;}
            
             else if (text22.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText22Pressed = true;}
            
             else if (text23.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText23Pressed = true;}
            
            else if (text24.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText24Pressed = true;}
            
            else if (text25.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText25Pressed = true;}
            
            else if (text26.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText26Pressed = true;}
            
            else if (text27.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText27Pressed = true;}
            
            else if (text28.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText28Pressed = true;}
            
            else if (text31.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText31Pressed = true;}
        	
        	else if (text32.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText32Pressed = true;}
            
             else if (text33.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText33Pressed = true;}
            
             else if (text34.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText34Pressed = true;}
            
             else if (text35.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText35Pressed = true;}
            
             else if (text36.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText36Pressed = true;}
        
            //////Нажатие на кнопку
                 
    	} 
    /////////////////////////////
    // Проверка отпускания левой кнопки мыши
    	else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
        // Проверка, была ли отпущена левая кнопка мыши на text6
      	  if (isText6Pressed) {
            isText6Pressed = false;
        }
        // Проверка, была ли отпущена левая кнопка мыши на text7
       	 else if (isText7Pressed) {
            isText7Pressed = false;
      	  }
      	  
      	   else if (isText8Pressed) {
            isText8Pressed = false;
      	  }
      	  
      	     else if (isText12Pressed) {
            isText12Pressed = false;
      	  }
      	     else if (isText13Pressed) {
            isText13Pressed = false;
      	  }
      	     else if (isText14Pressed) {
            isText14Pressed = false;
      	  }
      	     else if (isText15Pressed) {
            isText15Pressed = false;
      	  }
      	     else if (isText16Pressed) {
            isText16Pressed = false;
      	  }
      	     else if (isText17Pressed) {
            isText17Pressed = false;
      	  }
      	     else if (isText18Pressed) {
            isText18Pressed = false;
      	  }
      	     else if (isText19Pressed) {
            isText19Pressed = false;
      	  }
      	     else if (isText20Pressed) {
            isText20Pressed = false;
      	  }
      	     else if (isText21Pressed) {
            isText21Pressed = false;
      	  }
      	     else if (isText22Pressed) {
            isText22Pressed = false;
      	  }
      	     else if (isText23Pressed) {
            isText23Pressed = false;
      	  }
      	  
      	      else if (isText24Pressed) {
            isText24Pressed = false;
      	  }
      	  
      	      else if (isText25Pressed) {
            isText25Pressed = false;
      	  }
      	  
      	      else if (isText26Pressed) {
            isText26Pressed = false;
      	  }
      	  
      	      else if (isText27Pressed) {
            isText27Pressed = false;
      	  }
      	  
      	      else if (isText28Pressed) {
            isText28Pressed = false;
      	  }
      	  
      	     else if (isText31Pressed) {
            isText31Pressed = false;
      	  }
      	     else if (isText32Pressed) {
            isText32Pressed = false;
      	  }
      	     else if (isText33Pressed) {
            isText33Pressed = false;
      	  }
      	     else if (isText34Pressed) {
            isText34Pressed = false;
      	  }
      	     else if (isText35Pressed) {
            isText35Pressed = false;
      	  }
      	     else if (isText36Pressed) {
            isText36Pressed = false;
      	  }
   		 } 
    // Проверка передвижения мыши
   		 else if (event.type == sf::Event::MouseMoved) {
        // Передвижение text6 при удерживании левой кнопки мыши на нем
   
        
        if (isText6Pressed) {
        	
            text6.setPosition(event.mouseMove.x, event.mouseMove.y);
            
            if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 301&& event.mouseMove.y <= 550){
            	  text6.setFillColor(Color::Green);
            	  
      count1=1;
			}
			else {
				
				 text6.setFillColor(Color::Red); 
				 count1=0 ;}
        }
        //////////////////////////////////////////////////////////////////////
          if (isText7Pressed) {
            text7.setPosition(event.mouseMove.x, event.mouseMove.y);
            
            if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 40 && event.mouseMove.y <= 300){
            	  text7.setFillColor(Color::Green);
       count2=1;
			}
			else {
				
				 text7.setFillColor(Color::Red); 
				 count2=0;}
        }
        ///////////////////////////////////////////////////////////////////
        // Передвижение text7 при удерживании левой кнопки мыши на нем
        if (isText8Pressed) {
            text8.setPosition(event.mouseMove.x, event.mouseMove.y);
            
            // проверка правильности растановки ответов 
            if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 40 && event.mouseMove.y <= 300){
            	  text8.setFillColor(Color::Green);
                    count3=1;     
			}
			else {
				
				 text8.setFillColor(Color::Red); 
				 count3=0;}
        }
        //////////////////////////////////////////////
            if (isText12Pressed) {
            text12.setPosition(event.mouseMove.x, event.mouseMove.y);
            
              if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 40 && event.mouseMove.y <= 300){
            	  text12.setFillColor(Color::Green);
       count4=1;
			}
			else {
				
				 text12.setFillColor(Color::Red); 
				 count4=0;}
            
        }
        ////////////////////////////////////////////////////////////////////////////
        
            if (isText13Pressed) {
            text13.setPosition(event.mouseMove.x, event.mouseMove.y);
            
              if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 301&& event.mouseMove.y <= 550){
            	  text13.setFillColor(Color::Green);
       count5=1;
			}
			else {
				
				 text13.setFillColor(Color::Red); 
				 count5=0;}
        }
        //////////////////////////////////////////////////////////////////////////
            if (isText14Pressed) {
            text14.setPosition(event.mouseMove.x, event.mouseMove.y);
            
              if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 551 && event.mouseMove.y <= 750){
            	  text14.setFillColor(Color::Green);
            	  
       count6=1;
			}
			else {
				
				 text14.setFillColor(Color::Red); 
				 count6=0;}
        }
        ///////////////////////////////////////////////////////
            if (isText15Pressed) {
            text15.setPosition(event.mouseMove.x, event.mouseMove.y);
            
            if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 40 && event.mouseMove.y <= 300){
            	  text15.setFillColor(Color::Green);
       count7=1;
			}
			else {
				
				 text15.setFillColor(Color::Red); 
				 count7=0;}
        }
        ////////////////////////////////////////////////////////////////
            if (isText16Pressed) {
            text16.setPosition(event.mouseMove.x, event.mouseMove.y);
            
                 if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 301&& event.mouseMove.y <= 550){
            	  text16.setFillColor(Color::Green);
       count8=1;
			}
			else {
				
				 text16.setFillColor(Color::Red); 
				 count8=0;}
        }
        /////////////////////////////////////////////////////////////////////
        
            if (isText17Pressed) {
            text17.setPosition(event.mouseMove.x, event.mouseMove.y);
            
              if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 40 && event.mouseMove.y <= 300){
            	  text17.setFillColor(Color::Green);
       count9=1;
			}
			else {
				
				 text17.setFillColor(Color::Red);
				 count9=0; }
        }
        ///////////////////////////////////////////////////////////////////////
            if (isText18Pressed) {
            text18.setPosition(event.mouseMove.x, event.mouseMove.y);
            
             if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 301&& event.mouseMove.y <= 550){
            	  text18.setFillColor(Color::Green);
       count10=1;
			}
			else {
				
				 text18.setFillColor(Color::Red); 
				 count10=0;}
        }
        /////////////////////////////////////////////////////
            if (isText19Pressed) {
            text19.setPosition(event.mouseMove.x, event.mouseMove.y);
            
              if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 551 && event.mouseMove.y <= 750){
            	  text19.setFillColor(Color::Green);
       count11=1;
			}
			else {
				
				 text19.setFillColor(Color::Red); 
				 count11=0;}
        }
        ///////////////////////////////////////////////////////////////////////////////
            if (isText20Pressed) {
            text20.setPosition(event.mouseMove.x, event.mouseMove.y);
            
              if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 301&& event.mouseMove.y <= 550){
            	  text20.setFillColor(Color::Green);
       count12=1;
			}
			else {
				
				 text20.setFillColor(Color::Red); 
				 count12=0;}
        }
        ///////////////////////////////////////////////////
            if (isText21Pressed) {
            text21.setPosition(event.mouseMove.x, event.mouseMove.y);
            
            if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 40 && event.mouseMove.y <= 300){
            	  text21.setFillColor(Color::Green);
       count13=1;
			}
			else {
				
				 text21.setFillColor(Color::Red);
				 count13=0; }
            
        }
        ///////////////////////////////////////////////////////////
            if (isText22Pressed) {
            text22.setPosition(event.mouseMove.x, event.mouseMove.y);
            
              if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 301&& event.mouseMove.y <= 550){
            	  text22.setFillColor(Color::Green);
       count14=1;
			}
			else {
				
				 text22.setFillColor(Color::Red); 
				 count14=0;}
        }
        /////////////////////////////////////////////////////////////
            if (isText23Pressed) {
            text23.setPosition(event.mouseMove.x, event.mouseMove.y);
            
             if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 40 && event.mouseMove.y <= 300){
            	  text23.setFillColor(Color::Green);
       count15=1;
			}
			else {
				
				 text23.setFillColor(Color::Red); 
				 count15=0;}
        }
        ///////////////////////////////////////////////////////////////////////////
               if (isText24Pressed) {
            text24.setPosition(event.mouseMove.x, event.mouseMove.y);
            
            if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 551 && event.mouseMove.y <= 750){
            	  text24.setFillColor(Color::Green);
       count16=1;
			}
			else {
				
				 text24.setFillColor(Color::Red);
				 count16=0; }
        }
        //////////////////////////////////////////////////////////////////////
               if (isText25Pressed) {
            text25.setPosition(event.mouseMove.x, event.mouseMove.y);
            
             if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 301&& event.mouseMove.y <= 550){
            	  text25.setFillColor(Color::Green);
       count17=1;
			}
			else {
				
				 text25.setFillColor(Color::Red); 
				 count17=0;}
        }
        ////////////////////////////////////////////////////////////////
               if (isText26Pressed) {
            text26.setPosition(event.mouseMove.x, event.mouseMove.y);
            
              
            if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 40 && event.mouseMove.y <= 300){
            	  text26.setFillColor(Color::Green);
       count18=1;
			}
			else {
				
				 text26.setFillColor(Color::Red);
				 count18=0; }
        }
        ///////////////////////////////////////////////////////////////////////////
               if (isText27Pressed) {
            text27.setPosition(event.mouseMove.x, event.mouseMove.y);
            
            if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 551 && event.mouseMove.y <= 750){
            	  text27.setFillColor(Color::Green);
       count19=1;
			}
			else {
				
				 text27.setFillColor(Color::Red);
				 count19=0; }
        }
        //////////////////////////////////////////////////////////////////////////////////////
               if (isText28Pressed) {
            text28.setPosition(event.mouseMove.x, event.mouseMove.y);
            
            if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 40 && event.mouseMove.y <= 300){
            	  text28.setFillColor(Color::Green);
       count20=1;
			}
			else {
				
				 text28.setFillColor(Color::Red); 
				 count20=0;}
        }
        ////////////////////////////////////////////////////////////////////////////
              if (isText31Pressed) {
            text31.setPosition(event.mouseMove.x, event.mouseMove.y);
            
            if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 40 && event.mouseMove.y <= 300){
            	  text31.setFillColor(Color::Green);
       count21=1;
			}
			else {
				
				 text31.setFillColor(Color::Red); 
				 count21=0;}
        }
        //////////////////////////////////////////////////////////////////////////////////////
         if (isText32Pressed) {
            text32.setPosition(event.mouseMove.x, event.mouseMove.y);
            
            if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 40 && event.mouseMove.y <= 300){
            	  text32.setFillColor(Color::Green);
       count22=1;
			}
			else {
				
				 text32.setFillColor(Color::Red); 
				 count22=0;}
        }
        ///////////////////////////////////////////////////////////////////////////////////
         if (isText33Pressed) {
            text33.setPosition(event.mouseMove.x, event.mouseMove.y);
            
            if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 551 && event.mouseMove.y <= 750){
            	  text33.setFillColor(Color::Green);
       count23=1;
			}
			else {
				
				 text33.setFillColor(Color::Red); 
				 count23=0;}
        }
    //////////////////////////////////////////////////////////////////////////////////
           if (isText34Pressed) {
            text34.setPosition(event.mouseMove.x, event.mouseMove.y);
            
            if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 551 && event.mouseMove.y <= 750){
            	  text34.setFillColor(Color::Green);
       count24=1;
			}
			else {
				
				 text34.setFillColor(Color::Red); 
				 count24=0;}
        }
        
           if (isText35Pressed) {
            text35.setPosition(event.mouseMove.x, event.mouseMove.y);
            
            if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 551 && event.mouseMove.y <= 750){
            	  text35.setFillColor(Color::Green);
       count25=1;
			}
			else {
				
				 text35.setFillColor(Color::Red); 
				 count25=0;}
        }
           if (isText36Pressed) {
            text36.setPosition(event.mouseMove.x, event.mouseMove.y);
            
            if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 551 && event.mouseMove.y <= 750){
            	  text36.setFillColor(Color::Green);
       count26=1;
			}
			else {
				
				 text36.setFillColor(Color::Red); 
				 count26=0;}
        }
        
        
        ////////////////////////////////////////////////////////////
    	}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	 exitWin.setPosition(x,y);
// подсчёт очков
		
	   if(x==0 && y==0){
        	count27=1;
		}
	else {
		count27=0;
	}

	
	
              
              
              
            	if (Keyboard::isKeyPressed(Keyboard::Escape)) { 
		          
		} 
		// while(a<1){
        	 
		
		//	window.clear();

        // Отрисовка спрайта
       	//	 window.draw(sprite);
        // Отображение изменений на экране
       	//	window.display();
        sprite.setScale(sf::Vector2f(screenWidth / sprite.getLocalBounds().width, screenHeight / sprite.getLocalBounds().height));
		
		// Открисовка картинок при нажатие на пробел
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    if (currentImage == 1)
                    {
                    	
                        sprite.setTexture(image2);
                    
                 
                        currentImage = 2;
                    }
                    else if (currentImage == 2)
                    {
                        sprite.setTexture(image3);
                       	
                        currentImage = 3;
                    }
                    else if (currentImage == 3)
                    {
                        sprite.setTexture(image4);
                      
                        currentImage = 4;
                    }
                    else if (currentImage == 4){
                    	sprite.setTexture(image5);
                    	
                    	currentImage = 5;
					}
					 else if (currentImage == 5){
                    	sprite.setTexture(image6);
                    	
                    currentImage = 6;
                  
					}	
                }
            }
            // конец карнтинок 
        }
 		sprite.setScale(sf::Vector2f(screenWidth / sprite.getLocalBounds().width, screenHeight / sprite.getLocalBounds().height));
        window.clear();
        window.draw(sprite);
  
       	// Таймер 
			Time1=(int)clock.getElapsedTime().asSeconds() % 60; // получение значение секунд в переменную int
			Time2=(int)clock.getElapsedTime().asSeconds() / 60;	// минуты
		    stringstream ss; // поток
		    stringstream mn; // поток
			ss << Time1; // поток конвертация int  в string
			mn << Time2; // поток конвертация int  в string
			string str = ss.str(); // запись
    		Text text9(str,font,15) ;
    		text9.setFillColor(Color::Red);
   			text9.setPosition(670,15);
   			
   			Text text11(":",font,15);
   			text11.setFillColor(Color::Red);
   			text11.setPosition(660,15);
   			
   			string str1 = mn.str();
   			Text text10(str1,font,15) ;
    		text10.setFillColor(Color::Red);
   			text10.setPosition(650,15);
        
        // Отрисовка линий
        if (currentImage ==6){
        	
        Vertex line[] =
    {
        Vertex(Vector2f(10, 20),Color::Black), // P1
        Vertex(Vector2f(10, 750),Color::Black)  // P2
    };
   
   
        Vertex line1[] =
    {
        Vertex(Vector2f(10, 20),Color::Black), // P1
        Vertex(Vector2f(600, 20),Color::Black)  // P2
    };
     
	 Vertex line2[] =
    {
        Vertex(Vector2f(600, 20),Color::Black), // P1
        Vertex(Vector2f(600, 750),Color::Black)  // P2
    };
   
   	 Vertex line3[] =
    {
        Vertex(Vector2f(10, 750),Color::Black), // P1
        Vertex(Vector2f(600, 750),Color::Black)  // P2
    };
   
   Vertex line4[] =
    {
        Vertex(Vector2f(150, 20),Color::Black), // P1
        Vertex(Vector2f(150, 750),Color::Black)  // P2
    };
  
    
   

     Vertex line5[] =
    {
    
        Vertex(Vector2f(10, 60),Color::Black), // P1
        Vertex(Vector2f(600, 60),Color::Black)  // P2
      
    };
    
     Vertex line6[] =
    {
    
        Vertex(Vector2f(10, 310),Color::Black), // P1
        Vertex(Vector2f(600,310),Color::Black)  // P2
      
    };
       Vertex line7[] =
    {
    
        Vertex(Vector2f(10, 560),Color::Black), // P1
        Vertex(Vector2f(600,560),Color::Black)  // P2
      
    };
 
   
      			window.draw(line, 2, Lines);
      			window.draw(line1, 2,Lines);
      			window.draw(line2, 2,Lines);
      			window.draw(line3, 2,Lines);
      			window.draw(line4, 2,Lines);
      			window.draw(line5, 2,Lines);
      			window.draw(line6, 2,Lines);
      			window.draw(line7, 2,Lines);
      			window.draw(text);
      			window.draw(text1);
      			window.draw(text2);
      			window.draw(text3);
      			window.draw(text4);
      			window.draw(text5);
      			window.draw(text6);
      			window.draw(text7);
      			window.draw(text8);
      			window.draw(rectangle);
      			window.draw(rectangle1);
      			window.draw(rectangle2);
      			
      			
      			// очистка таймера на 1 шаге
      			if(prov==2){
      				text9.setString("");text10.setString("");text11.setString("");
				  }
      			
      			
      			window.draw(text9);		window.draw(text10);    window.draw(text11);    window.draw(text12);
      			window.draw(text13); 	window.draw(text14); 	window.draw(text15); 	window.draw(text16); 	window.draw(text17); 	window.draw(text18);
      			window.draw(text19);   	window.draw(text20);  	window.draw(text21); 	window.draw(text21); 	window.draw(text22); 	window.draw(text23);
      			window.draw(text24);    window.draw(text25);    window.draw(text26);    window.draw(text26);    window.draw(text27);    window.draw(text28);
      			window.draw(text29);    window.draw(text30);
      	}
      			 int sum =count22+count23+count24+count25+count26+count21+ count1 + count2 +count3 +count4 +count5 +count6 +count7 +count8 +count9 +count10 +count11 +count12 +count13+count14+count15+count16+count17+count18+count19 + count20+count27;
		
	
		
                   cout<<sum<<endl;
        // вывод оставшихся 6 вариантов 
      			 	if(sum>=21){
		             window.draw(text31);  window.draw(text32);  window.draw(text33);  window.draw(text34);  window.draw(text35);  window.draw(text36);
	             
	}
	// Отображение окна после выставление всех слов в таблице 1 шага
            if(sum==27){
           okno.setScale(0.4,0.4);
           okno.setPosition(250,200);
		   window.draw(okno);
           window.draw(rectangle3);
           window.draw(rectangle4);
		   window.draw(rectangle5);
		   window.draw(text37);   window.draw(text38);	
		 

   // Отключение движения текста при полном заполнение
    isText8Pressed = false;	    isText6Pressed = false;    isText7Pressed = false;    isText34Pressed = false;  isText27Pressed = false; isText28Pressed = false; 
    isText12Pressed = false;    isText13Pressed = false;   isText14Pressed = false;   isText15Pressed = false;  isText31Pressed = false; 
    isText16Pressed = false;    isText17Pressed = false;   isText18Pressed = false;   isText19Pressed = false;  isText32Pressed = false; 
    isText20Pressed = false;    isText21Pressed = false;   isText22Pressed = false;   isText23Pressed = false;  isText33Pressed = false;  
    isText24Pressed = false;	isText25Pressed = false;   isText26Pressed = false;   isText36Pressed = false;  isText35Pressed = false;
		   
}
	// Нажатие кнопки (нет) в окне оповещения при проходе первого шага
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
	
	if (rectangle5.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
				goto start;	}
				}
				
	// переход на шаг 2 по кнопке "Да"
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
	
	if (rectangle4.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
				goto step2;	}
				}
			
		// переход на шаг 1 по кнопке шаг-1	
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
	
	if (rectangle.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
				goto start;	}
				}	
		// проверка на 2 шаге по нажатию кнопки		
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
	
	if (rectangle6.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
 		
		sum1 = point+point1+point2+point3+point4+point5+point6+point7+point8+point9+point10+point11+point12+point13+point14+point15+point16+point17+point18+point19+ point20+point21+point22+point23+point24+point25;
		 chek=sum1;
		 chek1=sum1;
		 
	
			}
				}	
					
				
// Нажатие на квадрат-кнопку (2 шаг)!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
	
	if (rectangle1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                    
  
                    
                       if(prov==1) {// Действие при нажатии на квадрат
                       // очистка содержимого текста 1 шага
                   step2:
                   	
    text39.setString("Соблюдать правила ведения диалога");
    text39.setFillColor(Color::Black);
    text39.setPosition(620,50);
    
    text40.setString("Проводить изменения звуковой модели по \nпредложенному учителем правилу") ;
    text40.setFillColor(Color::Black);
    text40.setPosition(620,70);
    
    text41.setString("Подбирать слова к модели") ;
    text41.setFillColor(Color::Black);
    text41.setPosition(620,110);
    
    text42.setString("Характеризовать звуки по заданным признакам") ;
    text42.setFillColor(Color::Black);
    text42.setPosition(620,150);
 
    text43.setString("Отвечать на вопросы по изученному материалу") ;
    text43.setFillColor(Color::Black);
    text43.setPosition(620,190);
    
    text44.setString("Оценивать правильность выполненного задания") ;
    text44.setFillColor(Color::Black);
    text44.setPosition(620,230);
    
     text45.setString("Сравнивать звуки, звуковой и буквенный \nсостав слова в соответствии с учебной задачей") ;
    text45.setFillColor(Color::Black);
    text45.setPosition(620,270);
    
     text46.setString("Воспринимать суждения") ;
    text46.setFillColor(Color::Black);
    text46.setPosition(620,310);
    
     text47.setString("Устанавливать основания для сравнения звуков, \nслов(на основе образца)") ;
    text47.setFillColor(Color::Black);
    text47.setPosition(620,340);
    
    text48.setString("Строить устное речевое высказывание") ;
    text48.setFillColor(Color::Black);
    text48.setPosition(620,390);
    
    text49.setString("Удерживать учебную задачу, поставленную учителем") ;
    text49.setFillColor(Color::Black);
    text49.setPosition(620,420);
    
     text50.setString("Воспринимать разные точки зрения в процессе учебного диалога") ;
    text50.setFillColor(Color::Black);
    text50.setPosition(620,460);
    
    text51.setString("Приводить примеры в соответствии с учебной задачей") ;
    text51.setFillColor(Color::Black);
    text51.setPosition(620,490);
    
    text52.setString("Выражать эмоции в соответствии с целями и \nусловиями общения в знакомой среде") ;
    text52.setFillColor(Color::Black);
    text52.setPosition(620,520);
    
     text53.setString("Формулировать выводы в соответствии с задачей") ;
    text53.setFillColor(Color::Black);
    text53.setPosition(620,560);
    
	text54.setString("Выстраивать последовательность учебных операций") ;
    text54.setFillColor(Color::Black);
    text54.setPosition(620,590);
    
     text55.setString("Проявлять уважительное отношение к собеседнику \nсоблюдать в процессе общения нормы речевого этикета") ;
    text55.setFillColor(Color::Black);
    text55.setPosition(620,630);
    
    text56.setString("Анализировать графическую информуцию - модели \nзвукового состава слова") ;
    text56.setFillColor(Color::Black);
    text56.setPosition(620,670);
    
    text57.setString("Находить указанную ошибку") ;
    text57.setFillColor(Color::Black);
    text57.setPosition(620,710);
     
    text58.setString("Самостоятельно создавать модели звукового состава слова") ;
    text58.setFillColor(Color::Black);
    text58.setPosition(620,730);
 
    
    text59.setString("Использовать алфавит для самосотоятельного \nупорядочивания списка слов");
    text59.setFillColor(Color::Black);
    text59.setPosition(620,50);
    
    text60.setString("Выбирать источник получения информации") ;
    text60.setFillColor(Color::Black);
    text60.setPosition(620,90);
    
    text61.setString("Ответственно выполнять свою часть работы") ;
    text61.setFillColor(Color::Black);
    text61.setPosition(620,120);
    
    text62.setString("Принимать цель совместной деятельности") ;
    text62.setFillColor(Color::Black);
    text62.setPosition(620,150);
 
    text63.setString("Распределять роли, договариваться, учитывать интересы и мнения") ;
    text63.setFillColor(Color::Black);
    text63.setPosition(620,180);
    
    text64.setString("Коллективно строить план действия по достижению цели") ;
    text64.setFillColor(Color::Black);
    text64.setPosition(620,210);
                   	
                       text6.setString(""); text7.setString(""); text8.setString("");text12.setString("");text13.setString("");text14.setString(""); text15.setString("");text16.setString("");text17.setString("");
                       text18.setString(""); text19.setString(""); text20.setString("");text21.setString("");text22.setString("");text23.setString("");text24.setString("");text25.setString("");text26.setString("");
						text27.setString("");text28.setString("");text31.setString("");text32.setString("");text33.setString("");text34.setString("");text35.setString("");text36.setString("");
		sum1=0;
				// Обнуление значения Clock
						clock.restart();
						prov=2;
						text39.setPosition(620,50);text41.setPosition(620,110);text42.setPosition(620,150); text43.setPosition(620,190);text44.setPosition(620,230);
                        text45.setPosition(620,270);text46.setPosition(620,310); text47.setPosition(620,340);text48.setPosition(620,390); text49.setPosition(620,420);
						text50.setPosition(620,460);text51.setPosition(620,490);text52.setPosition(620,520);text53.setPosition(620,560);text54.setPosition(620,590);text55.setPosition(620,630);
   						text56.setPosition(620,670);text57.setPosition(620,710);text58.setPosition(620,730);text59.setPosition(620,50);text60.setPosition(620,90);text61.setPosition(620,120);
    					text62.setPosition(620,150);text63.setPosition(620,180);text64.setPosition(620,210);  text40.setPosition(620,70); 
			x=10; y=5;
						}
                       }
	
}
// отображение текста 2 шага
   if (prov==2){
   	
   					   window.draw(text39);window.draw(text40);window.draw(text41);window.draw(text42);window.draw(text43);window.draw(text44);window.draw(text45);window.draw(text46);window.draw(text47);
					   window.draw(text48);window.draw(text49);window.draw(text50);window.draw(text51);window.draw(text52);window.draw(text53);window.draw(text54);window.draw(text55);window.draw(text56);
					   window.draw(text57);window.draw(text58); window.draw(rectangle6); window.draw(proverka);
				// Таймер	
		
			
			Time3=59-((int)clock.getElapsedTime().asSeconds() % 60); // получение значение секунд в переменную int
			Time4=4-((int)clock.getElapsedTime().asSeconds() / 60);	// минуты
		
			int min=Time4, sec=Time3;
		    stringstream ss1; // поток
		    stringstream mn1; // поток
			ss1 << Time3; // поток конвертация int  в string
			mn1 << Time4; // поток конвертация int  в string
			string str3 = ss1.str(); // запись
    		Text text67(str3,font,15) ;
    		text67.setFillColor(Color::Red);
   			text67.setPosition(670,15);
   			
   			Text text68(":",font,15);
   			text68.setFillColor(Color::Red);
   			text68.setPosition(660,15);
   			
   			string str4 = mn1.str();
   			Text text69(str4,font,15) ;
    		text69.setFillColor(Color::Red);
   			text69.setPosition(650,15);
   			
   			// обнуление таймера 
   			if(min<=-1 && sec<= 59){
   			text67.setString("0");text69.setString("0");
   			window.draw(text67);
   			window.draw(text68);
   			window.draw(text69);
   			goto TimeLimit;
   		
			}
		   
   			window.draw(text67);
   			window.draw(text68);
   			window.draw(text69);
   			// Отображение 6 последних слов
			
			if (sum1>=20){
					   	
			window.draw(text59);window.draw(text60);window.draw(text61);window.draw(text62);window.draw(text63);window.draw(text64);
					   	
					   }
					   
   	
   }

		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        // Проверка, была ли нажата левая кнопка мыши 
        
          	if (text39.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
           	 isText39Pressed = true; }
            
        // Проверка, была ли нажата левая кнопка мыши на text7
       	 else if (text40.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText40Pressed = true;}
            // Проверка, была ли нажата левая кнопка мыши на text7
       	 else if (text41.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText41Pressed = true;}
            
             else if (text42.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText42Pressed = true;}
            
             else if (text43.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText43Pressed = true;}
            
             else if (text44.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText44Pressed = true;}
            
             else if (text45.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText45Pressed = true;}
            
             else if (text46.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText46Pressed = true;}
            
             else if (text47.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText47Pressed = true;}
            
             else if (text48.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText48Pressed = true;}
            
             else if (text49.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText49Pressed = true;}
            
             else if (text50.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText50Pressed = true;}
            
             else if (text51.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText51Pressed = true;}
            
             else if (text52.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText52Pressed = true;}
            
             else if (text53.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText53Pressed = true;}
            
            else if (text54.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText54Pressed = true;}
            
            else if (text55.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText55Pressed = true;}
            
            else if (text56.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText56Pressed = true;}
            
            else if (text57.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText57Pressed = true;}
            
            else if (text58.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText58Pressed = true;}
            
            else if (text59.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText59Pressed = true;}
        	
        	else if (text60.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText60Pressed = true;}
            
             else if (text61.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText61Pressed = true;}
            
             else if (text62.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText62Pressed = true;}
            
             else if (text63.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText63Pressed = true;}
            
             else if (text64.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            isText64Pressed = true;}
        
            //////Нажатие на кнопку
                 
    	} 
    /////////////////////////////
    // Проверка отпускания левой кнопки мыши
    	else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
        // Проверка, была ли отпущена левая кнопка мыши на text6
      	  if (isText39Pressed) {
            isText39Pressed = false;
        
        }
        // Проверка, была ли отпущена левая кнопка мыши на text7
       	 else if (isText40Pressed) {
            isText40Pressed = false;
      	  }
      	  
      	   else if (isText41Pressed) {
            isText41Pressed = false;
      	  }
      	  
      	     else if (isText42Pressed) {
            isText42Pressed = false;
      	  }
      	     else if (isText43Pressed) {
            isText43Pressed = false;
      	  }
      	     else if (isText44Pressed) {
            isText44Pressed = false;
      	  }
      	     else if (isText45Pressed) {
            isText45Pressed = false;
      	  }
      	     else if (isText46Pressed) {
            isText46Pressed = false;
      	  }
      	     else if (isText47Pressed) {
            isText47Pressed = false;
      	  }
      	     else if (isText48Pressed) {
            isText48Pressed = false;
      	  }
      	     else if (isText49Pressed) {
            isText49Pressed = false;
      	  }
      	     else if (isText50Pressed) {
            isText50Pressed = false;
      	  }
      	     else if (isText51Pressed) {
            isText51Pressed = false;
      	  }
      	     else if (isText52Pressed) {
            isText52Pressed = false;
      	  }
      	     else if (isText53Pressed) {
            isText53Pressed = false;
      	  }
      	  
      	      else if (isText54Pressed) {
            isText54Pressed = false;
      	  }
      	  
      	      else if (isText55Pressed) {
            isText55Pressed = false;
      	  }
      	  
      	      else if (isText56Pressed) {
            isText56Pressed = false;
      	  }
      	  
      	      else if (isText57Pressed) {
            isText57Pressed = false;
      	  }
      	  
      	      else if (isText58Pressed) {
            isText58Pressed = false;
      	  }
      	  
      	     else if (isText59Pressed) {
            isText59Pressed = false;
      	  }
      	     else if (isText60Pressed) {
            isText60Pressed = false;
      	  }
      	     else if (isText61Pressed) {
            isText61Pressed = false;
      	  }
      	     else if (isText62Pressed) {
            isText62Pressed = false;
      	  }
      	     else if (isText63Pressed) {
            isText63Pressed = false;
      	  }
      	     else if (isText64Pressed) {
            isText64Pressed = false;
      	  }
   		 } 
    // Проверка передвижения мыши
   		 else if (event.type == sf::Event::MouseMoved) {
        // Передвижение text6 при удерживании левой кнопки мыши на нем
   
        
        if (isText39Pressed) {
            text39.setPosition(event.mouseMove.x, event.mouseMove.y);
            
            if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 301&& event.mouseMove.y <= 550){
            	  //text6.setFillColor(Color::Green);
            	  point=1; 
            	  
            position=1;
    
			}
			else {
				
				 //text6.setFillColor(Color::Black); 
				 point=0;
				 position=1;
				}
        }
        //////////////////////////////////////////////////////////////////////
          if (isText40Pressed) {
            text40.setPosition(event.mouseMove.x, event.mouseMove.y);
            
            if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 40 && event.mouseMove.y <= 300){
            	  //text7.setFillColor(Color::Green);
            	  point1=1;
     				position1=1;
			}
			else {
				
				 //text7.setFillColor(Color::Black);
				 point1=0; position1=1;
				}
        }
        ///////////////////////////////////////////////////////////////////
        // Передвижение text7 при удерживании левой кнопки мыши на нем
        if (isText41Pressed) {
            text41.setPosition(event.mouseMove.x, event.mouseMove.y);
            
            // проверка правильности растановки ответов 
            if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 40 && event.mouseMove.y <= 300){
            	  //text8.setFillColor(Color::Green);
            	  point2=1;position2=1;
                       
			}
			else {
				
				 //text8.setFillColor(Color::Black); 
				 point2=0;position2=1;
				}
        }
        //////////////////////////////////////////////
            if (isText42Pressed) {
            text42.setPosition(event.mouseMove.x, event.mouseMove.y);
            
              if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 40 && event.mouseMove.y <= 300){
            //	  text12.setFillColor(Color::Green);
            point3=1;position3=1;
      
			}
			else {
				
			//	 text12.setFillColor(Color::Black); 
			 point3=0;position3=1;
				 }
            
        }
        ////////////////////////////////////////////////////////////////////////////
        
            if (isText43Pressed) {
            text43.setPosition(event.mouseMove.x, event.mouseMove.y);
            
              if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 301&& event.mouseMove.y <= 550){
            	 // text13.setFillColor(Color::Green);
            	  point4=1;position4=1;
      
			}
			else {
				 point4=0;position4=1;
				 //text13.setFillColor(Color::Black); 
				 }
        }
        //////////////////////////////////////////////////////////////////////////
            if (isText44Pressed) {
            text44.setPosition(event.mouseMove.x, event.mouseMove.y);
            
              if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 551 && event.mouseMove.y <= 750){
            	  //text44.setFillColor(Color::Green);
            	   point5=1;position5=1;
      
			}
			else {
				 point5=0;position5=1;
				 //text14.setFillColor(Color::Black); 
				 }
        }
        ///////////////////////////////////////////////////////
            if (isText45Pressed) {
            text45.setPosition(event.mouseMove.x, event.mouseMove.y);
            
            if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 40 && event.mouseMove.y <= 300){
            	  //text45.setFillColor(Color::Green);
            	   point6=1;position6=1;
      
			}
			else {
				
				 point6=0;position6=1;
				 //text15.setFillColor(Color::Black); 
				 }
        }
        ////////////////////////////////////////////////////////////////
            if (isText46Pressed) {
            text46.setPosition(event.mouseMove.x, event.mouseMove.y);
            
                 if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 301&& event.mouseMove.y <= 550){
            	  //text16.setFillColor(Color::Green);
            	   point7=1;position7=1;
      
			}
			else {
				 point7=0;position7=1;
				 //text16.setFillColor(Color::Black); 
				}
        }
        /////////////////////////////////////////////////////////////////////
        
            if (isText47Pressed) {
            text47.setPosition(event.mouseMove.x, event.mouseMove.y);
            
              if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 40 && event.mouseMove.y <= 300){
            	 // text17.setFillColor(Color::Green);
            	  point8=1;position8=1;
       
			}
			else {
				 point8=0;position8=1;
				 //text17.setFillColor(Color::Black);
				 }
        }
        ///////////////////////////////////////////////////////////////////////
            if (isText48Pressed) {
            text48.setPosition(event.mouseMove.x, event.mouseMove.y);
            
             if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 301&& event.mouseMove.y <= 550){
            	 // text18.setFillColor(Color::Green);
            	  point9=1;position9=1;
    
			}
			else {
				 point9=0;position9=1;
				 //text18.setFillColor(Color::Black); 
				 }
        }
        /////////////////////////////////////////////////////
            if (isText49Pressed) {
            text49.setPosition(event.mouseMove.x, event.mouseMove.y);
            
              if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 551 && event.mouseMove.y <= 750){
            	 // text19.setFillColor(Color::Green);
            	  point10=1;position10=1;
     
			}
			else {
				 point10=0;position10=1;
				 //text19.setFillColor(Color::Black); 
				}
        }
        ///////////////////////////////////////////////////////////////////////////////
            if (isText50Pressed) {
            text50.setPosition(event.mouseMove.x, event.mouseMove.y);
            
              if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 301&& event.mouseMove.y <= 550){
            	//  text20.setFillColor(Color::Green);
            	 point11=1;position11=1;
      
			}
			else {
				 point11=0;position11=1;
				 //text20.setFillColor(Color::Black); 
				}
        }
        ///////////////////////////////////////////////////
            if (isText51Pressed) {
            text51.setPosition(event.mouseMove.x, event.mouseMove.y);
            
            if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 40 && event.mouseMove.y <= 300){
            	 // text21.setFillColor(Color::Green);
            	  point12=1;position12=1;
      
			}
			else {
				 point12=0;position12=1;
				// text21.setFillColor(Color::Black);
				 }
            
        }
        ///////////////////////////////////////////////////////////
            if (isText52Pressed) {
            text52.setPosition(event.mouseMove.x, event.mouseMove.y);
            
              if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 301&& event.mouseMove.y <= 550){
            	 // text22.setFillColor(Color::Green);
            	  point13=1;position13=1;
      
			}
			else {
				 point13=0;position13=1;
				 //text22.setFillColor(Color::Black); 
				}
        }
        /////////////////////////////////////////////////////////////
            if (isText53Pressed) {
            text53.setPosition(event.mouseMove.x, event.mouseMove.y);
            
             if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 40 && event.mouseMove.y <= 300){
            	 // text23.setFillColor(Color::Green);
            	  point14=1;position14=1;
      
			}
			else {
				 point14=0;position14=1;
				 //text23.setFillColor(Color::Black); 
				}
        }
        ///////////////////////////////////////////////////////////////////////////
               if (isText54Pressed) {
            text54.setPosition(event.mouseMove.x, event.mouseMove.y);
            
            if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 551 && event.mouseMove.y <= 750){
            //	  text24.setFillColor(Color::Green);
             point15=1;position15=1;
      
			}
			else {
				 point15=0;position15=1;
			//	 text24.setFillColor(Color::Black);
				  }
        }
        //////////////////////////////////////////////////////////////////////
               if (isText55Pressed) {
            text55.setPosition(event.mouseMove.x, event.mouseMove.y);
            
             if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 301&& event.mouseMove.y <= 550){
            	//  text25.setFillColor(Color::Green);
            	 point16=1;position16=1;
      
			}
			else {
				 point16=0;position16=1;
				 //text25.setFillColor(Color::Black); 
				 }
        }
        ////////////////////////////////////////////////////////////////
               if (isText56Pressed) {
            text56.setPosition(event.mouseMove.x, event.mouseMove.y);
            
              
            if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 40 && event.mouseMove.y <= 300){
            	 // text26.setFillColor(Color::Green);
            	  point17=1;position17=1;
     
			}
			else {
				 point17=0;position17=1;
				 //text26.setFillColor(Color::Black);
				 }
        }
        ///////////////////////////////////////////////////////////////////////////
               if (isText57Pressed) {
            text57.setPosition(event.mouseMove.x, event.mouseMove.y);
            
            if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 551 && event.mouseMove.y <= 750){
            	 // text27.setFillColor(Color::Green);
            	  point18=1;position18=1;
    
			}
			else {
				 point18=0;position18=1;
				 //text27.setFillColor(Color::Black);
				 }
        }
        //////////////////////////////////////////////////////////////////////////////////////
               if (isText58Pressed) {
            text58.setPosition(event.mouseMove.x, event.mouseMove.y);
            
            if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 40 && event.mouseMove.y <= 300){
            	 // text28.setFillColor(Color::Green);
            	  point19=1;position19=1;
     
			}
			else {
				 point19=0;position19=1;
				 //text28.setFillColor(Color::Black); 
			}
        }
        ////////////////////////////////////////////////////////////////////////////
              if (isText59Pressed) {
            text59.setPosition(event.mouseMove.x, event.mouseMove.y);
            
            if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 40 && event.mouseMove.y <= 300){
            	  //text31.setFillColor(Color::Green);
            	   point20=1;
    
			}
			else {
				 point20=0;
				 //text31.setFillColor(Color::Black); 
				}
        }
        //////////////////////////////////////////////////////////////////////////////////////
         if (isText60Pressed) {
            text60.setPosition(event.mouseMove.x, event.mouseMove.y);
            
            if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 40 && event.mouseMove.y <= 300){
            	 // text32.setFillColor(Color::Green);
            	  point21=1;
      
			}
			else {
				 point21=0;
				 //text32.setFillColor(Color::Black); 
				 }
        }
        ///////////////////////////////////////////////////////////////////////////////////
         if (isText61Pressed) {
            text61.setPosition(event.mouseMove.x, event.mouseMove.y);
            
            if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 551 && event.mouseMove.y <= 750){
           // 	  text33.setFillColor(Color::Green);
            point22=1;
      
			}
			else {
				 point22=0;
			//	 text33.setFillColor(Color::Black); 
				 }
        }
    //////////////////////////////////////////////////////////////////////////////////
           if (isText62Pressed) {
            text62.setPosition(event.mouseMove.x, event.mouseMove.y);
            
            if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 551 && event.mouseMove.y <= 750){
            	  //text34.setFillColor(Color::Green);
            	   point23=1;
      
			}
			else {
				 point23=0;
				 //text34.setFillColor(Color::Black); 
				}
        }
        
           if (isText63Pressed) {
            text63.setPosition(event.mouseMove.x, event.mouseMove.y);
            
            if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 551 && event.mouseMove.y <= 750){
            	 // text35.setFillColor(Color::Green);
            	  point24=1;
     
			}
			else {
				 point24=0;
				 //text35.setFillColor(Color::Black); 		
				 }
        }
           if (isText64Pressed) {
            text64.setPosition(event.mouseMove.x, event.mouseMove.y);
            
            if(event.mouseMove.x >= 150 && event.mouseMove.x <= 600 && event.mouseMove.y >= 551 && event.mouseMove.y <= 750){
            	  //text36.setFillColor(Color::Green);
            	   point25=1;
     
			}
			else {
				 point25=0;
				 //text36.setFillColor(Color::Black); 
				 }
        }
     
   
sum1 = position+position1+position2+position3+position4+position5+position6+position7+position8+position9+position10+position11+position12+position13+position14+position15+position16+position17+position18+position19;
cout<<"SUM1:"<<sum1<< endl;
      		//	window.draw(line8, 2,Lines);
      	
      	
      	// если правильных меньше 75% 
      	if(chek<=19.5){
      TimeLimit:
	  	sum1 = point+point1+point2+point3+point4+point5+point6+point7+point8+point9+point10+point11+point12+point13+point14+point15+point16+point17+point18+point19+ point20+point21+point22+point23+point24+point25;
		 chek=sum1;		
		okno1.setScale(0.4,0.4);
        okno1.setPosition(250,200);
		window.draw(okno1);	
		window.draw(rectangle3);
		//rectangle5.setPosition()	
		window.draw(rectangle5);
		text38.setString("ОK");
		window.draw(text38);
		window.draw(text65);
		stringstream po; // поток
		po << chek; // поток конвертация int  в string
		string str2 = po.str(); // запись
    	Text text66(str2,font,15);
    	text66.setFillColor(Color::Red);
   		text66.setPosition(350,400);
    	window.draw(text66);
	Time elapsedTime = clock.getElapsedTime();	
	isText40Pressed = false; 	 isText41Pressed = false;	 isText42Pressed = false;	isText43Pressed = false; isText44Pressed = false; isText45Pressed = false;
    isText46Pressed = false;	 isText47Pressed = false;    isText48Pressed = false;   isText49Pressed = false; isText50Pressed = false; isText51Pressed = false;
    isText52Pressed = false;	 isText53Pressed = false;	 isText54Pressed = false;   isText55Pressed = false; isText64Pressed = false; isText56Pressed = false; isText39Pressed = false;
    isText57Pressed = false;	 isText58Pressed = false;   isText59Pressed = false;    isText60Pressed = false; isText61Pressed = false; isText62Pressed = false; isText63Pressed = false;
				}
				
		if(chek1>19.5){
	  	sum1 = point+point1+point2+point3+point4+point5+point6+point7+point8+point9+point10+point11+point12+point13+point14+point15+point16+point17+point18+point19+ point20+point21+point22+point23+point24+point25;
		chek1=sum1;		
		okno2.setScale(0.4,0.4);
        okno2.setPosition(250,200);
		window.draw(okno2);	
		rectangle3.setPosition(250,360);
		window.draw(rectangle3);
		//rectangle5.setPosition()	
		window.draw(rectangle5);
		text38.setString("ОK");
		window.draw(text38);
		window.draw(text65);
		stringstream po; // поток
		po << chek; // поток конвертация int  в string
		string str2 = po.str(); // запись
    	Text text66(str2,font,15);
    	text66.setFillColor(Color::Red);
   		text66.setPosition(350,400);
    	window.draw(text66);
	Time elapsedTime = clock.getElapsedTime();	
	isText40Pressed = false; 	 isText41Pressed = false;	 isText42Pressed = false;	isText43Pressed = false; isText44Pressed = false; isText45Pressed = false;
    isText46Pressed = false;	 isText47Pressed = false;    isText48Pressed = false;   isText49Pressed = false; isText50Pressed = false; isText51Pressed = false;
    isText52Pressed = false;	 isText53Pressed = false;	 isText54Pressed = false;   isText55Pressed = false; isText64Pressed = false; isText56Pressed = false; isText39Pressed = false;
    isText57Pressed = false;	 isText58Pressed = false;   isText59Pressed = false;    isText60Pressed = false; isText61Pressed = false; isText62Pressed = false; isText63Pressed = false;
			
		
				}

		}
		
		
        window.display();
                    	
		if (Keyboard::isKeyPressed(Keyboard::Escape)) { 
		       break;
		} 


	}


}
