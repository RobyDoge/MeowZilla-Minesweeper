#include "MinesweeperCell.h"

MinesweeperCell::MinesweeperCell(int row, int column)
{
	m_state = ECellState::UNREVEALED;
	adjacentMines = 0;
	this->row = row;
	this->column = column;

}

ECellState MinesweeperCell::GetState()
{
	return m_state;
}

void MinesweeperCell::SetState(ECellState state)
{
	m_state = state;
}

int MinesweeperCell::GetAdjacentMines()
{
	return adjacentMines;
}

void MinesweeperCell::AddAdjacentMine()
{
	adjacentMines++;
}

int MinesweeperCell::GetRow()
{
	return row;
}

int MinesweeperCell::GetColumn()
{
	return column;
}

bool MinesweeperCell::IsMine() const
{
	
		return (m_state == ECellState::MINE || m_state == ECellState::FLAGGED_MINE);
	
}
