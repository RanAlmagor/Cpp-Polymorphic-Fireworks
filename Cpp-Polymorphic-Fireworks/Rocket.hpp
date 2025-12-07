#pragma once
#include "Particle.hpp"
#include<vector>

class Rocket : public Particle
{
private:
	std::vector<sf::Vector2f> trail;
	static constexpr int MIN_LIFETIME = 60;
	static constexpr int LIFETIME_VARIANCE = 40;
	

public:
	Rocket(const sf::Vector2f& pos, const sf::Vector2f& vel, const  sf::Color& col);

	void update() override;

	void draw(sf::RenderWindow& window) const override;
};
