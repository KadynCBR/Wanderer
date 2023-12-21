// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WandererCharacterBase.generated.h"

UCLASS()
class WANDERER_API AWandererCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWandererCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Movement Speed
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MovementSpeed;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
