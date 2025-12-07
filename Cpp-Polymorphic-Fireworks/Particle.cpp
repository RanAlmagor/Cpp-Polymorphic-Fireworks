#include "particle.hpp"

Particle::Particle(const sf::Vector2f &pos, const sf::Vector2f &vel, const sf::Color &col,int life) :position{ pos }, velocity{ vel }, color{ col},lifetime{life}
{

}

bool Particle::isDead() const
{
	return lifetime < 0;
}

// Getters
sf::Vector2f Particle::getPosition() const 
{ return position; 
}
sf::Color  Particle:: getColor() const 
{ return color; 
}