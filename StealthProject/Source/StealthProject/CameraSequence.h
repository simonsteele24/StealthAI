// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CameraSequence.generated.h"

UCLASS()
class STEALTHPROJECT_API ACameraSequence : public APawn
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

public:
	// Sets default values for this pawn's properties
	ACameraSequence();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void RotateCameraAround(float dt);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = Rotation)
	float RotationSpeed = 20.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Duration)
	float SequenceDuration = 5.0f;

};
