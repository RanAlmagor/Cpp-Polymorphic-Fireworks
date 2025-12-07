#pragma once
#include <SFML/Graphics.hpp>

class Particle
{
protected:
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Color color;
	bool dead = false;

public:
	Particle(sf::Vector2f& pos, sf::Vector2f& vel, sf::Color& col);

	virtual void update() = 0;

	virtual void draw(sf::RenderWindow& window) const = 0;

	bool isDead() const;

	virtual ~Particle() =default;



};