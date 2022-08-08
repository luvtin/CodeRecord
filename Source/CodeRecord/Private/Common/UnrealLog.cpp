// Fill out your copyright notice in the Description page of Project Settings.


#include "Common/UnrealLog.h"


// Sets default values
AUnrealLog::AUnrealLog()
{
}

// Called when the game starts or when spawned
void AUnrealLog::BeginPlay()
{
	Super::BeginPlay();

	// 在当前屏幕视口中打印;首参数-1，表示无需更新或刷新此消息，第二个参数表示持续时间
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("AddOnScreenDebugMessage: Hello World!"));

	/*
	第一个参数 ---- Log的类别。 LogTemp 是 Log 的类别 中的一种
	第二个参数 ---- Log的颜色 
	Warning ， 表示输出信息用Yellow黄色来显示
	Log，表示输出信息用 Grey 灰色来显示
	Error，表示输出信息用 Red 红色来显示
	第三个参数 ---- TEXT("信息")
	
	输出可变量 UE_LOG(LogTemp, Log, TEXT("%s, %f, %i"), *StringName, float, int); 
	%s 是输出 字符串，注意加*
	%f 是输出 浮点数数字，比如 time 就是 float 类型的
	%i 是 int 类型
	*/
	UE_LOG(LogTemp, Log, TEXT("UE_LOG: Hello World!"));

	// TimeHandle模拟delay,须在endplay中clear，否则切换关卡时会崩溃
	GetWorld()->GetTimerManager().SetTimer(MyTimerHandle, [&]()
	{
		UE_LOG(LogTemp, Warning, TEXT("此文本将在执行后 8 秒出现在控制台中"))
		GetWorld()->GetTimerManager().ClearTimer(MyTimerHandle);
	}, 8, false);
}

void AUnrealLog::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	GetWorld()->GetTimerManager().ClearTimer(MyTimerHandle);
}
