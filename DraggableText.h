#include <SFML/Graphics.hpp>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Table.hpp"
using namespace std;
using namespace sf;

class DraggableTextNoColor {
public:
    DraggableTextNoColor(const std::string& text, const sf::Font& font, unsigned int characterSize, const sf::Color& color, const sf::Vector2f& position)
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
                m_text.setFillColor(sf::Color::Black);
                m_isGreen = true;
                m_wasGreen = true;
                greenTextCount++;
            }
        } else if (m_text.getPosition().x < 650 && m_text.getPosition().y < 700) {
            if (m_isGreen && m_wasGreen) {
                m_text.setFillColor(sf::Color::Black); // Change color back to red if not in color change area
                m_wasGreen = false;
				m_isGreen = false;
                greenTextCount--;
            } else if (m_text.getFillColor() != sf::Color::Black) {
                m_text.setFillColor(sf::Color::Black);
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
int DraggableTextNoColor::greenTextCount = 0;

void startTimer(sf::RenderWindow& window, sf::Event& event, sf::Font& font, Clock& clock, int& countdown, Text& timerText)
{
    sf::Time elapsed = clock.getElapsedTime();
    int seconds = countdown - elapsed.asSeconds();

    if (seconds >= 0)
    {
        int minutes = seconds / 60;
        int remainingSeconds = seconds % 60;

        // Форматируем строки для добавления ведущего нуля
        std::string minutesStr = std::to_string(minutes);
        std::string secondsStr = std::to_string(remainingSeconds);
        if (minutes < 10) minutesStr = "0" + minutesStr;
        if (remainingSeconds < 10) secondsStr = "0" + secondsStr;

        timerText.setString(minutesStr + " : " + secondsStr);
        window.draw(timerText);
    }
    else
    {
        if (countdown >= 0)
        {
            timerText.setString("Время Вышло");
            window.draw(timerText);
        }
    }
}

