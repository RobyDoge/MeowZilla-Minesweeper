#pragma once
#include "IStrategy.h"

class MediumStrategy : public IStrategy
{
public:
	int GetHeight() override;
	int GetWidth() override;
	int GetMinesNumber() override;
	int GetTimer() override;
	std::string GetTheme() override;

private:
	int m_width = 16;
	int m_height = 16;
	int m_minesNumber = 40;
	int m_timer = 100;
	std::string m_theme = "Dark Blue";
};

