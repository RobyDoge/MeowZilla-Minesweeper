#include "MinesweeperListenerUI.h"
#include "MinesweeperUI.h"

void MinesweeperListenerUI::OnGameOver()
{
	emit GameOver();
}


void MinesweeperListenerUI::OnWin()
{
	QMessageBox msgBox;
	msgBox.setWindowTitle("Victory!!!");
	msgBox.setText("Congratulations! You won!");
	msgBox.setIcon(QMessageBox::Information);
	msgBox.exec();
}

void MinesweeperListenerUI::OnSettingsUpdated(int width, int height, int minesNumber, std::string theme, int timer)
{
	emit FlagsChanged(minesNumber);
	emit TimerChanged(timer);
	emit SettingsChanged(width, height, theme);
}

void MinesweeperListenerUI::OnCellImageChange(MinesweeperCell* cell, EGameState gameState, std::string theme)
{
	emit CellImageChanged(cell, gameState, theme);
}

void MinesweeperListenerUI::OnFlagCountChanged(int flagsNumber)
{
	emit FlagsChanged(flagsNumber);
}

void MinesweeperListenerUI::OnTimerChanged(int timer)
{
	emit TimerChanged(timer);
	if (timer == 0)
		emit GameOver();
}
