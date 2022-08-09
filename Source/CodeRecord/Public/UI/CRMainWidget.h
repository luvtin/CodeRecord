// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CRMainWidget.generated.h"

class UButton;

UCLASS()
class CODERECORD_API UCRMainWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UCRMainWidget(const FObjectInitializer& ObjectInitializer);
	
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct()override;

	// 使用 Meta = (BindWidget) 绑定蓝图中的按钮，蓝图中的按钮名称需与变量名一致
	UPROPERTY(Meta = (BindWidget))
	UButton *Btn_Main;
	
	UFUNCTION()
	void OnMainBtnClick();
	
};
