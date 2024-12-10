#pragma once

#include "IMinesweeperListener.h"
#include "MinesweeperCell.h"
#include<memory>

using IGamePtr = std::shared_ptr<class IMinesweeperGame>;

//! Interface class for the Minesweeper game
class IMinesweeperGame
{
public:
	//! Method to add a listener IMinesweeperListener pointer to the game
	virtual bool AddMinesweeperListener(IMinesweeperListener* listener) = 0;
	virtual bool RemoveMinesweeperListener(IMinesweeperListener* listener) = 0;

	virtual void GenerateMines(int clickedCellRow, int clickedCellColumn) = 0;
	virtual void RestartGame() = 0;
	virtual void GameOver() = 0;
	virtual void CheckVictory() = 0;
	virtual void EndGame() = 0;
	virtual void CountdownTimer() = 0;

	virtual void RevealCells(MinesweeperCell* cell) = 0;
	virtual void CheckCell(MinesweeperCell* cell) = 0;
	virtual void CheckAdjacentMines(MinesweeperCell* cell) = 0;
	virtual void FlagCell(MinesweeperCell* cell) = 0;
	virtual void SetSettings(int width, int height, int minesNumber, std::string theme, int timer) = 0;

public:

	virtual std::string GetTheme() const = 0;
	virtual int GetTimer() = 0;
	virtual int GetWidth() = 0;
	virtual int GetHeight() = 0;
	virtual int GetFlagsNumber() = 0;
	virtual MinesweeperCell* GetCell(int row, int column) = 0;

public:
	static IGamePtr CreateGame();
};
