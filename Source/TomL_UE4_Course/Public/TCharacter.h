// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

#include "TCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class TOML_UE4_COURSE_API ATCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* springArmComp;

	// Sets default values for this character's properties
	ATCharacter();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void moveForward(float v);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
