#pragma once

#include "IMinesweeperListener.h"
#include "MinesweeperCell.h"

class IMinesweeperGame
{
public:
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
};
