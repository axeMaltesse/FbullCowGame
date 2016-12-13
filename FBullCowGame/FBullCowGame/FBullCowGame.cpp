#include "FBullCowGame.h"
#include <iostream>

FBullCowGame::FBullCowGame() {
	Reset();
}

int32 FBullCowGame::getMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const
{
	return myHiddenWord.length();
}

bool FBullCowGame::isGameWon() const
{
	return false;
}

void FBullCowGame::Reset() {
	MyCurrentTry = 1;
	MyMaxTries = 8;
	const FString MY_HIDDENT_WORD = "planet";
	myHiddenWord = MY_HIDDENT_WORD;
}

EGuessStatus FBullCowGame::checkGuessValidity(FString Guess)
{
	if (false) {
		return EGuessStatus::Not_isogram;
	}if (false) {
		return EGuessStatus::Not_lower_case;
	}if (Guess.length() != GetHiddenWordLength()) {
		return EGuessStatus::Wrong_length;
	}
	else {
		return EGuessStatus::OK;
	}
}

BullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTry++;
	BullCowCount BullCowCount;

	for (int32 i = 0; i < myHiddenWord.length(); i++) {
		for (int32 j = 0; j < Guess.length(); j++) {
			if (myHiddenWord[i] == Guess[j]) {
				if (i == j) {
					BullCowCount.Bulls += 1;
				}
				else {
					BullCowCount.Cows += 1;
				}
			}
		}
	}

	return BullCowCount;
}

