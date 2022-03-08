// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TInteractionComponent.h"

#include "TCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UAnimMontage;

UCLASS()
class TOML_UE4_COURSE_API ATCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* springArmComp;

	UPROPERTY(VisibleAnywhere)
	UTInteractionComponent* InteractionComp;

	// Sets default values for this character's properties
	ATCharacter();
	
protected:
	UPROPERTY(EditAnywhere, Category = "Attack")
	TSubclassOf<AActor> projectileClass;

	UPROPERTY(EditAnywhere, Category = "Attack")
	UAnimMontage* AttackAnim;

	FTimerHandle TimerHandle_PAttack;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void moveForward(float v);

	void moveRight(float v);

	void PAttack();

	void PAttack_Fire();

	void PInteraction();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
