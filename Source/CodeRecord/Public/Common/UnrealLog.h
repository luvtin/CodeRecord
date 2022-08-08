﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UnrealLog.generated.h"

UCLASS()
class CODERECORD_API AUnrealLog : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AUnrealLog();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	FTimerHandle MyTimerHandle;
};
