#pragma once
//! Enum class for the state of a cell in the game
enum class ECellState {
	//! The cell is flagged as a mine
	FLAGGED, 
	//! The cell is revealed
	REVEALED,
	//! The cell is not revealed
	UNREVEALED,
	//! The cell is a mine and is revealed
	MINE,
	//! The cell is a mine and is flagged
	FLAGGED_MINE
};