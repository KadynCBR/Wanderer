// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/WandererCharacterBase.h"
#include "WandererEnemy.generated.h"

/**
 * 
 */
UCLASS()
class WANDERER_API AWandererEnemy : public AWandererCharacterBase
{
	GENERATED_BODY()

public:
	AWandererEnemy();
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float EnemyHP;

private:
};
