// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/CRFPCaracter.h"

// Sets default values
ACRFPCaracter::ACRFPCaracter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACRFPCaracter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACRFPCaracter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ACRFPCaracter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ACRFPCaracter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACRFPCaracter::MoveRight);
	PlayerInputComponent->BindAxis("TurnRight", this, &ACRFPCaracter::TurnRight);
	PlayerInputComponent->BindAxis("LookUp", this, &ACRFPCaracter::LookUp);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACRFPCaracter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACRFPCaracter::StopJumping);

	// 使用BindKey时需要在 **.Build.cs文件中导入“Slate”模块
	PlayerInputComponent->BindKey(EKeys::RightMouseButton, IE_Pressed, this, &ACRFPCaracter::RightMousePressed);
	PlayerInputComponent->BindKey(EKeys::RightMouseButton, IE_Released, this, &ACRFPCaracter::RightMouseReleased);
}

void ACRFPCaracter::RightMousePressed()
{
	bRightMousePressed = true;
}

void ACRFPCaracter::RightMouseReleased()
{
	bRightMousePressed = false;
}

void ACRFPCaracter::MoveForward(float Val)
{
	if (Val != 0)
	{
		AddMovementInput(GetActorForwardVector(), Val, false);
	}
}

void ACRFPCaracter::MoveRight(float Val)
{
	if (Val != 0)
	{
		AddMovementInput(GetActorRightVector(), Val, false);
	}
}

void ACRFPCaracter::TurnRight(float Val)
{
	if (Val != 0 && bRightMousePressed)
	{
		AddControllerYawInput(Val);
	}
}

void ACRFPCaracter::LookUp(float Val)
{
	if (Val != 0 && bRightMousePressed)
	{
		AddControllerPitchInput(Val);
	}
}
