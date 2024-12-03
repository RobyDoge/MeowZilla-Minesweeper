#include "MinesweeperInfoDisplay.h"

MinesweeperInfoDisplay::MinesweeperInfoDisplay(int flagsNumber, int timer, QWidget* window)
{
	m_window = window;
	m_flagsLabel = new QLabel(window);
	UpdateFlagsLabel(flagsNumber);
	m_flagsLabel->setAlignment(Qt::AlignLeft);
	m_flagsLabel->setFixedSize(200, 20);
	m_flagsLabel->move(10, 40); // Ajusteaza valoarea Y în functie de design

	m_timerLabel = new QLabel(window);
	UpdateTimerLabel(timer);
	m_timerLabel->setAlignment(Qt::AlignRight);
	m_timerLabel->setFixedSize(100, 20);
	m_timerLabel->move(m_window->size().width()-110, 40); // Ajusteaza valoarea Y în functie de design

	m_gameOverMessage.setWindowTitle("Game Over");
	m_gameOverMessage.setText("YOU LOST!!!! Better luck next time! >:)");
	m_gameOverMessage.setIcon(QMessageBox::Critical);
	m_gameOverMessage.addButton("Close", QMessageBox::RejectRole);

}

void MinesweeperInfoDisplay::UpdateTimerLabel(int timer)
{
	if (timer == -1)
		m_timerLabel->setVisible(false);
	else
		m_timerLabel->setVisible(true);
	m_timerLabel->setText(QString("Time left: %1").arg(timer));
	m_timerLabel->move(m_window->size().width() - 110, 40); // Ajusteaza valoarea Y în functie de design
}

void MinesweeperInfoDisplay::GameOver()
{
	m_gameOverMessage.exec();
}

void MinesweeperInfoDisplay::UpdateFlagsLabel(int flagsNumber)
{
	m_flagsLabel->setText(QString("Flags left: %1").arg(flagsNumber));
}