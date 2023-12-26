// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "WandererGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class WANDERER_API UWandererGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	void AddExperience(float ToAdd);
	float GetExperience();
	int GetLevel();

private:
	// Unsure if this should be here or in playerstate, it makes more sense to put it here, and reset
	// on death?
	/*
		Experience (Per run)
			reset after death
	*/
	UPROPERTY()
	float Experience;

	/*
		Level (Per run)
			reset after death
	*/
	UPROPERTY()
	int Level; 

	/*
		Gold (Per save)
			given after Level completion
			meta currency
	*/
	UPROPERTY()
	int Gold;

	/*
		If having the concept of unlocked levels, we can use bits to represent which levels we have unlocked
	*/
	UPROPERTY()
	int32 LevelsUnlocked;

	

};
