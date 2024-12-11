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

public:
	void SetWidth(int width);
	void SetHeight(int height);
	void SetMinesNumber(int minesNumber);
	void SetTheme(const std::string& theme);
	void SetTimer(int timer);
	std::string GetTheme() const;
	int GetTimer() override;
	int GetWidth() override;
	int GetHeight() override;
	std::vector<std::vector<CellPtr>> GetCells();
	CellPtr GetCell(int row, int column) override;
	EGameState GetGameState();
	int GetFlagsNumber() override;

private:
	void CheckAdjacentMines(CellPtr cell) override;
	void SetUnrevealedCells();
	bool IsOutOfBounds(int row, int column);
	void GameOver() override;
	void CheckVictory() override;
	void EndGame() override;
	void CountdownTimer() override;

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
};

