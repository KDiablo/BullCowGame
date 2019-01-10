#include "FBullCowGame.h"
#include <map>
#define TMap std::map
using FString = std::string;
using int32 = int;

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "house";
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bIsGameWon = false;
	return;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//receives a valid guess, increments and returns count
	MyCurrentTry++;
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
	if (BullCowCount.Bulls == GetHiddenWordLength()) {
		bIsGameWon = true;
	}
		
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Guess) const
{
	//treat 0 and 1 letter strings as isograms
	if (Guess.length() <= 1) 
		return true;

	TMap<char, bool> LetterSeen;

	for (auto Letter : Guess) {
		if (LetterSeen.count(Letter) >= 1)
			return false; 
		else 
			LetterSeen[Letter] = true;
	}
	return true;
}

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

bool FBullCowGame::IsGameWon() const { return bIsGameWon; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) {
		return EGuessStatus::NotIsogram;
	}
	else if (Guess.length() != GetHiddenWordLength()) {
		return EGuessStatus::WrongLength;
	}
	else
		return EGuessStatus::OK;
	
}
