#pragma once
#include<memory>
#include <string>
#include <optional>

/*! Interface class for implementing the Strategy design pattern. */
class IStrategy
{
public:
	/*! Getter method that returns the board's width */
	virtual int GetWidth() = 0;

	/*! Getter method that returns the board's height */
	virtual int GetHeight() = 0;

	/*! Getter method that returns the mine number */
	virtual int GetMinesNumber() = 0;

	/*! Getter method that returns the timer */
	virtual int GetTimer() = 0;

	/*! Getter method that returns the theme */
	virtual std::string GetTheme() = 0;
};

using IStrategyPtr = std::shared_ptr<class IStrategy>;
