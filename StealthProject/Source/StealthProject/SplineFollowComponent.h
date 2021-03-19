// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/SplineComponent.h"
#include "StealthProjectAIController.h"
#include "SplineFollowComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STEALTHPROJECT_API USplineFollowComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USplineFollowComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	USplineComponent * Path;
	int PathIndex = 0;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable) void SetSplinePath(USplineComponent* newComponent);
	UFUNCTION(BlueprintCallable) void MoveAlongSpline(AStealthProjectAIController* controller);
	UFUNCTION(BlueprintCallable) bool CheckIfPointHasBeenReached(const FVector& actorLocation, const float & distanceForCheckToBeSuccessful);

};
