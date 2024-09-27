#pragma once

#include <SFML/Graphics.hpp>
class Meteor
{
public:
	Meteor();
	~Meteor();

	void move(float& time); // двиэение метеора
	void draw(sf::RenderWindow& window); // отрисвока метеора
	void animation(); // анимация метеора
	bool collision(sf::FloatRect object); // столкновения метеора
	void restart(); // установка новых координат
	sf::FloatRect get_meteor_bounds(); // положение глобальных координат

private:
	sf::Sprite space_object;  //объект метеорит
	sf::Texture texture_object; // текстура метеорит


	int xsp[5]{ 3,73,135,198,262 };       // координаты текстуры по x
	int ysp[6]{ 3,68,132,200,265,325 };   // координаты текстуры по y

	int ix, iy = 0; // смещение по x y
	int st = 0; // шаг анимации 
};

