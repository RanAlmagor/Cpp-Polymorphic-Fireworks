#include "particle.hpp"

Particle::Particle(sf::Vector2f &pos, sf::Vector2f &vel, sf::Color &col) :position{ pos }, velocity{ vel }, color{ col }
{

}

bool Particle::isDead() const
{
	return dead;
}