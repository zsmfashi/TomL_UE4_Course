// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TGameplayInterface.h"
#include "TTreasureChect.generated.h"

UCLASS()
class TOML_UE4_COURSE_API ATTreasureChect : public AActor, public ITGameplayInterface
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	float TargetPitch;

	void Interact_Implementation(APawn* interactor);
	
public:	
	// Sets default values for this actor's properties
	ATTreasureChect();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BashMesh;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* LibMesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
