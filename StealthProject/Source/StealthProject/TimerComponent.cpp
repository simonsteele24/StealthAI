// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerComponent.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values for this component's properties
UTimerComponent::UTimerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTimerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTimerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTimerComponent::SetTransitionTime(float newTime) 
{
	TimeForTransition = newTime;
}

void UTimerComponent::ResetTimer() 
{
	StartTime = UKismetSystemLibrary::GetGameTimeInSeconds(GetWorld());
}

bool UTimerComponent::CheckTimer() 
{
	return UKismetSystemLibrary::GetGameTimeInSeconds(GetWorld()) - StartTime >= TimeForTransition;
}