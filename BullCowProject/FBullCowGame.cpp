#include "FBullCowGame.h"
using FString = std::string;
using int32 = int;

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "house";
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//receives a valid guess, increments and returns count
	//increment turn num
	MyCurrentTry++;
	//setup a return variable
	FBullCowCount BullCowCount;
	//loop through all chars in guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLength; i++) {
		//compare all letters against hidden word
		for (int32 j = 0; j < HiddenWordLength; j++) {
			if (tolower(Guess[i]) == tolower(MyHiddenWord[j]) && i == j) {
				BullCowCount.Bulls++;//if the letters match in the same position, add to bulls
			}
			else if (tolower(Guess[i]) == tolower(MyHiddenWord[j])) {
				BullCowCount.Cows++;//if they match, but not in the same position, add to cows
			}
		}
	}
	
	//return BullCowCount
	return BullCowCount;
}

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

bool FBullCowGame::IsGameWon() const
{
	return false;
}

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false) {
		return EGuessStatus::NotIsogram;
	}
	else if (Guess.length() != GetHiddenWordLength()) {
		return EGuessStatus::WrongLength;
	}
	else
		return EGuessStatus::OK;
	
}