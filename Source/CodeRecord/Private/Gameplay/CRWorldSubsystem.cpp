// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/CRWorldSubsystem.h"

#include "GameMapsSettings.h"
#include "Gameplay/CRGameMode.h"
#include "Kismet/GameplayStatics.h"

bool UCRWorldSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	Super::ShouldCreateSubsystem(Outer);

	// TODO 仅当GameMode为ACRGameMode时创建Subsystem
	return Cast<ACRGameMode>(UGameplayStatics::GetGameMode(Outer)) ? true : true;
}


void UCRWorldSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Warning, TEXT("初始化了"));

	// TODO 仅当GameMode为ACRGameMode时创建Subsystem
	if (UGameplayStatics::GetGameMode(GetWorld()))
	{
		UE_LOG(LogTemp, Error, TEXT("%s"), *UGameplayStatics::GetGameMode(GetWorld())->GetClass()->GetFName().ToString());
	}
}

void UCRWorldSubsystem::Deinitialize()
{
	Super::Deinitialize();
	UE_LOG(LogTemp, Warning, TEXT("卸载了"));
}
