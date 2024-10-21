// Copyright dh


#include "Player/SimplePlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

ASimplePlayerController::ASimplePlayerController()
{
	bReplicates = true;
}

void ASimplePlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(SimpleContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(SimpleContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void ASimplePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	UEnhancedInputComponent* EnhanceInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhanceInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASimplePlayerController::Move);
}

void ASimplePlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputValue = InputActionValue.Get<FVector2D>();

	const FRotator Rotation = GetControlRotation();
	FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	FVector FowardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	//GEngine->AddOnScreenDebugMessage(-1, 60.f, FColor::Black, YawRotation.Vector().ToString());
	GEngine->AddOnScreenDebugMessage(-1, 60.f, FColor::Black, InputValue.ToString());

	if (APawn* ControlledPawn = GetPawn<APawn>()) {
		ControlledPawn->AddMovementInput(FowardDirection, InputValue.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputValue.X);
	}
}
