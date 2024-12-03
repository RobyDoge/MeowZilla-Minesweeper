#pragma once

#include <QDialog>
#include <QSpinBox>
#include <QComboBox>
#include <QCheckBox>
#include <QPushButton>

class MinesweeperConfigDialog : public QDialog
{
	Q_OBJECT

public:
	MinesweeperConfigDialog(QWidget* parent = nullptr);

	int GetWidth() const;
	int GetHeight() const;
	int GetMines() const;
	QString GetTheme() const;
	int GetTimer() const; // Returneazã 0 dacã timer-ul este dezactivat

private slots:
	void UpdateMineRange();

private:
	QSpinBox* m_widthSpinBox;
	QSpinBox* m_heightSpinBox;
	QSpinBox* m_minesSpinBox;
	QComboBox* m_themeComboBox;
	QSpinBox* m_timerSpinBox;
	QCheckBox* m_timerCheckBox;
};
