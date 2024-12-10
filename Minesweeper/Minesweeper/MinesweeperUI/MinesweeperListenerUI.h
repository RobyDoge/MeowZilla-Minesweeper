#pragma once
#include "IMinesweeperListener.h"
#include "EGameState.h"
#include <qobject.h>

class MinesweeperListenerUI : public QObject, public IMinesweeperListener
{
    Q_OBJECT

    void OnCellImageChange(CellPtr cell, EGameState gameState, std::string theme) override;
    void OnFlagCountChanged(int flagsNumber) override;
    void OnTimerChanged(int timer) override;
    void OnGameOver() override;
    void OnWin() override;
    void OnSettingsUpdated(int width, int height, int minesNumber, std::string theme, int timer) override;

signals:
    void CellImageChanged(CellPtr cell, EGameState gameState, std::string theme);
    void FlagsChanged(int flagsNumber);
    void TimerChanged(int timer);
    void SettingsChanged(int width, int height, std::string theme);
    void GameOver();
};