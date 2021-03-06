#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct BullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus {
	OK,
	Not_isogram,
	Wrong_length,
	Not_lower_case
};

class FBullCowGame {

public:
	int32 getMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool isGameWon() const;

	FBullCowGame();
	void Reset();
	EGuessStatus checkGuessValidity(FString);

	BullCowCount SubmitGuess(FString);

private:
	int32 MyCurrentTry;
	FString myHiddenWord;
	int32 numberOfBulls; //Player best guess.

	bool isIsogram(FString) const;
	bool isLowercase(FString) const;
};