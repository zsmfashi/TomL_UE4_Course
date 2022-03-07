// Fill out your copyright notice in the Description page of Project Settings.


#include "TMagic.h"

// Sets default values
ATMagic::ATMagic()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->sphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	this->RootComponent = this->sphereComp;

	this->projectileMoveComp = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComp");
	this->projectileMoveComp->InitialSpeed = 1000;
	this->projectileMoveComp->bInitialVelocityInLocalSpace = true;
	this->projectileMoveComp->bRotationFollowsVelocity = true;

	this->particalSystemComp = CreateDefaultSubobject<UParticleSystemComponent>("ParticleSystemComp");
	this->particalSystemComp->SetupAttachment(this->RootComponent);
}

// Called when the game starts or when spawned
void ATMagic::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATMagic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

