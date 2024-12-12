#include "HardStrategy.h"

int HardStrategy::GetHeight()
{
	return m_width;
}

int HardStrategy::GetWidth()
{
	return m_height;
}

int HardStrategy::GetMinesNumber()
{
	return m_minesNumber;
}

int HardStrategy::GetTimer()
{
	return m_timer;
}

std::string HardStrategy::GetTheme()
{
	return m_theme;
}
