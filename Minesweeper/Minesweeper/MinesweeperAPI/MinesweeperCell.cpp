#include "MinesweeperCell.h"

MinesweeperCell::MinesweeperCell(int row, int column)
{
	m_state = ECellState::UNREVEALED;
	m_adjacentMines = 0;
	this->m_row = row;
	this->m_column = column;
}

ECellState MinesweeperCell::GetState()
{
	return m_state;
}

int MinesweeperCell::GetAdjacentMines()
{
	return m_adjacentMines;
}

int MinesweeperCell::GetRow()
{
	return m_row;
}

int MinesweeperCell::GetColumn()
{
	return m_column;
}

void MinesweeperCell::SetState(ECellState state)
{
	m_state = state;
}

void MinesweeperCell::AddAdjacentMine()
{
	m_adjacentMines++;
}

bool MinesweeperCell::IsMine() const
{
	return (m_state == ECellState::MINE || m_state == ECellState::FLAGGED_MINE);
}
