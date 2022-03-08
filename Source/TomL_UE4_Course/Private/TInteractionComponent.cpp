// Fill out your copyright notice in the Description page of Project Settings.


#include "TInteractionComponent.h"
#include "TGameplayInterface.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UTInteractionComponent::UTInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTInteractionComponent::PrimaryInteract()
{
	FCollisionObjectQueryParams ObjectQueryParams;
	ObjectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);

	AActor* Owner = this->GetOwner();
	FVector EyeLocation;
	FRotator EyeRotation;
	Owner->GetActorEyesViewPoint(EyeLocation, EyeRotation);

	FVector EndVec = EyeLocation + EyeRotation.Vector() * 1000;

	FHitResult HitResult;
	this->GetWorld()->LineTraceSingleByObjectType(HitResult, EyeLocation, EndVec, ObjectQueryParams);

	FCollisionShape CollisionShape;
	CollisionShape.SetSphere(30.0);

	TArray<FHitResult> HitResults;
	if (this->GetWorld()->SweepMultiByObjectType(HitResults, EyeLocation, EndVec, FQuat::Identity, ObjectQueryParams, CollisionShape))
	{
		for (const auto& i : HitResults)
		{
			AActor* HitActor = i.GetActor();
			if (HitActor)
			{
				if (HitActor->Implements<UTGameplayInterface>())
				{
					APawn* Pawn = Cast<APawn>(Owner);

					
					ITGameplayInterface::Execute_Interact(HitActor, Pawn);
					break;
				}
			}
		}
	}



	//DrawDebugLine(this->GetWorld(), EyeLocation, EndVec, FColor(0, 255, 0), false, 0.5, 0, 2.0);
}

