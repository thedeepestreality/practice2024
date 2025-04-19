#pragma once

#include "GameState.h"

enum class Direction {
	Up,
	Down,
	Left,
	Right
};

class GameManager {
private:
	GameState m_state;
public:
	GameManager(const GameState& state) : m_state(state) {};

	void move_player(Direction dir) {
		CellPosition candidate = m_state.m_player_pos;
		switch (dir) {
			case Direction::Up: 
				--candidate.row;
				break;
			case Direction::Down:
				++candidate.row;
				break;
			case Direction::Left:
				--candidate.col;
				break;
			case Direction::Right:
				++candidate.col;
				break;
		}
		// check borders
		if (candidate.row < 0 || candidate.col < 0)
			return;
		if (candidate.row >= m_state.m_field.size() || candidate.col >= m_state.m_field[0].size())
			return;
		// check walls
		if (m_state.m_field[candidate.row][candidate.col] != CellType::Empty)
			return;
		m_state.m_player_pos = candidate;
	}

	GameState get_state() const {
		return m_state;
	}
};