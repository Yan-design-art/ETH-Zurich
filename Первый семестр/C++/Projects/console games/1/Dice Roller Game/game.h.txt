#pragma once


enum class RoundResult {
	PlayerWins,
	AIWins,
	Draw
};


inline RoundResult determine_round_winner(int player_sum, int ai_sum) {
	if (player_sum > ai_sum) {
		return RoundResult::PlayerWins;
	}

	else if (player_sum < ai_sum) {
		return RoundResult::AIWins;
	}

	else {
		return RoundResult::Draw;	
	}
}