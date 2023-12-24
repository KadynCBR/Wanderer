
#pragma once

#include "CoreMinimal.h"
#include "Character/WandererCharacterBase.h"
#include "InputActionValue.h"
#include "WandererPlayer.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UInputAction;
class UInputMappingContext;

/**
 * AWandererPlayer inherits from AWandererCharacterBase
 * Used to create player characters using enhanced input
 */
UCLASS()
class WANDERER_API AWandererPlayer : public AWandererCharacterBase
{
	GENERATED_BODY()

public:
	AWandererPlayer();

protected:
	// BeginPlay called when the game starts or player is spawned
	virtual void BeginPlay() override;
	// SetupPlayer... used to bind input actions
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) 
	UCameraComponent* PlayerCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USpringArmComponent* SpringArm;

	// Input Mapping context for enhanced input mappings
	UPROPERTY(EditAnywhere, Category=Input)
	UInputMappingContext* InputMappingContext;

	// Input action for movement. Handles all movement(l,r,f,b)
	UPROPERTY(EditAnywhere, Category=Input)
	UInputAction* MoveAction;

	void OnMove(const FInputActionValue& Value);

private:

};
