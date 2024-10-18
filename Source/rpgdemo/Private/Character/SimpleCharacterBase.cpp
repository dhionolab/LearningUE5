// Copyright dh


#include "Character/SimpleCharacterBase.h"

ASimpleCharacterBase::ASimpleCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ASimpleCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

