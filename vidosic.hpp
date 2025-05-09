#include <SFML/Graphics.hpp>
#include <iostream>
#include<locale>
#include<sstream>
#include<string>
#include<windows.h>  
using namespace std;
using namespace sf;

void loadTextures(sf::Texture* textures, int numTextures,string strF) {
    for (int i = 0; i < numTextures; i++) {
        stringstream ss;
        string str;
        ss << i+1;
        ss >> str;
        if (i <= 10) {
            str =strF + "_000" + str + ".jpg";
        } else if(i < 100) {
            str =strF +  "_00" + str + ".jpg";
        }else if(i < 1000) {
        str =strF +  "_0" + str + ".jpg";	
        }else{
        str =strF +  "_" + str + ".jpg";	
		}

        textures[i].loadFromFile(str);
    }
    cout <<"!!!"<<endl;
}
void upAttack(Texture* textures,sf::Sprite& sprite, int& currentTextureIndex, int numTextures) {
    currentTextureIndex++;
    if (currentTextureIndex >= numTextures) {
        currentTextureIndex = 0;
    }
    sprite.setTexture(textures[currentTextureIndex]);
     sprite.setTextureRect(IntRect(0,0,textures[currentTextureIndex].getSize().x,textures[currentTextureIndex].getSize().y));  
}
void video(bool& video,RenderWindow& window)
{
	

	
View view(FloatRect(0, 0, window.getSize().x, window.getSize().y));
view.setSize(window.getSize().x, window.getSize().y);



window.setView(view);
 window.setFramerateLimit(30);
Texture textures[2849];
loadTextures(textures, 2849,"video_frames\\frames\\frame");
Sprite sprite;


sf::Clock timer;


int currentTextureIndex;


    sf::Vector2u windowSize = window.getSize();

    // Получаем размер текстуры спрайта
    sf::Vector2u textureSize = textures[0].getSize();

    // Вычисляем масштабирующие коэффициенты
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

    // Устанавливаем масштаб спрайта
    sprite.setScale(scaleX, scaleY);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


  if (timer.getElapsedTime().asSeconds() >= 60)
        {
video = false;
break;
        }else{
        	
   upAttack(textures,sprite,currentTextureIndex,2849);     	
        	
		}




        window.clear();
        window.draw(sprite);
        window.display();
    }

    
}
