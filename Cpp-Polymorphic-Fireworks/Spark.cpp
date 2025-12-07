#include "Spark.hpp"
#include <cstdlib> //  rand
#include <algorithm> //  std::max

Spark::Spark(const sf::Vector2f& pos, const sf::Vector2f& vel, const sf::Color& col)
	: Particle(pos, vel, col, MIN_LIFETIME + (rand() % LIFETIME_VARIANCE))
{
}

void Spark::update()
{
	lifetime--;
	velocity.y += 0.2f;
	position += velocity;
}

void Spark::draw(sf::RenderWindow& window)const
{

}