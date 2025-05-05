#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>

#include "GameState.h"
#include "GameManager.h"

void render_world(const GameState& state) {
	system("cls");
	std::cout << "Epoch " << state.epoch << '\n';
	for (int row = 0; row < state.m_field.size(); ++row) {
		for (int col = 0; col < state.m_field[0].size(); ++col) {
			if (state.m_player_pos.row == row && state.m_player_pos.col == col)
				std::cout << 'P';
			else
				switch (state.m_field[row][col]) {
					case CellType::Empty:
						std::cout << '.';
						break;
					case CellType::Wall:
						std::cout << 'H';
						break;
				}
		}
		std::cout << '\n';
	}
	std::cout << '\n';
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

struct RenderParams {
	float cell_side = 100.0f;
	sf::Color empty_color = sf::Color(100, 250, 50);
	sf::Color wall_color = sf::Color(100, 100, 100);
	sf::Color player_color = sf::Color(255, 100, 100);
};

void render_world(const GameState& state, sf::RenderWindow& window, const RenderParams& params = RenderParams()) {
	const float cell_side = params.cell_side;
	sf::RectangleShape cell({ cell_side, cell_side });
	for (int row = 0; row < state.m_field.size(); ++row) {
		for (int col = 0; col < state.m_field[0].size(); ++col) {
			cell.setPosition(col*cell_side, row*cell_side);
			if (state.m_player_pos.row == row && state.m_player_pos.col == col)
				cell.setFillColor(params.player_color);
			else
				switch (state.m_field[row][col]) {
				case CellType::Empty:
					cell.setFillColor(params.empty_color);
					break;
				case CellType::Wall:
					cell.setFillColor(params.wall_color);
					break;
				}
			window.draw(cell);
		}
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
}

int main() {
	GameState init_state;
	init_state.m_field = {
		{ CellType::Empty, CellType::Empty, CellType::Empty, CellType::Empty, CellType::Empty, CellType::Empty, CellType::Empty, CellType::Empty},
		{ CellType::Empty, CellType::Empty, CellType::Empty, CellType::Empty, CellType::Empty, CellType::Empty, CellType::Empty, CellType::Empty },
		{ CellType::Empty, CellType::Empty, CellType::Wall,  CellType::Empty, CellType::Empty, CellType::Wall,  CellType::Empty, CellType::Empty },
		{ CellType::Empty, CellType::Empty, CellType::Wall,  CellType::Wall,  CellType::Wall,  CellType::Wall,  CellType::Empty, CellType::Empty },
		{ CellType::Empty, CellType::Empty, CellType::Wall,  CellType::Empty, CellType::Empty, CellType::Wall,  CellType::Empty, CellType::Empty },
		{ CellType::Empty, CellType::Empty, CellType::Empty, CellType::Empty, CellType::Empty, CellType::Empty, CellType::Empty, CellType::Empty },
		{ CellType::Empty, CellType::Empty, CellType::Empty, CellType::Empty, CellType::Empty, CellType::Empty, CellType::Empty, CellType::Empty },
	};
	init_state.m_player_pos.row = 0;
	init_state.m_player_pos.col = 0;

	GameManager manager(init_state);
	const unsigned int win_width = 640u;
	const unsigned int win_height = 480u;

	sf::RenderWindow window(sf::VideoMode({ win_width, win_height }), "CMake SFML Project");
    window.setFramerateLimit(144);

	const int field_rows = init_state.m_field.size();
	const int field_cols = init_state.m_field[0].size();

	const float width_ratio = (float)win_width / field_cols;
	const float height_ratio = (float)win_height / field_rows;

	const float cell_side = std::min(width_ratio, height_ratio);

	RenderParams render_params;
	render_params.cell_side = cell_side;

	sf::Event event;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
			if (event.type == sf::Event::Closed)
				window.close();
        }

		//sf::CircleShape shape(50.f);
		//// set the shape color to green
		//shape.setFillColor(sf::Color(100, 250, 50));
		
        window.clear();
		//window.draw(shape);
		auto state = manager.get_state();
		render_world(state, window, render_params);

        window.display();
		/*Direction dir = Direction(rand() % 4);*/
		// Process direction
		Direction dir = Direction::None;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
			dir = Direction::Left;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
			dir = Direction::Right;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
			dir = Direction::Down;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
			dir = Direction::Up;

		manager.move_player(dir);
    }

	/*
	GameState init_state;
	init_state.m_field = {
		{CellType::Empty, CellType::Empty, CellType::Empty, CellType::Empty, CellType::Empty},
		{CellType::Empty, CellType::Wall,  CellType::Empty, CellType::Wall,  CellType::Empty},
		{CellType::Empty, CellType::Wall,  CellType::Empty, CellType::Wall,  CellType::Empty},
		{CellType::Empty, CellType::Wall,  CellType::Empty, CellType::Wall,  CellType::Empty},
		{CellType::Empty, CellType::Empty, CellType::Empty, CellType::Empty, CellType::Empty}
	};
	init_state.m_player_pos.row = 0;
	init_state.m_player_pos.col = 0;

	GameManager manager(init_state);

	// Render inital field
	render_world(manager.get_state());

	for (int step = 0; step < 6; ++step) {
		manager.move_player(Direction::Right);
		// Render field
		render_world(manager.get_state());
	}

	manager.move_player(Direction::Down);
	// Render field
	render_world(manager.get_state());

	manager.move_player(Direction::Left);
	// Render field
	render_world(manager.get_state());

	system("pause");
*/
	return 0;
}
