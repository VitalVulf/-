#ifndef ELEMENT_H
#define ELEMENT_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class Element {
public:
    Element(float width, float height, sf::Color color, sf::Vector2f position, int index) : index(index) {
        rectangle.setSize(sf::Vector2f(width, height));
        rectangle.setFillColor(color);
        rectangle.setOutlineColor(sf::Color::Black); // Черная обводка
        rectangle.setOutlineThickness(1.0f); // Толщина обводки
        rectangle.setPosition(position);
    }

    void draw(sf::RenderWindow& window) const {
        window.draw(rectangle);
    }

void splitElement() {
    sf::Vector2f currentSize = rectangle.getSize();
    sf::Vector2f newSize(currentSize.x / 2, currentSize.y);

    sf::RectangleShape newRectangle1(newSize);
    newRectangle1.setFillColor(rectangle.getFillColor());
    newRectangle1.setOutlineColor(sf::Color::Black); // Черная обводка
    newRectangle1.setOutlineThickness(1.0f); // Толщина обводки
    newRectangle1.setPosition(rectangle.getPosition());

    sf::RectangleShape newRectangle2(newSize);
    newRectangle2.setFillColor(rectangle.getFillColor());
    newRectangle2.setOutlineColor(sf::Color::Black); // Черная обводка
    newRectangle2.setOutlineThickness(1.0f); // Толщина обводки
    newRectangle2.setPosition(rectangle.getPosition().x + currentSize.x / 2, rectangle.getPosition().y);

    // Создаем два новых элемента таблицы
    Element newElement1(newSize.x, newSize.y, rectangle.getFillColor(), newRectangle1.getPosition(), 0); // Передаем индекс 0 для примера
    Element newElement2(newSize.x, newSize.y, rectangle.getFillColor(), newRectangle2.getPosition(), 0); // Передаем индекс 0 для примера

    // Добавляем новые элементы в вектор элементов
    splitElements.push_back(newElement1);
    splitElements.push_back(newElement2);
}



    void drawSplitElements(sf::RenderWindow& window) const {
        for (const auto& splitElement : splitElements) {
            splitElement.draw(window);
        }
    }

    int getIndex() const {
        return index;
    }
public:
    sf::RectangleShape rectangle;
private:

    std::vector<Element> splitElements;
    int index;
};

class Table {
public:
    std::vector<std::vector<Element>> cells; // Изменяем доступ к cells на public

    Table(int rows, int cols, float cellWidth, float cellHeight, sf::Color fillColor, sf::Color outlineColor, sf::Vector2f position, sf::RenderWindow& window) {
        int index = 0;
        for (int i = 0; i < rows; ++i) {
            std::vector<Element> row;
            for (int j = 0; j < cols; ++j) {
                Element cell(cellWidth, cellHeight, fillColor, sf::Vector2f(position.x + j * cellWidth, position.y + i * cellHeight), index);
                row.push_back(cell);
                index++;
            }
            cells.push_back(row);
        }
    }

    void draw(sf::RenderWindow& window) {
        for (const auto& row : cells) {
            for (const auto& cell : row) {
                cell.draw(window);
            }
        }
    }

    Element& getElement(int row, int col) {
        return cells[row][col];
    }
};
#endif // ELEMENT_H


