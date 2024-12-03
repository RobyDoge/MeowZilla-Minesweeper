﻿#include "MinesweeperGame.h"

MinesweeperGame::MinesweeperGame()
{
	m_width = 10;
	m_height = 10;
	m_minesNumber = 10;
	m_flagsNumber = m_minesNumber;
	m_gameState = EGameState::FIRSTCLICK;
	m_theme = "Dark Blue";
	m_timer = -1;
	SetUnrevealedCells();
}

bool MinesweeperGame::AddMinesweeperListener(IMinesweeperListener* listener)
{
	m_listeners.push_back(listener);

	return true;
}

bool MinesweeperGame::RemoveMinesweeperListener(IMinesweeperListener* listener)
{
	for (auto it = m_listeners.begin(); it != m_listeners.end(); ++it)
	{
		if (*it == listener)
		{
			m_listeners.erase(it);
			return true;
		}
	}

	return false;
}

void MinesweeperGame::GenerateMines(int clickedCellRow, int clickedCellColumn)//redenumire
{
	srand(time(NULL));
	int xPos, yPos;
	m_gameState = EGameState::INGAME;

	int indexMine = 0;
	while (indexMine < m_minesNumber)
	{
		xPos = rand() % m_height;
		yPos = rand() % m_width;
		if (xPos != clickedCellRow && yPos != clickedCellColumn)
		{
			if (m_cells[xPos][yPos].GetState() == ECellState::UNREVEALED) // se va adauga conditie sa nu se genereze mina pe click
			{
				m_cells[xPos][yPos].SetState(ECellState::MINE);
				indexMine++;
			}
			if (m_cells[xPos][yPos].GetState() == ECellState::FLAGGED) // se va adauga conditie sa nu se genereze mina pe click
			{
				m_cells[xPos][yPos].SetState(ECellState::FLAGGED_MINE);
				indexMine++;
			}
		}
	}
	if (m_timer != -1)
		CountdownTimer();
}

void MinesweeperGame::RestartGame()
{
	SetUnrevealedCells();
	m_flagsNumber = m_minesNumber;
	m_revealedCells = 0;
	m_gameState = EGameState::FIRSTCLICK;
	for (auto listener : m_listeners)
	{
		listener->OnFlagCountChanged(m_flagsNumber);
		listener->OnTimerChanged(m_timer);
	}
}

void MinesweeperGame::RevealCells(MinesweeperCell* cell)
{
	std::queue<MinesweeperCell*> filledCells;
	filledCells.push(cell);
	filledCells.back()->SetState(ECellState::REVEALED);
	while (!filledCells.empty())
	{
		CheckAdjacentMines(filledCells.front());
		if (filledCells.front()->GetAdjacentMines() == 0)
			for (int row = filledCells.front()->GetRow() - 1; row <= filledCells.front()->GetRow() + 1; row++)
				for (int column = filledCells.front()->GetColumn() - 1; column <= filledCells.front()->GetColumn() + 1; column++)
					if (!isOutOfBounds(row, column))
						if (!(row == filledCells.front()->GetRow() && column == filledCells.front()->GetColumn())
							&& (m_cells[row][column].GetState() == ECellState::UNREVEALED || m_cells[row][column].GetState() == ECellState::FLAGGED))
						{
							if (m_cells[row][column].GetState() == ECellState::FLAGGED)
							{
								m_flagsNumber++;
								for (auto listener : m_listeners)
								{
									listener->OnFlagCountChanged(m_flagsNumber);
								}
							}
							filledCells.push(&m_cells[row][column]);
							if (m_cells[row][column].GetState() == ECellState::FLAGGED)
								m_flagsNumber++;
							filledCells.back()->SetState(ECellState::REVEALED);
						}
		for (auto listener : m_listeners)
		{
			listener->OnCellImageChange(filledCells.front(), m_gameState, m_theme);
			listener->OnFlagCountChanged(m_flagsNumber);
		}
		m_revealedCells++;
		filledCells.pop();
	}
}

void MinesweeperGame::CheckCell(MinesweeperCell* cell)
{
	if (m_gameState == EGameState::FIRSTCLICK || m_gameState == EGameState::INGAME)
		if (cell->GetState() == ECellState::UNREVEALED)
		{
			if (m_revealedCells == 0)
				GenerateMines(cell->GetRow(), cell->GetColumn());
			RevealCells(cell);
			CheckVictory();
		}
		else if (cell->GetState() == ECellState::MINE)
		{
			GameOver();
		}


}

void MinesweeperGame::CheckAdjacentMines(MinesweeperCell* cell)
{
	for (int x = cell->GetRow() - 1; x <= cell->GetRow() + 1; x++)
		for (int y = cell->GetColumn() - 1; y <= cell->GetColumn() + 1; y++)
			if (!isOutOfBounds(x, y))
				if (m_cells[x][y].GetState() == ECellState::MINE || m_cells[x][y].GetState() == ECellState::FLAGGED_MINE)
					cell->AddAdjacentMine();
}

void MinesweeperGame::FlagCell(MinesweeperCell* cell)
{
	if (m_gameState == EGameState::FIRSTCLICK || m_gameState == EGameState::INGAME)
	{
		bool stateChanged = false;
		if (cell->GetState() == ECellState::UNREVEALED)
		{
			cell->SetState(ECellState::FLAGGED);
			m_flagsNumber--;
			stateChanged = true;
		}
		if (cell->GetState() == ECellState::FLAGGED && !stateChanged)
		{
			cell->SetState(ECellState::UNREVEALED);
			m_flagsNumber++;
		}
		if (cell->GetState() == ECellState::MINE)
		{
			cell->SetState(ECellState::FLAGGED_MINE);
			m_flagsNumber--;
			stateChanged = true;
		}
		if (cell->GetState() == ECellState::FLAGGED_MINE && !stateChanged)
		{
			cell->SetState(ECellState::MINE);
			m_flagsNumber++;
		}

		for (auto listener : m_listeners)
		{
			listener->OnCellImageChange(cell, m_gameState, m_theme);
			listener->OnFlagCountChanged(m_flagsNumber);
		}
	}
	return;
}

void MinesweeperGame::GameOver()
{
	m_gameState = EGameState::GAMEOVER;
	EndGame();
}

void MinesweeperGame::CheckVictory()
{
	if (m_width * m_height - m_revealedCells == m_minesNumber)
	{
		m_gameState = EGameState::WIN;
		EndGame();
	}
}

void MinesweeperGame::EndGame()
{
	for (auto listener : m_listeners)
	{
		for (int row = 0; row < m_height; row++)
			for (int column = 0; column < m_width; column++)
				if (m_cells[row][column].GetState() == ECellState::MINE)
					listener->OnCellImageChange(&m_cells[row][column], m_gameState, m_theme);
		if (m_gameState == EGameState::GAMEOVER)
			listener->OnGameOver();
		else
			listener->OnWin();
	}
}

void MinesweeperGame::CountdownTimer()
{
	std::thread([this]() {
		int currentTimer = m_timer;
		int currentSecond = m_timer;
		auto startTime = std::chrono::system_clock::now();
		auto startTimeMs = std::chrono::time_point_cast<std::chrono::milliseconds>(startTime);
		auto startTimeMsToInt = startTimeMs.time_since_epoch().count();
		while (currentTimer > 0 && m_gameState == EGameState::INGAME)
		{
			auto currentTime = std::chrono::system_clock::now();
			auto currentTimeMs = std::chrono::time_point_cast<std::chrono::milliseconds>(currentTime);
			auto currentTimeMsToInt = currentTimeMs.time_since_epoch().count();
			currentTimer = m_timer - ((currentTimeMsToInt - startTimeMsToInt) / 1000);
			if (m_gameState == EGameState::INGAME && currentTimer != currentSecond)
			{
				for (auto listener : m_listeners)
				{
					listener->OnTimerChanged(currentTimer);
				}
				currentSecond = currentTimer;
			}
		}
		if (m_gameState != EGameState::WIN && m_gameState != EGameState::FIRSTCLICK)
			GameOver();
		}).detach();
}

void MinesweeperGame::SetSettings(int width, int height, int minesNumber, std::string theme, int timer)
{
	SetWidth(width);
	SetHeight(height);
	SetMinesNumber(minesNumber);
	SetTheme(theme);
	SetTimer(timer);
	for (auto listener : m_listeners)
	{
		listener->OnSettingsUpdated(width, height, minesNumber, theme, timer);
	}
}

void MinesweeperGame::SetUnrevealedCells()
{
	m_cells.clear();

	for (int row = 0; row < m_height; row++)
	{
		std::vector<MinesweeperCell> line;

		for (int column = 0; column < m_width; column++)
			line.push_back(MinesweeperCell(row, column));

		m_cells.push_back(line);
	}
}

bool MinesweeperGame::isOutOfBounds(int row, int column)
{
	if (row < 0 || row >= m_height || column < 0 || column >= m_width)
		return true;
	return false;
}

int MinesweeperGame::GetWidth()
{
	return m_width;
}

int MinesweeperGame::GetHeight()
{
	return m_height;
}

std::vector<std::vector<MinesweeperCell>> MinesweeperGame::GetCells()
{
	return m_cells;
}

MinesweeperCell* MinesweeperGame::GetCell(int row, int column)
{
	return &m_cells[row][column];
}

EGameState MinesweeperGame::GetGameState()
{
	return m_gameState;
}

int MinesweeperGame::GetFlagsNumber()
{
	return m_flagsNumber;
}

void MinesweeperGame::SetWidth(int width)
{
	m_width = width;
}

void MinesweeperGame::SetHeight(int height)
{
	m_height = height;
}

void MinesweeperGame::SetMinesNumber(int minesNumber)
{
	m_minesNumber = minesNumber;
}

void MinesweeperGame::SetTheme(const std::string& theme)
{
	m_theme = theme;
}

void MinesweeperGame::SetTimer(int timer)
{
	m_timer = timer;
}

std::string MinesweeperGame::GetTheme()
{
	return m_theme;
}

int MinesweeperGame::GetTimer()
{
	return m_timer;
}

