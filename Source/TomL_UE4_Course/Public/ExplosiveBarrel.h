// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Engine/StaticMesh.h"
#include "Components/StaticMeshComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "ExplosiveBarrel.generated.h"

UCLASS()
class TOML_UE4_COURSE_API AExplosiveBarrel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExplosiveBarrel();

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	void fireRadialForce();

protected:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* meshComp;

	UPROPERTY(EditAnywhere)
	URadialForceComponent* radialForceComp;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
