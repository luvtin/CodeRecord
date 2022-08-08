// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
// 创建None代码时include中包含 **.generated.h
#include "CREnum.generated.h"

UENUM(BlueprintType)
enum ELevelName
{
	MainMap UMETA(DisplayName = "MainMap"),
	OtherMap UMETA(DisplayName = "OtherMap")
};
