// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraSequence.h"
#include "GameFramework/SpringArmComponent.h"
#include "StealthProjectCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACameraSequence::ACameraSequence()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

}

// Called when the game starts or when spawned
void ACameraSequence::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraSequence::Tick(float DeltaTime)
{
	RotateCameraAround(DeltaTime);
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ACameraSequence::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACameraSequence::RotateCameraAround(float dt)
{
	FQuat quaternion = FQuat::MakeFromEuler(FVector(0.0f, 0.0f, dt * RotationSpeed));
	FRotator rotation = FRotator(quaternion);
	AddActorWorldRotation(rotation);
}