#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "Rocket.hpp"
#include "Spark.hpp"

int main()
{
    
    sf::RenderWindow window(sf::VideoMode({ 1280, 720 }), "The Ultimate Fireworks Show");
    window.setFramerateLimit(60);

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::vector<std::unique_ptr<Particle>> particles;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            if (const auto* mousePress = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (mousePress->button == sf::Mouse::Button::Left)
                {
                    // Launch from bottom of the HD screen (720.f)
                    sf::Vector2f startPos((float)mousePress->position.x, 720.f);

                    float speedX = (rand() % 200 - 100) / 100.f * 2.f;
                    // Adjusted speed to keep the rocket on screen (-6 to -9)
                    float speedY = -((rand() % 300) / 100.f + 6.f);

                    sf::Vector2f velocity(speedX, speedY);
                    sf::Color color(rand() % 256, rand() % 256, rand() % 256);

                    particles.push_back(std::make_unique<Rocket>(startPos, velocity, color));
                }
            }
        }

        std::vector<std::unique_ptr<Particle>> newSparks;

        for (auto& p : particles)
        {
            p->update();

            if (p->isDead())
            {
                Rocket* rocket = dynamic_cast<Rocket*>(p.get());

                if (rocket != nullptr)
                {
                    // Increased spark count to 100 for bigger explosion
                    int sparksCount = 100;
                    for (int i = 0; i < sparksCount; i++)
                    {
                        float angle = (rand() % 360) * 3.14159f / 180.f;

                        // Increased explosion speed range (3.0 to 11.0)
                        float speed = (rand() % 80) / 10.f + 3.f;

                        sf::Vector2f sparkVel(std::cos(angle) * speed, std::sin(angle) * speed);

                        newSparks.push_back(std::make_unique<Spark>(rocket->getPosition(), sparkVel, rocket->getColor()));
                    }
                }
            }
        }

        for (auto& s : newSparks)
        {
            particles.push_back(std::move(s));
        }

        std::erase_if(particles, [](const auto& p) {
            return p->isDead();
            });

        window.clear(sf::Color::Black);

        
        sf::RenderStates states;
        states.blendMode = sf::BlendAdd;

        for (const auto& p : particles)
        {
            
            p->draw(window, states);
        }

        window.display();
    }

    return 0;
}