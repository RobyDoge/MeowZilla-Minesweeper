#pragma once

#include "IMinesweeperListener.h"
#include "ICell.h"
#include "IStrategy.h"
#include "EDifficulty.h"
#include<memory>

using IGamePtr = std::shared_ptr<class IMinesweeperGame>;

//! Interface class for the Minesweeper game implemented in MinesweeperGame class.
class IMinesweeperGame
{
public:
	/*******************************************//**
 	*  Method to add a listener IMinesweeperListener pointer to the game.
		\param listener is a IMinesweeperListener pointer that handles notifications
 	***********************************************/
	virtual bool AddMinesweeperListener(IMinesweeperListener* listener) = 0;

	/*******************************************//**
 	*  Method to remove a listener IMinesweeperListener pointer from the game.
		\param listener is a IMinesweeperListener pointer that handles notifications
 	***********************************************/
	virtual bool RemoveMinesweeperListener(IMinesweeperListener* listener) = 0;

public:
	/*******************************************//**
 	*  Method to generate mines based on the clicked Cell row and column.
		\param clickedCellRow is an integer representing the row of the clicked cell
		\param clickedCellColumn is an integer representing the column of the clicked cell
 	***********************************************/
	virtual void GenerateMines(int clickedCellRow, int clickedCellColumn) = 0;

	/*! Method to restart the game.*/
	virtual void RestartGame() = 0;

	/*******************************************//**
 	*  Method to generate mines based on the clicked Cell row and column:
		- changes the game state to GAMEOVER
		- calls the EndGame method
 	***********************************************/
	virtual void GameOver() = 0;

	/*******************************************//**
 	*  Method to check if the game is won:
		- checking if all mines are flagged 
		- calls the EndGame method
	   Implemented in MinesweeperGame, private method.
 	***********************************************/
	virtual void CheckVictory() = 0;

	/*******************************************//**
 	*  Method to end the game:
		- Sets the game state to GAMEOVER if the game is over
		- Sets the game state to WIN if the game is won
		- Loops through the listeners and calls the OnGameOver or OnWin method \n\n
	Implemented in MinesweeperGame, private method.
 	***********************************************/
	virtual void EndGame() = 0;

	/*!
		Method to the timer in a separate thread, continuously updating the remaining time.
		- Notifies registered listeners about timer changes.
		- If the timer reaches zero or the game state changes to a terminal state (not WIN or FIRSTCLICK), the game ends. \n\n
		Implemented in MinesweeperGame, private method.
	*/
	virtual void CountdownTimer() = 0;

	/*! Method that sets the argument cell to revealed and checks for surrounding cells to reveal.
		\param cell is an ICell pointer representing the cell to be set to unrevealed
	*/
	virtual void RevealCells(CellPtr cell) = 0;

	/*!
		This method handles the behavior when a cell in the game is clicked. 
		- It checks the state of the game and the cell
		- If the game hasn't started, it calls the GenerateMines method
		- Calls the RevealCells method passing the clicked cell as an argument
		- Checks for victory using the CheckVictory method
		\param cell is an ICell pointer representing the cell that was clicked
	*/
	virtual void CheckCell(CellPtr cell) = 0;

	/*!
		Method that checks and counts the number of adjacent mines around a given cell. \n\n
		- Iterates through the cells surrounding the specified cell 
  		- Increments the adjacent mine count for the given cell if any of the surrounding cells contain a mine or a flagged mine
		- Checks all possible adjacent cells 

		\param cell is an ICell pointer representing the cell to check for adjacent mines
		Implemented in MinesweeperGame, private method.
	*/
	virtual void CheckAdjacentMines(CellPtr cell) = 0;

	/*!
		Method to calculate the number of mines adjacent to the given cell.
		- Iterates over all neighboring cells and checks their states
		- Increments the count of adjacent mines in the given cell if a mine is found
		\param cell is an ICell pointer representing the cell to check for adjacent mines
	*/
	virtual void FlagCell(CellPtr cell) = 0;

	/*!
 		Method to set the settings of the game:
		- Sets the game window's width and height
		- Sets the game's number of mines
		- Sets the game's theme
		- Loops through the listeners and calls the OnSettingsUpdated method
		\param width is an integer representing the width of the game window
		\param height is an integer representing the height of the game window
		\param minesNumber is an integer representing the number of mines in the game
		\param theme is a string representing the theme of the game
		\param timer is an integer representing the timer of the game
	*/
	virtual void SetSettings(int width, int height, int minesNumber, std::string theme, int timer) = 0;

	/*******************************************//**
 	*  Method to set the strategy of the game:
		- Sets the game's strategy to the given strategy
		- Calls the SetSettings method of the strategy

		\param strategy is an IStrategy pointer that represents the strategy to be set
 	***********************************************/
	virtual void SetStrategy(IStrategyPtr strategy) = 0;

	/*******************************************//**
 	*  Method to set the difficulty of the game:
		- Sets the game's strategy to the strategy corresponding to the given difficulty
		- Calls the SetSettings method of the strategy

		\param difficulty is an EDifficulty arguments that represents the difficulty which will set the strategy
 	***********************************************/
	virtual void SetStrategy(EDifficulty difficulty) = 0;

public:
	/*! Getter method that returns the game's current theme. */
	virtual std::string GetTheme() const = 0;

	/*! Getter method that returns the game's timer. */
	virtual int GetTimer() = 0;

	/*! Getter method that returns the game's width. */
	virtual int GetWidth() = 0;

	/*! Getter method that returns the game's height. */
	virtual int GetHeight() = 0;

	/*! Getter method that returns the number of flags within the game. */
	virtual int GetFlagsNumber() = 0;

	/*******************************************//**
 	*  Getter method that returns the Cell at the specified row and column.
		\param row is an integer representing the row of the cell
		\param column is an integer representing the column of the cell
 	***********************************************/
	virtual CellPtr GetCell(int row, int column) = 0;

public:
	/*! Method to create a game instance, used so that the UI only interacts with the game through the interface. */
	static IGamePtr CreateGame();
};
