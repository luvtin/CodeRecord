// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CRPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CODERECORD_API ACRPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ACRPlayerController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
