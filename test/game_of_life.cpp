#include "gtest/gtest.h"
#include "game_of_life.h"

TEST(gameOfLife, liveCellShouldDieWhenThereAreNoNeighbors)
{
    EXPECT_EQ(game_of_life::calculate_next_cell_state(1, 0), 0);
}

TEST(gameOfLife, liveCellShouldLiveWhenThereIsOneNeighbor)
{
    EXPECT_EQ(game_of_life::calculate_next_cell_state(1, 1), 0);
}

TEST(gameOfLife, liveCellShouldLiveWhenThereIsTwoNeighbors)
{
    EXPECT_EQ(game_of_life::calculate_next_cell_state(1, 2), 1);
}

TEST(gameOfLife, liveCellShouldLiveWhenThereAreThreeNeighbors)
{
    EXPECT_EQ(game_of_life::calculate_next_cell_state(1, 3), 1);
}

TEST(gameOfLife, liveCellShouldLiveWhenThereAreFourNeighbors)
{
    EXPECT_EQ(game_of_life::calculate_next_cell_state(1, 4), 0);
}

TEST(gameOfLife, deadCellShouldLiveWhenThereAreThreeNeighbors)
{
    EXPECT_EQ(game_of_life::calculate_next_cell_state(0, 3), 1);
}