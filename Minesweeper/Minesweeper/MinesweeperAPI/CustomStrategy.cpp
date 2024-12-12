#include "CustomStrategy.h"

CustomStrategy::CustomStrategy(const int& width, const int& height, const int& minesNumber, const int& timer,
                               std::string theme):
	m_width(width), m_height(height), m_minesNumber(minesNumber), m_timer(timer), m_theme(std::move(theme))
{
}

int CustomStrategy::GetWidth()
{
	return m_width;
}

int CustomStrategy::GetHeight()
{
	return m_height;
}

int CustomStrategy::GetMinesNumber()
{
	return m_minesNumber;
}

int CustomStrategy::GetTimer()
{
	return m_timer;
}

std::string CustomStrategy::GetTheme()
{
	return m_theme;
}
