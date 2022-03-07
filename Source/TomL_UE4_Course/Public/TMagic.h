// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "TMagic.generated.h"

UCLASS()
class TOML_UE4_COURSE_API ATMagic : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATMagic();

protected:
	UPROPERTY(VisibleAnywhere)
	USphereComponent* sphereComp;

	UPROPERTY(VisibleAnywhere)
	UProjectileMovementComponent* projectileMoveComp;

	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* particalSystemComp;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
