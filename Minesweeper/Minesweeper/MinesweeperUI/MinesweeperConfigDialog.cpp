#include "MinesweeperConfigDialog.h"
#include "Themes.h"
#include <QVBoxLayout>
#include <QLabel>

MinesweeperConfigDialog::MinesweeperConfigDialog(QWidget* parent)
	: QDialog(parent)
{
	setWindowTitle("Game Configuration");
	QVBoxLayout* layout = new QVBoxLayout(this);

	// Dimensiuni
	layout->addWidget(new QLabel("Width:"));
	m_widthSpinBox = new QSpinBox(this);
	m_widthSpinBox->setRange(7, 40); // Valori între 8 și 15
	m_widthSpinBox->setValue(10);    // Valoare implicită
	layout->addWidget(m_widthSpinBox);

	layout->addWidget(new QLabel("Height:"));
	m_heightSpinBox = new QSpinBox(this);
	m_heightSpinBox->setRange(7, 20); // Valori între 8 și 15
	m_heightSpinBox->setValue(10);    // Valoare implicită
	layout->addWidget(m_heightSpinBox);

	// Bombe
	layout->addWidget(new QLabel("Bombs:"));
	m_minesSpinBox = new QSpinBox(this);
	m_minesSpinBox->setValue(10);
	UpdateMineRange(); // Setăm limita inițială în funcție de dimensiunile implicite
	layout->addWidget(m_minesSpinBox);

	// Tema
	layout->addWidget(new QLabel("Theme:"));
	m_themeComboBox = new QComboBox(this);
	m_themeComboBox->addItems({
		QString::fromStdString(DARK_BLUE),
		QString::fromStdString(STARRY_SKY),
		QString::fromStdString(AURORA_BOREALIS),
		QString::fromStdString(CHRISTMAS)});

	layout->addWidget(m_themeComboBox);

	// Timer
	m_timerCheckBox = new QCheckBox("Enable Timer", this);
	m_timerCheckBox->setChecked(false); // Timer activat implicit
	layout->addWidget(m_timerCheckBox);

	layout->addWidget(new QLabel("Timer (seconds):"));
	m_timerSpinBox = new QSpinBox(this);
	m_timerSpinBox->setRange(15, 999); // Interval între 15 și 600 secunde
	m_timerSpinBox->setValue(60);      // Valoare implicită
	m_timerSpinBox->setEnabled(false);
	layout->addWidget(m_timerSpinBox);

	// Dezactivează timer-ul dacă checkbox-ul este debifat
	connect(m_timerCheckBox, &QCheckBox::toggled, m_timerSpinBox, &QSpinBox::setEnabled);

	// Butoane
	QPushButton* okButton = new QPushButton("OK", this);
	connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
	layout->addWidget(okButton);

	// Conectăm spinbox-ul pentru bombe să actualizeze limita dinamică în funcție de dimensiuni
	connect(m_widthSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &MinesweeperConfigDialog::UpdateMineRange);
	connect(m_heightSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &MinesweeperConfigDialog::UpdateMineRange);
}

int MinesweeperConfigDialog::GetWidth() const { return m_widthSpinBox->value(); }
int MinesweeperConfigDialog::GetHeight() const { return m_heightSpinBox->value(); }
int MinesweeperConfigDialog::GetMines() const { return m_minesSpinBox->value(); }
QString MinesweeperConfigDialog::GetTheme() const { return m_themeComboBox->currentText(); }

int MinesweeperConfigDialog::GetTimer() const
{
	return m_timerCheckBox->isChecked() ? m_timerSpinBox->value() : -1;
} // Returnează -1 dacă timer-ul este dezactivat

void MinesweeperConfigDialog::UpdateMineRange()
{
	int width = m_widthSpinBox->value();
	int height = m_heightSpinBox->value();
	int maxMines = (width * height) / 2; // Maxim jumătate din numărul total de celule
	m_minesSpinBox->setRange(maxMines/5, maxMines);
	m_minesSpinBox->setValue(std::min(m_minesSpinBox->value(), maxMines)); // Păstrează valoarea curentă dacă e validă
}
