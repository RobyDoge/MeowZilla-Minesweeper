#pragma once
#include "IStrategy.h"

//! Class that implements the IStrategy interface and defines the custom strategy.
class CustomStrategy : public IStrategy
{
public:
	/*! Constructor for the CustomStrategy that initializes private members. */
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

