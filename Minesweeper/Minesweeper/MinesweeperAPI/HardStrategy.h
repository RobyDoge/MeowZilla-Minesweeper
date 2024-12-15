#pragma once
#include "IStrategy.h"
class HardStrategy :
    public IStrategy
{
public:
	int GetHeight() override;
	int GetWidth() override;
	int GetMinesNumber() override;
	int GetTimer() override;
	std::string GetTheme() override;

private:
	int m_width = 25;
	int m_height = 25;
	int m_minesNumber = 99;
	int m_timer = 100;
	std::string m_theme = STARRY_SKY;
};

