// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CRGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CODERECORD_API ACRGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACRGameMode();

	virtual void BeginPlay() override;
};
