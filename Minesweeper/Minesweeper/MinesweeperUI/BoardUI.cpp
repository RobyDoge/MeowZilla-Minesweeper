#include "BoardUI.h"

BoardUI::BoardUI(int width, int height, std::string theme, QWidget* window)
{
	m_window = window;
	InitializeCells(width, height, theme);
}

void BoardUI::GenerateBoard(std::string theme)
{
	int cellSize = 30;
	int xOffset = 10;
	int yOffset = 80;
	std::string path = "../../Assets/" + theme + "/Unrevealed.png";
	QPixmap cellImage = QPixmap(QString::fromStdString(path)).scaled(30, 30, Qt::KeepAspectRatio, Qt::SmoothTransformation);

	for (int row = 0; row < m_cells.size(); row++)
	{
		for (int column = 0; column < m_cells[0].size(); column++)
		{
			QLabel* cell = m_cells[row][column];
			cell->setPixmap(cellImage);
			cell->setFixedSize(cellSize, cellSize);
			cell->move(xOffset + column * cellSize, yOffset + row * cellSize);
			cell->show();
		}
	}
}

void BoardUI::ChangeCellImage(CellPtr cell, EGameState gameState, std::string theme)
{
	QPixmap revealedImage;
	ECellState cellState = cell->GetState();
	std::string path = "../../Assets/" + theme;
	
	switch (cellState)
	{
	case ECellState::UNREVEALED:
		path += "/Unrevealed.png";
		break;
	case ECellState::FLAGGED:
		path += "/Flagged.png";
		break;
	case ECellState::FLAGGED_MINE:
		path += "/Flagged.png";
		break;

	case ECellState::REVEALED:
	{
		int adjacentMines = cell->GetAdjacentMines();
		switch (adjacentMines)
		{
		case 0:
			path += "/Revealed0.png";
			break;
		case 1:
			path += "/Revealed1.png";
			break;
		case 2:
			path += "/Revealed2.png";
			break;
		case 3:
			path += "/Revealed3.png";
			break;
		case 4:
			path += "/Revealed4.png";
			break;
		case 5:
			path += "/Revealed5.png";
			break;
		case 6:
			path += "/Revealed6.png";
			break;
		case 7:
			path += "/Revealed7.png";
			break;
		case 8:
			path += "/Revealed8.png";
			break;
		}
		break;
	}

	case ECellState::MINE:
		if (gameState == EGameState::INGAME)
			path += "/Unrevealed.png";
		if (gameState == EGameState::GAMEOVER)
			path += "/Mine.png";
		if (gameState == EGameState::WIN)
			path += "/Flagged.png";
		break;
	}

	revealedImage = QPixmap(QString::fromStdString(path)).scaled(30, 30, Qt::KeepAspectRatio, Qt::SmoothTransformation);

	m_cells[cell->GetRow()][cell->GetColumn()]->setPixmap(revealedImage);
	m_cells[cell->GetRow()][cell->GetColumn()]->setFixedSize(revealedImage.size());
}

QLabel* BoardUI::GetCell(int row, int column)
{
	return m_cells[row][column];
}

void BoardUI::InitializeCells(int width, int height, std::string theme)
{
	for (int row = 0; row < m_cells.size(); row++) 
		for (int col = 0; col < m_cells[row].size(); col++) 
			delete m_cells[row][col];  
	m_cells.clear();
	std::vector<std::vector<QLabel*>> cells;
	for (int row = 0; row < height; row++)
	{
		std::vector<QLabel*> line;
		for (int column = 0; column < width; column++)
		{
			QLabel* cell = new QLabel(m_window);
			cell->installEventFilter(m_window);
			line.push_back(cell);
		}
		cells.push_back(line);
	}
	m_cells = cells;
	GenerateBoard(theme);
}
