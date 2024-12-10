#pragma once
//! Enum class for the states of the game
enum class EGameState {
	//! Game is over
	GAMEOVER,
	//! Game is won
	WIN,
	//! Game is in progress
	INGAME,
	//! Game has not started
	FIRSTCLICK
};