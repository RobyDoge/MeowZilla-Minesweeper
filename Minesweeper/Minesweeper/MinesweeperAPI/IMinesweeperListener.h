#pragma once
#include "MinesweeperCell.h"
#include "EGameState.h"
#include <string>

class IMinesweeperListener
{
public:
	virtual void OnCellImageChange(MinesweeperCell* cell, EGameState gameState, std::string theme) = 0;
	virtual void OnFlagCountChanged(int flagsNumber) = 0;
	virtual void OnTimerChanged(int timer) = 0;
	virtual void OnGameOver() = 0;
	virtual void OnWin() = 0;
	virtual void OnSettingsUpdated(int width, int height, int minesNumber, std::string theme, int timer) = 0;
	virtual ~IMinesweeperListener() = default;
};