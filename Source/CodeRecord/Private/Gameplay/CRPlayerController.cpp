// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/CRPlayerController.h"

ACRPlayerController::ACRPlayerController()
{
	bEnableClickEvents = true;
	SetShowMouseCursor(true);
}

void ACRPlayerController::BeginPlay()
{
	Super::BeginPlay();

	SetInputMode(FInputModeGameAndUI().SetHideCursorDuringCapture(false));
}
