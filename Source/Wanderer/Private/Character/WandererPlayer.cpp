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
