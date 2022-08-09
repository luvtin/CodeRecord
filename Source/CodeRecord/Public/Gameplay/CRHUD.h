// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UI/CRMainWidget.h"
#include "CRHUD.generated.h"

/**
 * 
 */
UCLASS()
class CODERECORD_API ACRHUD : public AHUD
{
	GENERATED_BODY()

public:
	ACRHUD();

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> MainWidgetClass;

private:
	UCRMainWidget* MainWidget;
};
