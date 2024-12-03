#pragma once

#include "IMinesweeperGame.h"
#include "EGameState.h"
#include <vector>
#include <stdlib.h>    
#include <time.h> 
#include <queue>
#include <string>
#include <thread>

class MinesweeperGame:public IMinesweeperGame
{
public:

	MinesweeperGame();

	bool AddMinesweeperListener(IMinesweeperListener* listener) override;
	bool RemoveMinesweeperListener(IMinesweeperListener* listener) override;
	void GenerateMines(int clickedCellRow, int clickedCellColumn) override;
	void RestartGame() override;
	void RevealCells(MinesweeperCell* cell) override;
	void CheckCell(MinesweeperCell* cell) override;
	void FlagCell(MinesweeperCell* cell) override;
	void SetSettings(int width, int height, int minesNumber, std::string theme, int timer) override;

	// Adaugã aceste metode în MinesweeperGame.h
	void SetWidth(int width);
	void SetHeight(int height);
	void SetMinesNumber(int minesNumber);
	void SetTheme(const std::string& theme);
	void SetTimer(int timer);
	std::string GetTheme();
	int GetTimer();
	int GetWidth();
	int GetHeight();
	std::vector<std::vector<MinesweeperCell>> GetCells();
	MinesweeperCell* GetCell(int row, int column);
	EGameState GetGameState();
	int GetFlagsNumber();

private:
	void CheckAdjacentMines(MinesweeperCell* cell) override;
	void SetUnrevealedCells();
	bool isOutOfBounds(int row, int column);
	void GameOver() override;
	void CheckVictory() override;
	void EndGame() override;
	void CountdownTimer() override;

	std::vector<IMinesweeperListener*> m_listeners;
	std::vector<std::vector<MinesweeperCell>> m_cells;
	EGameState m_gameState;
	int m_width;
	int m_height;
	int m_minesNumber;
	std::string m_theme;
	int m_timer;
	int m_flagsNumber;
	int m_revealedCells;
};

