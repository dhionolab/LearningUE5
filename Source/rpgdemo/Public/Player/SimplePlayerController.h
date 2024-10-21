// Copyright dh

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SimplePlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
/**
 * 
 */
UCLASS()
class RPGDEMO_API ASimplePlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ASimplePlayerController();
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> SimpleContext;
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const FInputActionValue& InputActionValue);
};
