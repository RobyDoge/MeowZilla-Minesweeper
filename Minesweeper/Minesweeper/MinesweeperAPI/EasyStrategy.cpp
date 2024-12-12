#include "EasyStrategy.h"


int EasyStrategy::GetHeight()
{
	return m_width;
}

int EasyStrategy::GetWidth()
{
	return m_height;
}

int EasyStrategy::GetMinesNumber()
{
	return m_minesNumber;
}

int EasyStrategy::GetTimer()
{
	return m_timer;
}

std::string EasyStrategy::GetTheme()
{
	return m_theme;
}
