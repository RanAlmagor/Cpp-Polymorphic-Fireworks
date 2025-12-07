#pragma once
#include <SFML/Graphics.hpp>

class Particle
{
protected:
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Color color;
	int lifetime=0;

public:
	Particle(const sf::Vector2f& pos, const  sf::Vector2f& vel, const sf::Color& col,int life);

	virtual void update() = 0;

	virtual void draw(sf::RenderWindow& window, sf::RenderStates states = sf::RenderStates::Default) const = 0;

	virtual ~Particle() = default;

	bool isDead() const;

	// Getters

	sf::Vector2f getPosition() const;

	sf::Color getColor() const;



};