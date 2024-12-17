#pragma once

#include "ICell.h";

//! Class that implements the ICell interface.
class MinesweeperCell : public ICell
{
public:
	/*!  Default Constructor for the Cell class. */
	MinesweeperCell();
	/*******************************************//**
	*  Constructor for the Cell that sets the state to UNREVEALED, the number of adjacent mines to 0, and the row and column to the given values.
		\param row is an integer representing the row of the cell
		\param column is an integer representing the column of the cell
	***********************************************/
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

