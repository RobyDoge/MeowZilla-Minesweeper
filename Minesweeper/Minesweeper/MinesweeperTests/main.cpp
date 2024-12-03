#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "MinesweeperGame.h"
using namespace testing;
TEST(MinesweeperTest, GetCellStates)
{
    MinesweeperGame game;
    game.GetCell(2, 4)->SetState(ECellState::MINE);
    game.GetCell(6, 3)->SetState(ECellState::MINE);
    game.GetCell(9, 1)->SetState(ECellState::MINE);
    MinesweeperCell* cell = game.GetCell(2, 3);

    game.RevealCells(cell);

    ASSERT_EQ(game.GetCell(2, 3)->GetState(), ECellState::REVEALED);
    ASSERT_EQ(game.GetCell(1, 2)->GetState(), ECellState::UNREVEALED);
    ASSERT_EQ(game.GetCell(6, 3)->GetState(), ECellState::MINE);
}

TEST(MinesweeperTest, FillCells)
{

    MinesweeperGame game;
    game.GetCell(2, 1)->SetState(ECellState::MINE);
    game.GetCell(0, 3)->SetState(ECellState::MINE);

    game.GetCell(2, 6)->SetState(ECellState::MINE);
    game.GetCell(7, 6)->SetState(ECellState::MINE);
    game.GetCell(5, 3)->SetState(ECellState::MINE);
    game.GetCell(5, 8)->SetState(ECellState::MINE);
    MinesweeperCell* cell = game.GetCell(0, 1);
    game.RevealCells(cell);

    cell = game.GetCell(5, 6);
    game.RevealCells(cell);

    ASSERT_EQ(game.GetCell(0, 0)->GetState(), ECellState::REVEALED);
    ASSERT_EQ(game.GetCell(6, 7)->GetState(), ECellState::REVEALED);
    ASSERT_EQ(game.GetCell(5, 4)->GetState(), ECellState::REVEALED);
}

TEST(MinesweeperTest, GetAdjacentMines)
{
    MinesweeperGame game;
    game.GetCell(2, 0)->SetState(ECellState::MINE);
    game.GetCell(2, 1)->SetState(ECellState::MINE);
    game.GetCell(2, 2)->SetState(ECellState::MINE);
    game.GetCell(0, 3)->SetState(ECellState::MINE);

    game.GetCell(6, 3)->SetState(ECellState::MINE);
    game.GetCell(7, 5)->SetState(ECellState::MINE);

    MinesweeperCell* cell = game.GetCell(0, 1);
    game.RevealCells(cell);
    cell = game.GetCell(7, 4);
    game.RevealCells(cell);

    ASSERT_EQ(game.GetCell(1, 2)->GetAdjacentMines(), 3);
    ASSERT_EQ(game.GetCell(7, 4)->GetAdjacentMines(), 2);
}

TEST(MinesweeperTest, FlagCells)
{
    MinesweeperGame game;
    game.GetCell(2, 4)->SetState(ECellState::MINE);
    game.GetCell(6, 3)->SetState(ECellState::MINE);
    game.GetCell(9, 1)->SetState(ECellState::MINE);
    MinesweeperCell* cell = game.GetCell(1, 5);
    game.FlagCell(cell);
    cell = game.GetCell(9, 1);
    game.FlagCell(cell);
    cell = game.GetCell(2, 4);
    game.FlagCell(cell);
    cell = game.GetCell(7, 3);
    game.FlagCell(cell);
    cell = game.GetCell(9, 1);
    game.FlagCell(cell);
    cell = game.GetCell(7, 3);
    game.FlagCell(cell);

    ASSERT_EQ(game.GetCell(2, 2)->GetState(), ECellState::UNREVEALED);
    ASSERT_EQ(game.GetCell(1, 5)->GetState(), ECellState::FLAGGED);
    ASSERT_EQ(game.GetCell(9, 1)->GetState(), ECellState::MINE);
    ASSERT_EQ(game.GetCell(2, 4)->GetState(), ECellState::FLAGGED_MINE);
    ASSERT_EQ(game.GetCell(7, 3)->GetState(), ECellState::UNREVEALED);
    ASSERT_EQ(game.GetCell(6, 3)->GetState(), ECellState::MINE);
    
}

TEST(MinesweeperTest, FirstClickSafe)
{
    MinesweeperGame game;
    MinesweeperCell* cell = game.GetCell(2, 7);
    game.CheckCell(cell);
    ASSERT_EQ(game.GetCell(2, 7)->GetState(), ECellState::REVEALED);
}
int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}