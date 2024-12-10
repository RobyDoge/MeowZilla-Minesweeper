#pragma once

#include "ICell.h";

class MinesweeperCell : public ICell
{
public:
	MinesweeperCell();
	MinesweeperCell(int row, int column);

public:
	ECellState GetState() override;
	int GetAdjacentMines() override;
	int GetRow() override;
	int GetColumn() override;

	void SetState(ECellState state) override;
	void AddAdjacentMine() override;
	bool IsMine() const override;

private:
	ECellState m_state;
	int m_adjacentMines;
	int m_row;
	int m_column;
};

