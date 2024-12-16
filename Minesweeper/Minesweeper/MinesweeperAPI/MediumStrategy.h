#pragma once
#include "IStrategy.h"

/*! Class that implements the IStrategy interface and defines the medium strategy.*/
class MediumStrategy : public IStrategy
{
public:
	/*! Getter method that returns the board's width = 16. */
	int GetHeight() override;

	/*! Getter method that returns the board's height = 16. */
	int GetWidth() override;

	/*! Getter method that returns the mine number = 40. */
	int GetMinesNumber() override;

	/*! Getter method that returns the timer = 100. */
	int GetTimer() override;

	/*! Getter method that returns the theme for this strategy = Dark Blue. */
	std::string GetTheme() override;

private:
	int m_width = 16;
	int m_height = 16;
	int m_minesNumber = 40;
	int m_timer = 100;
	std::string m_theme = DARK_BLUE;
};

