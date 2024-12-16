#pragma once
#include "IStrategy.h"

//! Class that implements the IStrategy interface and defines the hard strategy.
class HardStrategy : public IStrategy
{
public:
	/*! Getter method that returns the board's width = 25. */
	int GetHeight() override;

	/*! Getter method that returns the board's height = 25.*/
	int GetWidth() override;

	/*! Getter method that returns the mine number = 99. */
	int GetMinesNumber() override;

	/*! Getter method that returns the timer = 100. */
	int GetTimer() override;

	/*! Getter method that returns the theme for this strategy = Starry Sky. */
	std::string GetTheme() override;

private:
	int m_width = 25;
	int m_height = 25;
	int m_minesNumber = 99;
	int m_timer = 100;
	std::string m_theme = STARRY_SKY;
};

