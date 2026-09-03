#include "pch.h"
#include "gtest/gtest.h"
#include "../test scripts2/game.h" 

TEST(DiceGameLogic, PlayerShouldWin) {
    int player_dice = 10;
    int ai_dice = 5;

    RoundResult result = determine_round_winner(player_dice, ai_dice);

    EXPECT_EQ(result, RoundResult::PlayerWins);
}

TEST(DiceGmaLogic, AIShouldWin) {
    int player_dice = 5;
    int ai_dice = 10;
    RoundResult result = determine_round_winner(player_dice, ai_dice);

    EXPECT_EQ(result, RoundResult::AIWins);
}

TEST(DiceGameLogic, ShouldBeADraw) {
    RoundResult result = determine_round_winner(7, 7);
    EXPECT_EQ(result, RoundResult::Draw);
}