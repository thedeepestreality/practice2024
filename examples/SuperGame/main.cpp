#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

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

int main() {
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
	return 0;
}