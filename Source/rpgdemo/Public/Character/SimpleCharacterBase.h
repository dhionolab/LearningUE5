// Copyright dh

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SimpleCharacterBase.generated.h"

UCLASS(Abstract)
class RPGDEMO_API ASimpleCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ASimpleCharacterBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;
};
