// Fill out your copyright notice in the Description page of Project Settings.


#include "ExplosiveBarrel.h"
#include "TMagic.h"

// Sets default values
AExplosiveBarrel::AExplosiveBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->meshComp = CreateDefaultSubobject<UStaticMeshComponent>("Berral");
	this->RootComponent = this->meshComp;
	this->meshComp->SetSimulatePhysics(true);

	this->radialForceComp = CreateDefaultSubobject<URadialForceComponent>("RadialForce");
	this->radialForceComp->SetupAttachment(this->meshComp);
	this->radialForceComp->ForceStrength = 1000.;
	this->radialForceComp->ImpulseStrength = 100000.;
	this->radialForceComp->Radius = 2000.;
}


void AExplosiveBarrel::NotifyActorBeginOverlap(AActor* OtherActor)
{
	UE_LOG(LogTemp, Log, TEXT("overlap"));
	if (Cast<ATMagic>(OtherActor))
	{
		this->fireRadialForce();
	}
	
}

void AExplosiveBarrel::fireRadialForce()
{
	this->radialForceComp->FireImpulse();
}

// Called when the game starts or when spawned
void AExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

