#pragma once
#include "IStrategy.h"
class CustomStrategy :
    public IStrategy
{
public:
	CustomStrategy(const int& width, const int& height, const int& minesNumber, const int& timer, std::string theme);
	int GetWidth() override;
	int GetHeight() override;
	int GetMinesNumber() override;
	int GetTimer() override;
	std::string GetTheme() override;
private:
	int m_width;
	int m_height;
	int m_minesNumber;
	int m_timer;
	std::string m_theme;
};

