#include "Rocket.hpp"
#include <cstdlib>

Rocket::Rocket(const sf::Vector2f& pos, const sf::Vector2f& vel, const sf::Color& col)
	: Particle(pos, vel, col, MIN_LIFETIME + (rand() % LIFETIME_VARIANCE))
{
}

void Rocket::update()
{

	lifetime--;

	//  ---trail managememt---

	trail.push_back(position);
	if (trail.size() > 20)
	{
		trail.erase(trail.begin());
	}

	position += velocity;
}

void Rocket::draw(sf::RenderWindow& window, sf::RenderStates states) const
{
    // Draw trail
    for (size_t i{ 0 }; i < trail.size(); i++)
    {
        unsigned char alpha = static_cast<unsigned char>(255 * (float)i / trail.size());

        sf::CircleShape tailPoint(2.f);
        tailPoint.setPosition(trail[i]);
        tailPoint.setFillColor(sf::Color(color.r, color.g, color.b, alpha));

        // Pass the blend mode states
        window.draw(tailPoint, states);
    }

    // Draw head
    sf::CircleShape head(4.f);
    head.setPosition(position);
    head.setFillColor(color);

    window.draw(head, states);
}