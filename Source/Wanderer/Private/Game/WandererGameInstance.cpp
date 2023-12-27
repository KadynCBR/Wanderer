// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/WandererGameInstance.h"

void UWandererGameInstance::AddExperience(float ToAdd) { Experience += ToAdd; }

float UWandererGameInstance::GetExperience() const { return Experience; }

int UWandererGameInstance::GetLevel() const { return (int)Experience % 100; }

void UWandererGameInstance::AddGold(int ToAdd) { Gold += ToAdd; }

int UWandererGameInstance::GetGold() const { return Gold; }

bool UWandererGameInstance::SpendGold(int ToSpend) { return false; }

void UWandererGameInstance::UnlockLevel(int LevelToUnlock) {
  LevelsUnlocked |= 1 << LevelToUnlock;
}

bool UWandererGameInstance::IsLevelUnlocked(int LevelToCheck) const { return (LevelsUnlocked & (1 << LevelToCheck)); }
