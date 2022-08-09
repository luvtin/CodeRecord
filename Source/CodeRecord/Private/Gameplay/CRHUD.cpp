// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/CRHUD.h"

ACRHUD::ACRHUD()
{
	// 构造函数中使用 ConstructorHelpers::FClassFinder 定位到蓝图位置
	static ConstructorHelpers::FClassFinder<UCRMainWidget> WBPMainWidget(TEXT("/Game/UI/WBP_MainWidget"));
	MainWidgetClass = WBPMainWidget.Class;
}

void ACRHUD::BeginPlay()
{
	Super::BeginPlay();

	if (MainWidgetClass)
	{
		MainWidget = CreateWidget<UCRMainWidget>(GetWorld(), MainWidgetClass);
		if (MainWidget)
		{
			MainWidget->AddToViewport();
		}
	}
}
