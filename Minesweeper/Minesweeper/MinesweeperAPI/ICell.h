#pragma once
#include "ECellState.h"

#include <memory>

using CellPtr = std::shared_ptr <class ICell>;

class ICell
{
public:
	virtual ECellState GetState() = 0;
	virtual int GetAdjacentMines() = 0;
	virtual int GetRow() = 0;
	virtual int GetColumn() = 0;

	virtual void SetState(ECellState state) = 0;
	virtual void AddAdjacentMine() = 0;
	virtual bool IsMine() const = 0;
};