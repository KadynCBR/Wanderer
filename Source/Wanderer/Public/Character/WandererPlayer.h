
#pragma once

#include "CoreMinimal.h"
#include "Character/WandererCharacterBase.h"
#include "WandererPlayer.generated.h"

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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCameraComponent* PlayerCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USpringArmComponent* SpringArm;

	virtual void SetupPlayerInputComponent(class UInputComponent* SetupPlayerInputComponent) override;

private:
	void MoveForward(float Value);
	void MoveSide(float Value);

};
