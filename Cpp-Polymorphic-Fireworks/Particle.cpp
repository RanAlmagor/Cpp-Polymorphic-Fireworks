#include "particle.hpp"

Particle::Particle(const sf::Vector2f &pos, const sf::Vector2f &vel, const sf::Color &col) :position{ pos }, velocity{ vel }, color{ col }
{

}

bool Particle::isDead() const
{
	return dead;
}