#pragma once

#include "ECellState.h";

class MinesweeperCell
{
public:
	MinesweeperCell(int row, int column);
	ECellState GetState();
	void SetState(ECellState state);
	int GetAdjacentMines();
	void AddAdjacentMine();
	int GetRow();
	int GetColumn();
	bool IsMine() const;

private:
	ECellState m_state;
	int adjacentMines;
	int row;
	int column;
};

