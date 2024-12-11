#pragma once

#include "IMinesweeperListener.h"
#include "ICell.h"
#include "IStrategy.h"
#include<memory>

using IGamePtr = std::shared_ptr<class IMinesweeperGame>;

//! Interface class for the Minesweeper game
class IMinesweeperGame
{
public:
	//! Method to add a listener IMinesweeperListener pointer to the game
	virtual bool AddMinesweeperListener(IMinesweeperListener* listener) = 0;
	//! Method to remove a listener IMinesweeperListener pointer from the game
	virtual bool RemoveMinesweeperListener(IMinesweeperListener* listener) = 0;

public:
	//! Method to generate mines based on the clicked Cell row and column
	virtual void GenerateMines(int clickedCellRow, int clickedCellColumn) = 0;
	//! Method to restart the game
	virtual void RestartGame() = 0;
	//! Method to end the game: changed state to GAMEOVER and calls EndGame method
	virtual void GameOver() = 0;
	/*******************************************//**
 	*  Method to check if the game is won by checking if all mines are flagged \n\n
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
		Notifies registered listeners about timer changes.
		If the timer reaches zero or the game state changes to a terminal state (not WIN or FIRSTCLICK), the game ends. \n\n
		Implemented in MinesweeperGame, private method.
	*/
	virtual void CountdownTimer() = 0;
	//! Method to set the cells to unrevealed
	virtual void RevealCells(CellPtr cell) = 0;
	/*!
		This method handles the behavior when a cell in the game is clicked. 
		It checks the state of the game and the cell and performs appropriate actions such as revealing cells, generating mines, or ending the game.
	*/
	virtual void CheckCell(CellPtr cell) = 0;
	//! Method to check the adjacent cells of a cell
	//! Implemented in MinesweeperGame, private method.
	virtual void CheckAdjacentMines(CellPtr cell) = 0;
	/*!
		Method to calculate the number of mines adjacent to the given cell.
		It iterates over all neighboring cells, checks their states, and increments the count of adjacent mines in the given cell if a mine is found. 
	*/
	virtual void FlagCell(CellPtr cell) = 0;
	/*!
 		Method to set the settings of the game:
		- Sets the game window's width and height
		- Sets the game's number of mines
		- Sets the game's theme
		- Loops through the listeners and calls the OnSettingsUpdated method
	*/
	virtual void SetSettings(int width, int height, int minesNumber, std::string theme, int timer) = 0;
	/*!
		Method to set the strategy of the game:
		- Sets the game's strategy to the given strategy
		- Calls the SetSettings method of the strategy
		- Loops through the listeners and calls the OnSettingsUpdated method
	*/
	virtual void SetStrategy(IStrategyPtr strategy) = 0;

public:
	//! Getter method that returns the game's current theme
	virtual std::string GetTheme() const = 0;
	//! Getter method that returns the game's timer
	virtual int GetTimer() = 0;
	//! Getter method that returns the game's width
	virtual int GetWidth() = 0;
	//! Getter method that returns the game's height
	virtual int GetHeight() = 0;
	//! Getter method that returns the number of flags within the game
	virtual int GetFlagsNumber() = 0;
	//! Getter method that returns the Cell at the specified row and column
	virtual CellPtr GetCell(int row, int column) = 0;

public:
	//! Method to create a game instance, used so that the UI only interacts with the game through the interface
	static IGamePtr CreateGame();
};
