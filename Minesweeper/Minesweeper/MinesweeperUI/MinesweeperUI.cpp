#include "MinesweeperUI.h"
#include <memory>
#include <QPushButton>
#include <QMouseEvent>

MinesweeperUI::MinesweeperUI(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowTitle("Minesweeper");
	auto game = IMinesweeperGame::CreateGame();
	m_minesweeperGame = game;

	m_board = new BoardUI(m_minesweeperGame->GetWidth(), m_minesweeperGame->GetHeight(), m_minesweeperGame->GetTheme(), this);

	m_infoDisplay = new MinesweeperInfoDisplay(m_minesweeperGame->GetFlagsNumber(), m_minesweeperGame->GetTimer(), this);
	CreateRestartButton();
	ResizeWindow();

	CreateMenuBar();
}

MinesweeperUI::~MinesweeperUI()
{}


void MinesweeperUI::CreateRestartButton()
{
	m_restartButton = new QPushButton(this);
	ChangeRestartButton();

	connect(m_restartButton, &QPushButton::clicked, this, &MinesweeperUI::OnRestartClicked);
}

void MinesweeperUI::CreateMenuBar()
{
	QMenuBar* menuBar = new QMenuBar(this);

	QMenu* gameMenu = menuBar->addMenu("Game");

	QAction* configureAction = gameMenu->addAction("Configure...");
	connect(configureAction, &QAction::triggered, this, &MinesweeperUI::OpenConfigDialog);

	setMenuBar(menuBar);
}

void MinesweeperUI::OpenConfigDialog()
{
	MinesweeperConfigDialog configDialog(this);
	if (configDialog.exec() == QDialog::Accepted)
	{
		// Preluăm valorile și configurăm jocul
		int width = configDialog.GetWidth();
		int height = configDialog.GetHeight();
		int mines = configDialog.GetMines();
		std::string theme = configDialog.GetTheme().toStdString();
		int timer = configDialog.GetTimer() ;

		m_minesweeperGame->SetSettings(width, height, mines, theme, timer);
		m_minesweeperGame->RestartGame();
	}
}



void MinesweeperUI::OnRestartClicked()
{
	m_minesweeperGame->RestartGame();
	m_board->GenerateBoard(m_minesweeperGame->GetTheme());
}

void MinesweeperUI::OnCellLeftClick(int row, int column)
{
	CellPtr cell = m_minesweeperGame->GetCell(row, column);
	m_minesweeperGame->CheckCell(cell);
}

void MinesweeperUI::OnCellRightClick(int row, int column)
{
	CellPtr cell = m_minesweeperGame->GetCell(row, column);
	m_minesweeperGame->FlagCell(cell);
}

void MinesweeperUI::ChangeRestartButton()
{
	std::string path = "../../Assets/" + m_minesweeperGame->GetTheme() + "/RestartButton.png";
	QIcon buttonIcon(QString::fromStdString(path));
	m_restartButton->setIcon(buttonIcon);

	m_restartButton->setIconSize(QSize(50, 50));
	m_restartButton->setFixedSize(50, 50);
}

void MinesweeperUI::ResizeWindow()
{
	m_windowWidth = m_minesweeperGame->GetWidth() * 30 + 20;
	m_windowHeight = m_minesweeperGame->GetHeight() * 30 + 60 + 80;
	resize(m_windowWidth, m_windowHeight);


	int windowWidth = this->width();
	int xPosition = (windowWidth - m_restartButton->width()) / 2;
	int yPosition = 25;

	m_restartButton->setGeometry(xPosition, yPosition, m_restartButton->width(), m_restartButton->height());
}




bool MinesweeperUI::eventFilter(QObject* obj, QEvent* event)
{
	if (event->type() == QEvent::MouseButtonPress)
	{
		QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event); // Cast la QMouseEvent pentru a accesa detalii despre eveniment
		QLabel* cell = qobject_cast<QLabel*>(obj);
		if (cell)
			for (int row = 0; row < m_minesweeperGame->GetHeight(); row++)
				for (int col = 0; col < m_minesweeperGame->GetWidth(); col++)
					if (m_board->GetCell(row, col) == cell)
					{
						if (mouseEvent->button() == Qt::LeftButton) // Verifică dacă este butonul stâng al mouse-ului
							OnCellLeftClick(row, col);
						if (mouseEvent->button() == Qt::RightButton)
							OnCellRightClick(row, col);

						return true; // Evenimentul a fost gestionat
					}
	}

	return QMainWindow::eventFilter(obj, event); // Permite ca evenimentul să fie procesat mai departe
}

IGamePtr MinesweeperUI::GetMinesweeperGame()
{
	return m_minesweeperGame;
}

BoardUI* MinesweeperUI::GetBoard()
{
	return m_board;
}

MinesweeperInfoDisplay* MinesweeperUI::GetInfoDisplay()
{
	return m_infoDisplay;
}


