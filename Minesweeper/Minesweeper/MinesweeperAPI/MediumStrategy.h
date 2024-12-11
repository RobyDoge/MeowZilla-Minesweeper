#pragma once
#include "IStrategy.h"

class MediumStrategy : public IStrategy
{
public:
	int SetHeight() override;
	int SetWidth() override;
	int SetMinesNumber() override;
	int SetTimer() override;
	std::string SetTheme() override;

private:
	int m_width = 16;
	int m_height = 16;
	int m_minesNumber = 40;
	int m_timer = 100;
	std::string m_theme = "Dark Blue";
};

