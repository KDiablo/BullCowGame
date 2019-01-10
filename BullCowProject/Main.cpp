/*
	this is the console executable that makes use of the BullCow Class. This acts as the view in the MVC pattern and is responsible for all user interaction
*/
#pragma once
#include <iostream>
#include <string>
#include "FBullCowGame.h"
using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain(bool);
FBullCowGame BCGame;

// Entry point to the application
int main() {

	PrintIntro();

	do {
		PlayGame();
	} while (AskToPlayAgain(true));
	
	return 0;
}


void PlayGame()
{
	BCGame.Reset();
	
	//set number of guesses and loop for the number of turns asking for guesses

	while(BCGame.GetCurrentTry() <= BCGame.GetMaxTries() && !BCGame.IsGameWon())
	{
		FText Guess = GetValidGuess();
		
		// submit valid guess to the game 
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		
		std::cout << "Bulls: " << BullCowCount.Bulls << " Cows: " << BullCowCount.Cows << std::endl << std::endl;
	}
	if (BCGame.IsGameWon())
		std::cout << "Congratulations! You've guessed the right word!\n";
	else if (BCGame.GetCurrentTry() >= BCGame.GetMaxTries()) {
		std::cout << "Sorry! You have run out of guesses!\n";
	}	
	return;
}

// This prints the intro to the game
void PrintIntro() {
	
	int32 WordLength = BCGame.GetHiddenWordLength();

	//instroduce the game
	std::cout << "Welcome to Bulls and Cows, a fun word game!\n";
	std::cout << "Can you guess the " << WordLength << "-letter isogram I'm thinking of?\n" << std::endl;

	return;
}

FText GetValidGuess() {
	EGuessStatus Status = EGuessStatus::Invalid;
	FText Guess;
	do {
		//get a guess from the user
		
		std::cout << "Try " << BCGame.GetCurrentTry() <<  " of " << BCGame.GetMaxTries() << ": enter your guess: ";
		getline(std::cin, Guess);
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::NotIsogram:
			std::cout << "Please enter an isogram! (A word that only has one of each letter in it)\n\n";
			break;
		case EGuessStatus::WrongLength:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << "-letter word!\n\n";
			break;
		default:
			break;
		}
	} while (Status != EGuessStatus::OK);
	return Guess;
	
}

bool AskToPlayAgain(bool DoesWantToPlay) {
	//ask user if they want to play again
	FText Answer;
	std::cout << "Do you want to play again? [y/n]\n";
	getline(std::cin, Answer);

	char firstChar = tolower(Answer[0]);

	if (firstChar == 'y') {
		std::cout << std::endl;
		DoesWantToPlay = true;
	}
	else if (firstChar == 'n')
		DoesWantToPlay = false;
	else {
		std::cout << "Answer not recognized, do you want to play again? Please enter y or n!";
		 DoesWantToPlay = AskToPlayAgain(DoesWantToPlay);
	}

	return DoesWantToPlay;

}
