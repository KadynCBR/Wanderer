
#pragma once

#include "CoreMinimal.h"
#include "Character/WandererCharacterBase.h"
#include "WandererPlayer.generated.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"
#include "InputAction.h"

class UCameraComponent;
class USpringArmComponent;

/**
 * 
 */
UCLASS()
class WANDERER_API AWandererPlayer : public AWandererCharacterBase
{
	GENERATED_BODY()

public:
	AWandererPlayer();

protected:
	//virtual void SetupPlayerInputComponent(class UInputComponent* SetupPlayerInputComponent) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Value);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCameraComponent* PlayerCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInputMappingContext* InputMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInputAction* MoveForwardAction;

private:
	//void MoveForward(float Value);
	//void MoveSide(float Value);

};
