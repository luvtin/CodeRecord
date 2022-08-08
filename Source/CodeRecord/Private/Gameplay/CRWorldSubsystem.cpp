// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/CRWorldSubsystem.h"
#include "Core/CREnum.h"

bool UCRWorldSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	Super::ShouldCreateSubsystem(Outer);

	const UWorld* CurrentWorld = Cast<UWorld>(Outer);
	check(CurrentWorld);
	const FString MapName = StaticEnum<ELevelName>()->GetValueAsString(MainMap);
	const bool bSupportWorldType = CurrentWorld->WorldType == EWorldType::Game || EWorldType::PIE;
	const bool bMainMapLevel = CurrentWorld->GetName() == MapName;
	
	// TODO 仅当Game运行时且为MainMap关卡时创建
	return bMainMapLevel && bSupportWorldType ? true : false;
}


void UCRWorldSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	UE_LOG(LogTemp, Warning, TEXT("初始化了"));
}

void UCRWorldSubsystem::Deinitialize()
{
	Super::Deinitialize();
	UE_LOG(LogTemp, Warning, TEXT("卸载了"));
}
