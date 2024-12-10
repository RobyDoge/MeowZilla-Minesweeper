#pragma once
#include "MinesweeperCell.h"
#include "EGameState.h"
#include <vector>
#include <qlabel.h>
class BoardUI : public QWidget
{
public:
	BoardUI(int width, int height, std::string theme, QWidget* window);
	void GenerateBoard(std::string theme);
	QLabel* GetCell(int row, int column);

private:
	std::vector<std::vector<QLabel*>> m_cells;
	QWidget* m_window;

public slots:
	void ChangeCellImage(CellPtr cell, EGameState state, std::string theme);
	void InitializeCells(int width, int height, std::string theme);
};

