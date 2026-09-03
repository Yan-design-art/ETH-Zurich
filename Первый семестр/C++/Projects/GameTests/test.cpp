#include "pch.h"
#include "gtest/gtest.h"
#include "../test scripts2/game.h" // Подключаем наш файл с логикой

// Тест 1: Проверяем, что игрок побеждает, если у него больше очков
TEST(DiceGameLogic, PlayerShouldWin) {
    // Arrange (Подготовка данных)
    int player_dice = 10;
    int ai_dice = 5;

    // Act (Выполнение действия)
    RoundResult result = determine_round_winner(player_dice, ai_dice);

    // Assert (Проверка утверждения)
    // Мы ожидаем (EXPECT_EQ), что результат будет равен RoundResult::PlayerWins
    EXPECT_EQ(result, RoundResult::PlayerWins);
}

TEST(DiceGmaLogic, AIShouldWin) {
    int player_dice = 5;
    int ai_dice = 10;
    RoundResult result = determine_round_winner(player_dice, ai_dice);

    EXPECT_EQ(result, RoundResult::AIWins);
}

// Тест 2: Проверяем ничью
TEST(DiceGameLogic, ShouldBeADraw) {
    RoundResult result = determine_round_winner(7, 7);
    EXPECT_EQ(result, RoundResult::Draw);
}