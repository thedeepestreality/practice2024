#include <iostream>
#include <cmath>
#include <array>

#include <SFML/Graphics.hpp>

sf::Vector2f rotate_vec(sf::Vector2f vec, float alpha) {
	// R(alpha) * vec
	float x = cos(alpha) * vec.x - sin(alpha) * vec.y;
	float y = sin(alpha) * vec.x + cos(alpha) * vec.y;
	return sf::Vector2f(x, y);
}

struct Point3D {
	float x;
	float y;
	float z;
	Point3D(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}
};

Point3D rotate3D_x(Point3D p, float alpha) {
	float x = p.x;
	float y = cos(alpha) * p.y - sin(alpha) * p.z;
	float z = sin(alpha) * p.y + cos(alpha) * p.z;
	return Point3D(x, y, z);
}

Point3D rotate3D_z(Point3D p, float alpha) {
	float x = cos(alpha) * p.x + sin(alpha) * p.z;
	float y = p.y;
	float z = -sin(alpha) * p.x + cos(alpha) * p.z;
	return Point3D(x, y, z);
}

void render_cube(const std::array<Point3D, 8>& points, 
				sf::RenderWindow& win) {
	const float f0 = 0.005;
	auto sz = win.getSize();
	float c_x = sz.x / 2.0f;
	float c_y = sz.y / 2.0f;
	for (int i = 0; i < 7; ++i) {
		sf::Vector2f start(
			c_x + points[i].x / (f0 * points[i].z), 
			c_y + points[i].y / (f0 * points[i].z)
		);
		sf::Vector2f end(
			c_x + points[i+1].x / (f0 * points[i+1].z),
			c_y + points[i+1].y / (f0 * points[i+1].z)
		);
		std::array line = { sf::Vertex(start), sf::Vertex(end) };
		win.draw(line.data(), line.size(), sf::PrimitiveType::Lines);
	}
	sf::Vector2f start(
		c_x + points[7].x / (f0*points[7].z),
		c_y + points[7].y / (f0 * points[7].z)
	);
	sf::Vector2f end(
		c_x + points[0].x / (f0 * points[0].z),
		c_y + points[0].y / (f0 * points[0].z)
	);
	std::array line = { sf::Vertex(start), sf::Vertex(end) };
	win.draw(line.data(), line.size(), sf::PrimitiveType::Lines);
}

int main() {
	const unsigned int win_width = 640u;
	const unsigned int win_height = 480u;

	sf::RenderWindow window(sf::VideoMode({ win_width, win_height }), "CMake SFML Project");
    window.setFramerateLimit(144);

	sf::Event event;
	float alpha = 0.0f;
	float dalpha = 0.2f;
	float phi = 0.0f;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
			if (event.type == sf::Event::Closed)
				window.close();
        }
		
        window.clear();
		float z0 = 15.0f;
		std::array cube = {
			Point3D(-10.0f, -10.f, z0),
			Point3D(-10.0f, 10.f, z0),
			Point3D(10.0f, 10.f, z0),
			Point3D(10.0f, -10.f, z0),
			Point3D(10.0f, -10.f, z0 + 20.f),
			Point3D(10.0f, 10.f, z0 + 20.f),
			Point3D(-10.0f, 10.f, z0 + 20.f),
			Point3D(-10.0f, -10.f, z0 + 20.f),
		};
		float z_c = z0 + 10.0f;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
			alpha += dalpha;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
			alpha -= dalpha;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
			phi -= dalpha;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
			phi += dalpha;

        // convert to radians
		float ralpha = 3.14159265359f * alpha / 180.0f;
		float rphi = 3.14159265359f * phi / 180.0f;

		for (int i = 0; i < 8; ++i) {
			cube[i].z -= z_c;
			cube[i] = rotate3D_z(cube[i], ralpha);
			cube[i] = rotate3D_x(cube[i], rphi);
			cube[i].z += z_c;
		}

		render_cube(cube, window);

		//// create an empty shape
		//sf::ConvexShape convex;

		//// resize it to 5 points
		//convex.setPointCount(3);

		//// define the points
		//convex.setPoint(0, { 100.0f, 100.0f });
		//convex.setPoint(1, { 150.0f, 200.0f });
		//convex.setPoint(2, { 200.0f, 100.0f });

		//sf::Vector2f p1 = convex.getPoint(0);
		//sf::Vector2f p2 = convex.getPoint(1);
		//sf::Vector2f p3 = convex.getPoint(2);

		//sf::Vector2f center = (p1 + p2 + p3) / 3.0f;

		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		//	alpha -= dalpha;
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		//	alpha += dalpha;

  //      // convert to radians
		//float ralpha = 3.14159265359f * alpha / 180.0f;

		//// create an empty shape
		//sf::ConvexShape convex_rotated;

		//// resize it to 5 points
		//convex_rotated.setPointCount(3);

		//// define the points		
		//convex_rotated.setPoint(0, rotate_vec(p1 - center, alpha) + center);
		//convex_rotated.setPoint(1, rotate_vec(p2 - center, alpha) + center);
		//convex_rotated.setPoint(2, rotate_vec(p3 - center, alpha) + center);

		//convex_rotated.setFillColor(sf::Color(200, 100, 100));

		//window.draw(convex);
		//window.draw(convex_rotated);
		window.display();
    }

	return 0;
}
