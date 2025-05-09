#include <SFML/Graphics.hpp>
#include <iostream>
#include <functional> 

using namespace std;
using namespace sf;

class Button
{
public:
    Button(sf::Vector2f position, float width, float height, sf::Color idleColor, sf::Color hoverColor, sf::Color pressedColor, std::string buttonText, sf::Font& font)
        : m_position(position), m_idleColor(idleColor), m_hoverColor(hoverColor), m_pressedColor(pressedColor)
    {
        m_shape.setPosition(position);
        m_shape.setSize(sf::Vector2f(width, height));
        m_shape.setFillColor(m_idleColor);
        

        m_text.setFont(font);
        m_text.setString(buttonText);
        m_text.setCharacterSize(20);
        m_text.setFillColor(sf::Color::Black);

      
        sf::FloatRect textBounds = m_text.getLocalBounds();
        m_text.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
        m_text.setPosition(position.x + width / 2.0f, position.y + height / 2.0f);
    }
    void setOnClick(const std::function<void()>& onClick) {
        m_onClick = onClick;
    }
void update(sf::RenderWindow& window,View& view)

{
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window), view);
    bool isMouseOver = m_shape.getGlobalBounds().contains(mousePos);

    if (isMouseOver)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            m_shape.setFillColor(m_pressedColor);
            m_shape.setOutlineColor(m_hoverColor);

            if (m_onClick) {
                m_onClick();
            }
        
        }
        else
        {
            m_shape.setFillColor(m_hoverColor);
            m_shape.setOutlineColor(m_hoverColor);
        }
    }
    else
    {
        m_shape.setFillColor(Color(191,202,202,185));
        m_shape.setOutlineColor(Color(191,202,202,185));
    }
}

    void draw(sf::RenderWindow& window)
    {
        window.draw(m_shape);
        window.draw(m_text);
    }

    void setSize(float width, float height)
    {
        m_shape.setSize(sf::Vector2f(width, height));
        // Recenter text
        sf::FloatRect textBounds = m_text.getLocalBounds();
        m_text.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
        m_text.setPosition(m_position.x + width / 2.0f, m_position.y + height / 2.0f);
    }

public:
	std::function<void()> m_onClick;
    sf::RectangleShape m_shape;
    sf::Text m_text;
    sf::Vector2f m_position;
    sf::Color m_idleColor;
    sf::Color m_hoverColor;
    sf::Color m_pressedColor;
};
