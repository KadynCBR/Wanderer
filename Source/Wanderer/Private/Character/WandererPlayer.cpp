// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/WandererPlayer.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

AWandererPlayer::AWandererPlayer() {
  PlayerCamera = CreateDefaultSubobject<UCameraComponent>("PlayerCamera");
  SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");

  SpringArm->SetupAttachment(GetRootComponent());
  PlayerCamera->SetupAttachment(SpringArm);

}

void AWandererPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AWandererPlayer::MoveForward);
	PlayerInputComponent->BindAxis("MoveSide", this, &AWandererPlayer::MoveSide);
}

void AWandererPlayer::MoveForward(float Value) {
	AddMovementInput(GetActorForwardVector(), Value);
}

void AWandererPlayer::MoveSide(float Value) {
	AddMovementInput(GetActorRightVector(), Value);
}
