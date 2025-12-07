#pragma once
#include "Particle.hpp"

class Spark : public Particle
{
private:
	static constexpr int MIN_LIFETIME = 30;
	static constexpr int LIFETIME_VARIANCE = 30;
public:
	
	Spark(const sf::Vector2f& pos, const sf::Vector2f& vel, const sf::Color& col);

	void update() override;

	void draw(sf::RenderWindow& window, sf::RenderStates states = sf::RenderStates::Default) const override;

};