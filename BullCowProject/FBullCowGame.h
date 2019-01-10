#pragma once
#include <string>
using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus {
	OK,
	NotIsogram,
	WrongLength,
	Invalid
};

class FBullCowGame {

public:
	FBullCowGame();
	int32 GetMaxTries() const;

	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	int32 GetHiddenWordLength() const;

	EGuessStatus CheckGuessValidity(FString) const; 
	void Reset(); 
	FBullCowCount SubmitGuess(FString);

private:
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bIsGameWon = false;

	bool IsIsogram(FString) const;
};
