// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/CRMainWidget.h"

#include "Components/Button.h"
#include "Components/CanvasPanelSlot.h"

UCRMainWidget::UCRMainWidget(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer)
{
}

void UCRMainWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	check(Btn_Main);
	if (UCanvasPanelSlot* MainBtnSlot = Cast<UCanvasPanelSlot>(Btn_Main->Slot))
	{
		MainBtnSlot->SetAnchors(FAnchors(0.5f, 0.5f, 0.5f, 0.5f));
		MainBtnSlot->SetPosition(FVector2D(0.0f, 0.0f));
		MainBtnSlot->SetSize(FVector2D(100.0f, 100.0f));
		MainBtnSlot->SetAlignment(FVector2D(0.5f, 0.5f));
	}
	Btn_Main->SetBackgroundColor(FLinearColor(1.0f, 0.5f, 0.5f, 0.5f));
	Btn_Main->OnClicked.AddDynamic(this, &UCRMainWidget::OnMainBtnClick);
}

void UCRMainWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UCRMainWidget::OnMainBtnClick()
{
	UE_LOG(LogTemp, Log, TEXT("点击了MainButton"));
}
