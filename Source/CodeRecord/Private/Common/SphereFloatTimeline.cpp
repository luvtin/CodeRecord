// Fill out your copyright notice in the Description page of Project Settings.

#include "Common/SphereFloatTimeline.h"
#include "Components/TimelineComponent.h"

// Sets default values
ASphereFloatTimeline::ASphereFloatTimeline()
{
	SM_Sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(SM_Sphere);

	MainTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("Timeline"));
}

// Called when the game starts or when spawned
void ASphereFloatTimeline::BeginPlay()
{
	Super::BeginPlay();

	ActorInitLoc = ActorTargetLoc = GetActorLocation();
	ActorTargetLoc.Z += 200.0f;
	
	FOnTimelineFloat MovementValue;
	FOnTimelineEvent TimelineFinishedEvent;
	// MovementValue.BindUFunction(this,FName("TimelineProgress"));
	MovementValue.BindDynamic(this,&ASphereFloatTimeline::TimelineProgress);
	// TimelineFinishedEvent.BindUFunction(this,FName("TimelineFinished"));
	TimelineFinishedEvent.BindDynamic(this,&ASphereFloatTimeline::TimelineFinished);
	if(MovementCurve)
	{
		MainTimeline->AddInterpFloat(MovementCurve,MovementValue);
	}
	MainTimeline->SetTimelineFinishedFunc(TimelineFinishedEvent);
	MainTimeline->PlayFromStart();
}

void ASphereFloatTimeline::TimelineProgress(float Value)
{
	FVector NewLoc = FMath::Lerp(ActorInitLoc,ActorTargetLoc,Value);
	SetActorLocation(NewLoc);
}

void ASphereFloatTimeline::TimelineFinished()
{
	if (MainTimeline->GetPlaybackPosition() == 0.0f)
	{
		MainTimeline->PlayFromStart();
	}
	else
	{
		MainTimeline->Reverse();
	}
}


