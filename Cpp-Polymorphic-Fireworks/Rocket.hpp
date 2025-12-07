#pragma once
#include "Particle.hpp"
#include<vector>

class Rocket : public Particle
{
private:
	std::vector<sf::Vector2f> trail;
	int lifetime;

public:
	Rocket(const sf::Vector2f& pos, const sf::Vector2f& vel, const  sf::Color& col);

	void update() override;

	void draw(sf::RenderWindow& window) const override;
};
