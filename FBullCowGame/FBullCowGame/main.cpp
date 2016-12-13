#include <iostream>
#include <string>
#include "FBullCowGame.h"

FBullCowGame BCGame;
using FText = std::string;
using int32 = int;

void PrintIntro() {
	std::cout << "Welcome to my game!\n";
	std::cout << "it is my revision of cpp\n";
	std::cout << "The hidden word length is: " << BCGame.GetHiddenWordLength() << std::endl;
	return;
}

FText getGuess() {
	int32 MyCurrentTry = BCGame.GetCurrentTry();
	std::cout << "Your try is: " << MyCurrentTry << std::endl;
	std::cout << "Your Guess: \n";
	FText Guess;
	std::getline(std::cin, Guess);
	EGuessStatus Status = BCGame.checkGuessValidity(Guess);
	do {
		switch (Status) {
		case EGuessStatus::Wrong_length:
			std::cout << "Please enter a valid length" << std::endl;
			break;
		case EGuessStatus::Not_isogram:
			std::cout << "Not isogram!" << std::endl;
			break;
		case EGuessStatus::Not_lower_case:
			std::cout << "please enter lower case letters \n";
			break;
		default:
			break;
		}
		return Guess;
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);
}

void PlayGame() {
	BCGame.Reset();
	int32 MaxTries = BCGame.getMaxTries();

	while (!BCGame.isGameWon() && BCGame.GetCurrentTry() != 8){
		FText Guess = getGuess();
		BCGame.checkGuessValidity(Guess);
		std::cout << "Your guess was: " << Guess << std::endl;
		BullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		std::cout << "Bulls: " << BullCowCount.Bulls << ". Cows: " << BullCowCount.Cows << std::endl;
	}
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again? ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}

int main() {
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
}