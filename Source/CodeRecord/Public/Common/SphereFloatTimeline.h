// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SphereFloatTimeline.generated.h"

class UTimelineComponent;

UCLASS()
class CODERECORD_API ASphereFloatTimeline : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASphereFloatTimeline();

	UPROPERTY(VisibleAnywhere,Category="Timeline Actor | Mesh")
	UStaticMeshComponent* SM_Sphere;

	UPROPERTY(EditAnywhere,Category="Timeline Actor | Curves")
	UCurveFloat* MovementCurve;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	UTimelineComponent* MainTimeline;

	UFUNCTION()
	void TimelineProgress(float Value);
	
	UFUNCTION()
	void TimelineFinished();

	FVector ActorInitLoc;
	FVector ActorTargetLoc;

};
