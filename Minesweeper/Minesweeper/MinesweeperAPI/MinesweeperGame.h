#pragma once

#include "IMinesweeperGame.h"
#include "EGameState.h"
#include <vector>
#include <stdlib.h>    
#include <time.h> 
#include <queue>
#include <string>
#include <thread>

//! Class that implements the IMinesweeperGame interface.
class MinesweeperGame:public IMinesweeperGame
{
public:
	/*!  Constructor for the Game that initializes private members, sets cells to unrevealed and resets listeners. */
	MinesweeperGame();

public:

	bool AddMinesweeperListener(IMinesweeperListener* listener) override;
	bool RemoveMinesweeperListener(IMinesweeperListener* listener) override;
	void GenerateMines(int clickedCellRow, int clickedCellColumn) override;
	void RestartGame() override;
	void RevealCells(CellPtr cell) override;
	void CheckCell(CellPtr cell) override;
	void FlagCell(CellPtr cell) override;
	void SetSettings(int width, int height, int minesNumber, std::string theme, int timer) override;
	void SetStrategy(IStrategyPtr strategy) override;
	void SetStrategy(EDifficulty difficulty) override;

public:
	/*! Method to set the game's width.
		\param width is an integer representing the width of the game window
	*/
	void SetWidth(int width);
	/*! Method to set the game's height.
		\param height is an integer representing the height of the game window
	*/
	void SetHeight(int height);
	/*! Method to set the game's number of mines.
		\param minesNumber is an integer representing the number of mines in the game
	*/
	void SetMinesNumber(int minesNumber);

	/*! Method to set the game's theme.
		\param theme is a string representing the theme of the game
	*/
	void SetTheme(const std::string& theme);

	/*! Method to set the game's timer.
		\param timer is an integer representing the timer of the game
	*/
	void SetTimer(int timer);
	/*! Getter method that returns the game's theme. */
	std::string GetTheme() const;
	int GetTimer() override;
	int GetWidth() override;
	int GetHeight() override;
	/*! Getter method that returns the game's cells stored in a matrix of CellPtr. */
	std::vector<std::vector<CellPtr>> GetCells();
	CellPtr GetCell(int row, int column) override;
	/*! Getter method that returns the game's state stored as an EGameState value. */
	EGameState GetGameState();
	int GetFlagsNumber() override;

private:
	void ResetListeners();
	void CheckAdjacentMines(CellPtr cell) override;
	void SetUnrevealedCells();
	bool IsOutOfBounds(int row, int column);
	void GameOver() override;
	void CheckVictory() override;
	void EndGame() override;
	void CountdownTimer() override;
	void SetSettings(); //this is called for when a strategy is selected

	std::vector<IMinesweeperListener*> m_listeners;
	std::vector<std::vector<CellPtr>> m_cells;
	EGameState m_gameState;
	int m_width;
	int m_height;
	int m_minesNumber;
	std::string m_theme;
	int m_timer;
	int m_flagsNumber;
	int m_revealedCells;

	IStrategyPtr m_strategy;
};

