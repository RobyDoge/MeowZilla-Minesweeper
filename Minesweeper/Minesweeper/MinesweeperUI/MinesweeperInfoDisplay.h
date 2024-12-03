#pragma once

#include <qlabel.h>
#include <QMessageBox>
class MinesweeperInfoDisplay : public QWidget
{
public:
	MinesweeperInfoDisplay(int flagsNumber, int timer, QWidget* window);

private:
	QLabel* m_flagsLabel;
	QLabel* m_timerLabel;
	QWidget* m_window;
	QMessageBox m_gameOverMessage;

public slots:
	void UpdateFlagsLabel(int flagsNumber);
	void UpdateTimerLabel(int timer);
	void GameOver();
};
