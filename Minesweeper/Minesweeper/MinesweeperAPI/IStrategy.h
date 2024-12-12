#pragma once
#include<memory>
#include <string>
#include <optional>
class IStrategy
{
public:
	virtual int GetWidth() = 0;
	virtual int GetHeight() = 0;
	virtual int GetMinesNumber() = 0;
	virtual int GetTimer() = 0;
	virtual std::string GetTheme() = 0;
};

using IStrategyPtr = std::shared_ptr<class IStrategy>;
