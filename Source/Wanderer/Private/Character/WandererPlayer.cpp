// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/WandererPlayer.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

AWandererPlayer::AWandererPlayer() {
  PlayerCamera = CreateDefaultSubobject<UCameraComponent>("PlayerCamera");
  SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");

  SpringArm->SetupAttachment(GetRootComponent());
  PlayerCamera->SetupAttachment(SpringArm);

}



void AWandererPlayer::BeginPlay()
{
	Super::BeginPlay();
	// Registering the input mapping context with the input subsystem
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController())) {
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer())) {
			Subsystem->AddMappingContext(InputMappingContext, 0);
		}
	}
}

void AWandererPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Cast to use enhanced input features
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
	if (EnhancedInputComponent) {
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AWandererPlayer::OnMove);
	}
}

// Handle movement input 
void AWandererPlayer::OnMove(const FInputActionValue& Value) {
	// use 2D vector (from Kadyn and vid)
	const FVector2D MovementInput = Value.Get<FVector2D>();

	// Add movement input for forward and right
	AddMovementInput(GetActorForwardVector(), MovementInput.Y);
	AddMovementInput(GetActorRightVector(), MovementInput.X);
}

