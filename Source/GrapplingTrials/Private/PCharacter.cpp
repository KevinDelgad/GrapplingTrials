// Fill out your copyright notice in the Description page of Project Settings.


#include "PCharacter.h"

#include "PAction.h"
#include "PActionComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
APCharacter::APCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Camera
	HeadConnectionName = FName("head");
	CameraComp = CreateDefaultSubobject<UCameraComponent>(FName("CameraComponent"));
	CameraComp->SetupAttachment(GetMesh());
	
	CameraComp->bUsePawnControlRotation = true;
	bUseControllerRotationYaw = false;

	//Movement Comp
	GetCharacterMovement()->bOrientRotationToMovement = true;

	ActionComponent = CreateDefaultSubobject<UPActionComponent>("ActionComponent");
}

// Called when the game starts or when spawned
void APCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	//Connect Camera to Character Mesh Head
	FAttachmentTransformRules ATR = FAttachmentTransformRules(EAttachmentRule::KeepRelative, true);
	CameraComp->AttachToComponent(GetMesh(), ATR, HeadConnectionName);
}

void APCharacter::MoveForward(float Value)
{
	//Get Direction Controller (Camera) is looking and move in that direction
	
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;

	AddMovementInput(ControlRot.Vector(), Value);
}

void APCharacter::MoveRight(float Value)
{
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;

	//X = Forward (Red)
	//Y = Right (Green)
	//Z = Up (Blue)

	
	//Get Axis of Controller Matrix
	FVector RightVector = FRotationMatrix(ControlRot).GetScaledAxis(EAxis::Y);

	AddMovementInput(RightVector, Value);
}

void APCharacter::PrimaryFire()
{
	ActionComponent->StartActionByName(this ,"TestAction");
}

void APCharacter::PrimaryAbility()
{
	
}

void APCharacter::SecondaryAbility()
{
	
}

void APCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Red,
		FString::Printf(TEXT("Controller Rotation Vector: %s"), *GetControlRotation().ToString()));
	GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Red,
		
		FString::Printf(TEXT("Controller Rotation Forward Vector: %s"), *GetControlRotation().Vector().ToString()));
}

// Called to bind functionality to input
void APCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Movement Input
	PlayerInputComponent->BindAxis("MoveForward", this,&APCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APCharacter::MoveRight);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APCharacter::Jump);
	PlayerInputComponent->BindAction("PrimaryFire", IE_Pressed, this, &APCharacter::PrimaryFire);

	//Camera Input
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
}

