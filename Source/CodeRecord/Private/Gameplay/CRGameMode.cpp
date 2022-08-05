// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/CRGameMode.h"
#include "Gameplay/CRFPCaracter.h"
#include "Gameplay/CRPlayerController.h"
#include "Gameplay/CRWorldSubsystem.h"

ACRGameMode::ACRGameMode()
{
	DefaultPawnClass = ACRFPCaracter::StaticClass();
	PlayerControllerClass = ACRPlayerController::StaticClass();
	
}

void ACRGameMode::BeginPlay()
{
	Super::BeginPlay();


	if(GetWorld()->GetSubsystem<UCRWorldSubsystem>())
	{
		UE_LOG(LogTemp, Warning, TEXT("存在Subsystem"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("不存在Subsystem"));
	}
	
}
