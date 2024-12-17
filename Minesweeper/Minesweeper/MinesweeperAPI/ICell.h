#pragma once
#include "ECellState.h"

#include <memory>

using CellPtr = std::shared_ptr <class ICell>;

//! Interface class for the Cells of the game board implemented in the MinesweeperCell class
class ICell
{
public:
	/*******************************************//**
	*  Method to get the current state of the cell.
		- Returns the state of the cell which is an ECellState enum
	Implement in MinesweeperCell as a public method.
	***********************************************/
	virtual ECellState GetState() = 0;

	/*******************************************//**
	*  Method to get the number of adjacent mines to the cell.
		- Returns the number of adjacent mines to the cell
	Implement in MinesweeperCell as a public method.
	***********************************************/
	virtual int GetAdjacentMines() = 0;

	/*******************************************//**
	*  Method to get the row of the cell.
		- Uses the m_row member variable of the inheriting class
		- Returns the index of the cell's row
	Implement in MinesweeperCell as a public method.
	***********************************************/
	virtual int GetRow() = 0;

	/*******************************************//**
	*  Method to get the column of the cell.
		- Uses the m_column member variable of the inheriting class
		- Returns the index of the cell's column
	Implement in MinesweeperCell as a public method.
	***********************************************/
	virtual int GetColumn() = 0;

	/*******************************************//**
	*  Method to set the state of the cell.
		- Sets the state of the cell to the given state
		\param state is an ECellState argument representing the state to be set
	Implement in MinesweeperCell as a public method.
	***********************************************/
	virtual void SetState(ECellState state) = 0;

	/*******************************************//**
	*  Method to increase the number of mines adjacent to the cell.
		- Increments the inheriting class member variable m_adjacentMines by 1
	Implement in MinesweeperCell as a public method.
	***********************************************/
	virtual void AddAdjacentMine() = 0;

	/*******************************************//**
	*  Method to check if the cell is a mine.
		- Uses the m_state member variable of the inheriting class
		- Returns true if the current state of the cell is MINE or FLAGGED_MINE, false otherwise
	Implement in MinesweeperCell as a public method.
	***********************************************/
	virtual bool IsMine() const = 0;
};