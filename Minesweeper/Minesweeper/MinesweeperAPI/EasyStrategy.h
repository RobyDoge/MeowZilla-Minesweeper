#pragma once
#include "IStrategy.h"
#include "string"
class EasyStrategy :public IStrategy
{
public:
	int SetHeight() override;
	int SetWidth() override;
	int SetMinesNumber() override;
	int SetTimer() override;
	std::string SetTheme() override;


private:
	int m_width = 10;
	int m_height = 10;
	int m_minesNumber = 10;
	int m_timer = -1;
	std::string m_theme = "Aurora Borealis";

};

