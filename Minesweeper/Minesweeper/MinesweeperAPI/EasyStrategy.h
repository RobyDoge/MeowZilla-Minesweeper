#pragma once
#include "IStrategy.h"

//! Class that implements the IStrategy interface and defines the easy strategy.
class EasyStrategy :public IStrategy
{
public:
	/*! Getter method that returns the board's width = 10. */
	int GetHeight() override;

	/*! Getter method that returns the board's height = 10. */
	int GetWidth() override;

	/*! Getter method that returns the mine number = 10. */
	int GetMinesNumber() override;

	/*! Getter method that returns the timer = -1. The easy strategy doesn't use the timer. */
	int GetTimer() override;

	/*! Getter method that returns the theme for this strategy = Aurora Borealis. */
	std::string GetTheme() override;

private:
	int m_width = 10;
	int m_height = 10;
	int m_minesNumber = 10;
	int m_timer = -1;
	std::string m_theme = "Aurora Borealis";
};

