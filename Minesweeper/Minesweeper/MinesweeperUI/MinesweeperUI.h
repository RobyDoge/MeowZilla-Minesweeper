#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MinesweeperUI.h"
#include "IMinesweeperGame.h"
#include "MinesweeperConfigDialog.h"
#include "MinesweeperInfoDisplay.h"
#include "BoardUI.h"
#include <qlabel.h>
#include <qpixmap.h>
#include <QMessageBox>
#include "IMinesweeperGame.h"

class MinesweeperUI : public QMainWindow
{
    Q_OBJECT

public:
    MinesweeperUI(QWidget *parent = nullptr);
    ~MinesweeperUI();

    IGamePtr GetMinesweeperGame();
    BoardUI* GetBoard();
    MinesweeperInfoDisplay* GetInfoDisplay();

private:
    void CreateRestartButton();
    void CreateMenuBar();
    void OpenConfigDialog();
    void SetEasyGame();
    void SetMediumGame();
	void SetHardGame();
    bool eventFilter(QObject* obj, QEvent* event) override;


    Ui::MinesweeperUIClass ui;
    IGamePtr m_minesweeperGame;
    QPushButton* m_restartButton;

    BoardUI* m_board;
    MinesweeperInfoDisplay* m_infoDisplay;

    int m_windowWidth;
    int m_windowHeight;

private slots:
    void OnRestartClicked();
    void OnCellLeftClick(int row, int col);
    void OnCellRightClick(int row, int col);

public slots:
    void ResizeWindow();
    void ChangeRestartButton();
};
