#pragma once

#include "GameState.h"

enum class Direction {
	None,
	Up,
	Down,
	Left,
	Right
};

class GameManager {
private:
	GameState m_state;
	
	CellPosition move(CellPosition pos, Direction dir) {
		/*++m_state.epoch;*/
		CellPosition new_pos = pos;
		switch (dir) {
		case Direction::Up:
			--new_pos.row;
			break;
		case Direction::Down:
			++new_pos.row;
			break;
		case Direction::Left:
			--new_pos.col;
			break;
		case Direction::Right:
			++new_pos.col;
			break;
		}
		// check borders
		if (new_pos.row < 0 || new_pos.col < 0)
			return pos;
		if (new_pos.row >= m_state.m_field.size() || new_pos.col >= m_state.m_field[0].size())
			return pos;
		// check walls
		if (m_state.m_field[new_pos.row][new_pos.col] != CellType::Empty)
			return pos;
		return new_pos;
	}
public:
	GameManager(const GameState& state) : m_state(state) {};

	void update_world(Direction player_dir) {
		m_state.m_player_pos = move(m_state.m_player_pos, player_dir);
		for (CellPosition& enemy_pos : m_state.m_enemy_pos)
			enemy_pos = move(enemy_pos, Direction((rand() % 4) + 1));
	}

	GameState get_state() const {
		return m_state;
	}
};