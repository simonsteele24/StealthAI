// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StealthProjectCharacter.h"
#include "StealthProjectPlayer.generated.h"

/**
 * 
 */
UCLASS()
class STEALTHPROJECT_API AStealthProjectPlayer : public AStealthProjectCharacter
{
	GENERATED_BODY()
	
protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void StartSprint();
	void StopSprint();
	void StartCrouching();
	void StopCrouching();

public:

	UPROPERTY(BlueprintReadWrite) bool bIsCrouching = false;
	UPROPERTY(BlueprintReadWrite) bool bIsSprinting = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) float Health = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float HealthTakenFromShot = 10.0f;

	UFUNCTION(BlueprintCallable)
	void DamagePlayer();

};
