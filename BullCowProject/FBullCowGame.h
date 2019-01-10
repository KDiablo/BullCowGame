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
	void Reset(); //TODO: make a more rich return value
	// provide method for counting bulls and cows and increasing turn number
	FBullCowCount SubmitGuess(FString);
//please try to ignore this and focus on the public interface
private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bIsGameWon = false;
};
