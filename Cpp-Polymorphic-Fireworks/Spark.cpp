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

void Spark::draw(sf::RenderWindow& window, sf::RenderStates states) const
{
    float maxLife = (float)(MIN_LIFETIME + LIFETIME_VARIANCE / 2);
    float ratio = lifetime / maxLife;

    if (ratio < 0.0f) ratio = 0.0f;
    if (ratio > 1.0f) ratio = 1.0f;

    unsigned char alpha = static_cast<unsigned char>(255 * ratio);

    sf::CircleShape spark(2.f);
    spark.setPosition(position);
    spark.setFillColor(sf::Color(color.r, color.g, color.b, alpha));

    // Pass the blend mode states
    window.draw(spark, states);
}