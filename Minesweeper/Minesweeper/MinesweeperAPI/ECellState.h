#pragma once
//! Enum class for the state of a cell in the game
enum class ECellState {
	FLAGGED,
	REVEALED,
	UNREVEALED,
	MINE,
	FLAGGED_MINE
};