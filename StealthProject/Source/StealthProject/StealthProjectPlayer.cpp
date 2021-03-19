// Fill out your copyright notice in the Description page of Project Settings.


#include "StealthProjectPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

void AStealthProjectPlayer::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AStealthProjectPlayer::StartSprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AStealthProjectPlayer::StopSprint);

	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AStealthProjectPlayer::StartCrouching);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &AStealthProjectPlayer::StopCrouching);

	PlayerInputComponent->BindAxis("MoveForward", this, &AStealthProjectCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AStealthProjectCharacter::MoveRight);
}

void AStealthProjectPlayer::StartSprint() 
{
	if (!bIsCrouching) 
	{
		bIsSprinting = true;
		GetCharacterMovement()->MaxWalkSpeed = 500.0f;
	}
}

void AStealthProjectPlayer::StopSprint() 
{
	bIsSprinting = false;
	GetCharacterMovement()->MaxWalkSpeed = 200.0f;
}

void AStealthProjectPlayer::StartCrouching() 
{
	bIsCrouching = true;
}

void AStealthProjectPlayer::StopCrouching() 
{
	bIsCrouching = false;
}

void AStealthProjectPlayer::DamagePlayer() 
{
	Health -= HealthTakenFromShot;

	if (Health <= 0) 
	{
		UGameplayStatics::OpenLevel(GetWorld(),FName(*UGameplayStatics::GetCurrentLevelName(GetWorld())));
	}
}