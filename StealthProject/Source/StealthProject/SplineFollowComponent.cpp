// Fill out your copyright notice in the Description page of Project Settings.


#include "SplineFollowComponent.h"

// Sets default values for this component's properties
USplineFollowComponent::USplineFollowComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USplineFollowComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USplineFollowComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USplineFollowComponent::SetSplinePath(USplineComponent* newComponent) 
{
	Path = newComponent;

	PathIndex++;
	PathIndex = PathIndex % Path->GetNumberOfSplinePoints();
}

bool USplineFollowComponent::CheckIfPointHasBeenReached(const FVector& actorLocation, const float& distanceForCheckToBeSuccessful) 
{
	FVector pointLocation = Path->GetLocationAtSplinePoint(PathIndex, ESplineCoordinateSpace::World);
	return FVector::Distance(actorLocation, pointLocation) <= distanceForCheckToBeSuccessful;
}

void USplineFollowComponent::MoveAlongSpline(AStealthProjectAIController* controller)
{
	FVector pointLocation = Path->GetLocationAtSplinePoint(PathIndex, ESplineCoordinateSpace::World);
	controller->MoveToLocation(pointLocation);
}