// Fill out your copyright notice in the Description page of Project Settings.


#include "TTreasureChect.h"

void ATTreasureChect::Interact_Implementation(APawn* interactor)
{
	this->LibMesh->SetRelativeRotation(FRotator(this->TargetPitch, 0, 0));
}

// Sets default values
ATTreasureChect::ATTreasureChect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->BashMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	this->RootComponent = this->BashMesh;
	this->LibMesh = CreateDefaultSubobject<UStaticMeshComponent>("LibMesh");

	this->TargetPitch = 110;
}

// Called when the game starts or when spawned
void ATTreasureChect::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATTreasureChect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

