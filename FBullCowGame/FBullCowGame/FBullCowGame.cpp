#include "FBullCowGame.h"
#include <iostream>
#include <map>
#define TMap std::map

FBullCowGame::FBullCowGame() {
	Reset();
}

int32 FBullCowGame::getMaxTries() const {return MyMaxTries;}
int32 FBullCowGame::GetCurrentTry() const {return MyCurrentTry;}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return myHiddenWord.length();
}

bool FBullCowGame::isGameWon() const
{
	BullCowCount Bulls;
	if (numberOfBulls == GetHiddenWordLength()) {
		std::cout << "Congratulations, You have won!" << std::endl;
		return true;
	}
	else {
		return false;
	}
}

void FBullCowGame::Reset(){
	MyCurrentTry = 1;
	MyMaxTries = 8;
	const FString MY_HIDDENT_WORD = "planet";
	myHiddenWord = MY_HIDDENT_WORD;
	const int32 HIGHSCORE = 0;
	numberOfBulls = HIGHSCORE;
}

EGuessStatus FBullCowGame::checkGuessValidity(FString Guess)
{
	if (!isIsogram(Guess)) {
		return EGuessStatus::Not_isogram;
	}if (!isLowercase(Guess)) {
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
					numberOfBulls = BullCowCount.Bulls;
				}
				else {
					BullCowCount.Cows += 1;
				}
			}
		}
	}
	return BullCowCount;
}

bool FBullCowGame::isIsogram(FString Guess) const
{
	TMap<char, bool>LetterSeen;
	if (Guess.length() < 2) {
		return true;
	}
	else if (Guess.length() >= 2) {
		for each (auto i in Guess){
			i = tolower(i);
			if (LetterSeen[i]) {
				return false;
			}
			else{
				LetterSeen[i] = true;
			}
		}
	}
	return true;
}

bool FBullCowGame::isLowercase(FString Guess) const
{
	for each (auto letter in Guess){
		if (islower(letter)) {
			return true;
		}
		else {
			return false;
		}
	}
	return true;
}

