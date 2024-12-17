#pragma once
#include "MinesweeperCell.h"
#include "ICell.h"
#include "EGameState.h"
#include <string>

//! Interface class for the Minesweeper game listeners. Implemented in MinesweeperListenerUI class.
class IMinesweeperListener
{
public:

	/*******************************************//**
	*  Method to notify the listeners that a cell has changed its state.
		- Emits a signal with the cell, the game state, and the theme
		\param cell is an ICell pointer representing the cell that has changed
		\param gameState is an EGameState enum representing the state of the game
		\param theme is a string representing the theme of the game
	***********************************************/
	virtual void OnCellImageChange(CellPtr cell, EGameState gameState, std::string theme) = 0;

	/*******************************************//**
	*  Method to notify the listeners that the number of flags has changed.
		- Emits a signal with the number of flags
		\param flagsNumber is an integer representing the number of flags in the game
	***********************************************/
	virtual void OnFlagCountChanged(int flagsNumber) = 0;

	/*******************************************//**
	*  Method to notify the listeners that the timer has changed.
		- Emits a signal with the timer
		\param timer is an integer representing the timer of the game
	***********************************************/
	virtual void OnTimerChanged(int timer) = 0;

	/*******************************************//**
	*  Method to notify the listeners that the game is over.
	**********************************************/
	virtual void OnGameOver() = 0;

	/*******************************************//**
	*  Method to notify the listeners that the game is won.
	**********************************************/
	virtual void OnWin() = 0;

	/*******************************************//**
	*  Method to notify the listeners that the settings have been updated.
		- Emits a signal with the width, height, mines number, theme, and timer
		\param width is an integer representing the width of the game window
		\param height is an integer representing the height of the game window
		\param minesNumber is an integer representing the number of mines in the game
		\param theme is a string representing the theme of the game
		\param timer is an integer representing the timer of the game
	**********************************************/
	virtual void OnSettingsUpdated(int width, int height, int minesNumber, std::string theme, int timer) = 0;

	//! Virtual destructor for the IMinesweeperListener interface.
	virtual ~IMinesweeperListener() = default;
};