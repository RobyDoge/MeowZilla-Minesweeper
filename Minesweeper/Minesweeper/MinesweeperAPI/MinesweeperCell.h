#pragma once

#include "ECellState.h";

class MinesweeperCell
{
public:
	MinesweeperCell(int row, int column);

public:
	ECellState GetState();
	int GetAdjacentMines();
	int GetRow();
	int GetColumn();

	void SetState(ECellState state);
	void AddAdjacentMine();
	bool IsMine() const;

private:
	ECellState m_state;
	int m_adjacentMines;
	int m_row;
	int m_column;
};

