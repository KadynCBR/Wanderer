// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/WandererPlayer.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"

AWandererPlayer::AWandererPlayer() {
  PlayerCamera = CreateDefaultSubobject<UCameraComponent>("PlayerCamera");
  SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");

  SpringArm->SetupAttachment(GetRootComponent());
  PlayerCamera->SetupAttachment(SpringArm);

}


// Making changes here trying to use enhanced
//void AWandererPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
/*
void AWandererPlayer::SetupPlayerInputComponent(UEnhancedInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//PlayerInputComponent->BindAxis("MoveForward", this, &AWandererPlayer::MoveForward);
	//PlayerInputComponent->BindAxis("MoveSide", this, &AWandererPlayer::MoveSide);
	PlayerInputComponent->BindAction(MoveForwardAction, ETriggerEvent::Triggered, this, &AWandererPlayer::MoveForward);
}

void AWandererPlayer::MoveForward(float Value) {
	AddMovementInput(GetActorForwardVector(), Value);
}

*/
void AWandererPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (EnhancedInputComponent) {
		EnhancedInputComponent->BindAction(MoveForwardAction, ETriggerEvent::Triggered, this, &AWandererPlayer::MoveForward);
		EnhancedInputComponent->BindAction(MoveSideAction, ETriggerEvent::Triggered, this, &AWandererPlayer::MoveSide);
	}
}

void AWandererPlayer::MoveForward(float Value) {
	AddMovementInput(GetActorForwardVector(), Value);
}

void AWandererPlayer::MoveSide(float Value) {
	AddMovementInput(GetActorRightVector(), Value);
}
