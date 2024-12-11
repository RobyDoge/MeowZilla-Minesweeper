#pragma once
#include<memory>
#include <string>
#include <optional>
class IStrategy
{
public:
	virtual int SetWidth() = 0;
	virtual int SetHeight() = 0;
	virtual int SetMinesNumber() = 0;
	virtual int SetTimer() = 0;
	virtual std::string SetTheme() = 0;
};

using IStrategyPtr = std::shared_ptr<class IStrategy>;
