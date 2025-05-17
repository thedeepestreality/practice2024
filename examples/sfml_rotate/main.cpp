#include <iostream>
#include <cmath>

#include <SFML/Graphics.hpp>

sf::Vector2f rotate_vec(sf::Vector2f vec, float alpha) {
	// R(alpha) * vec
	float x = cos(alpha) * vec.x - sin(alpha) * vec.y;
	float y = sin(alpha) * vec.x + cos(alpha) * vec.y;
	return sf::Vector2f(x, y);
}

int main() {
	const unsigned int win_width = 640u;
	const unsigned int win_height = 480u;

	sf::RenderWindow window(sf::VideoMode({ win_width, win_height }), "CMake SFML Project");
    window.setFramerateLimit(144);

	sf::Event event;
	float alpha = 0.0f;
	float dalpha = 0.01f;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
			if (event.type == sf::Event::Closed)
				window.close();
        }
		
        window.clear();

		// create an empty shape
		sf::ConvexShape convex;

		// resize it to 5 points
		convex.setPointCount(3);

		// define the points
		convex.setPoint(0, { 100.0f, 100.0f });
		convex.setPoint(1, { 150.0f, 200.0f });
		convex.setPoint(2, { 200.0f, 100.0f });

		sf::Vector2f p1 = convex.getPoint(0);
		sf::Vector2f p2 = convex.getPoint(1);
		sf::Vector2f p3 = convex.getPoint(2);

		sf::Vector2f center = (p1 + p2 + p3) / 3.0f;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
			alpha -= dalpha;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
			alpha += dalpha;

        // convert to radians
		float ralpha = 3.14159265359f * alpha / 180.0f;

		// create an empty shape
		sf::ConvexShape convex_rotated;

		// resize it to 5 points
		convex_rotated.setPointCount(3);

		// define the points		
		convex_rotated.setPoint(0, rotate_vec(p1 - center, alpha) + center);
		convex_rotated.setPoint(1, rotate_vec(p2 - center, alpha) + center);
		convex_rotated.setPoint(2, rotate_vec(p3 - center, alpha) + center);

		convex_rotated.setFillColor(sf::Color(200, 100, 100));

		window.draw(convex);
		window.draw(convex_rotated);
		window.display();
    }

	return 0;
}
