#include "MinesweeperUI.h"
#include <QtWidgets/QApplication>
#include "MinesweeperListenerUI.h"
#include "MinesweeperInfoDisplay.h"
#include <MinesweeperGame.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MinesweeperUI w;
    w.show();
    MinesweeperListenerUI listener;
    MinesweeperGame* minesweeperGame = w.GetMinesweeperGame();
    BoardUI* board = w.GetBoard();
    MinesweeperInfoDisplay* infoDisplay = w.GetInfoDisplay();
    w.connect(&listener, &MinesweeperListenerUI::CellImageChanged, board, &BoardUI::ChangeCellImage);
    w.connect(&listener, &MinesweeperListenerUI::FlagsChanged, infoDisplay, &MinesweeperInfoDisplay::UpdateFlagsLabel);
    w.connect(&listener, &MinesweeperListenerUI::TimerChanged, infoDisplay, &MinesweeperInfoDisplay::UpdateTimerLabel);
    w.connect(&listener, &MinesweeperListenerUI::SettingsChanged, board, &BoardUI::InitializeCells);
    w.connect(&listener, &MinesweeperListenerUI::SettingsChanged, &w, &MinesweeperUI::ResizeWindow);
    w.connect(&listener, &MinesweeperListenerUI::SettingsChanged, &w, &MinesweeperUI::ChangeRestartButton);
    w.connect(&listener, &MinesweeperListenerUI::GameOver, infoDisplay, &MinesweeperInfoDisplay::GameOver);
    minesweeperGame->AddMinesweeperListener(&listener);
    return a.exec();
}
