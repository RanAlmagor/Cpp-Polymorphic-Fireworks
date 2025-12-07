#include "Rocket.hpp"
#include <cstdlib>

Rocket::Rocket(const sf::Vector2f& pos,const sf::Vector2f& vel, const sf::Color& col) : Particle{ pos, vel, col }, lifetime{ 0 }          // או כל ערך התחלתי שאתה רוצה
{
	lifetime = 60 + (rand() % 40); // 60-99 sec
}

void Rocket::update()
{
	// 1 ---Life Management---

	lifetime--;
	if (lifetime < 0)
	{
		dead = true;
		return;
	}

	// 2 ---trail managememt---

	trail.push_back(position);
	if (trail.size() > 20)
	{
		trail.erase(trail.begin());
	}

	position += velocity;
}

void Rocket::draw(sf::RenderWindow& window) const
{
	// 1. ציור השובל (Trail)
	for (size_t i{ 0 }; i < trail.size(); i++)
	{
		// חישוב השקיפות (כמו שעשית)
		sf::Uint8 alpha = static_cast<sf::Uint8>(255 * ((float)i / trail.size()));

		// --- החלק החסר: יצירה וציור של הנקודה ---
		sf::CircleShape tailPoint(2.f); // רדיוס קטן (2 פיקסלים)
		tailPoint.setPosition(trail[i]); // המיקום מההיסטוריה

		// קביעת הצבע: לוקחים את ה-RGB המקורי, ומוסיפים את ה-Alpha שחישבנו
		tailPoint.setFillColor(sf::Color(color.r, color.g, color.b, alpha));

		window.draw(tailPoint);
	}

	// 2. ציור הראש של הטיל (המיקום הנוכחי)
	// מציירים אותו אטום לגמרי ובלי לולאה
	sf::CircleShape head(4.f); // ראש קצת יותר גדול (4 פיקסלים)
	head.setPosition(position);
	head.setFillColor(color);
	window.draw(head);
}
