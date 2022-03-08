// Fill out your copyright notice in the Description page of Project Settings.

#include "TCharacter.h"


// Sets default values
ATCharacter::ATCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->springArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	this->springArmComp->SetupAttachment(this->RootComponent);
	this->springArmComp->bUsePawnControlRotation = true;

	this->CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	this->CameraComp->SetupAttachment(this->springArmComp);
	
	this->InteractionComp = CreateDefaultSubobject<UTInteractionComponent>("InteractionComp");

	this->bUseControllerRotationYaw = false;
	this->GetCharacterMovement()->bOrientRotationToMovement = true;
}

// Called when the game starts or when spawned
void ATCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATCharacter::moveForward(float v)
{
	FRotator rotator = this->GetControlRotation();
	rotator.Pitch = 0;
	rotator.Roll = 0;
	this->AddMovementInput(rotator.Vector(), v);
}

void ATCharacter::moveRight(float v)
{
	FRotator rotator = this->GetControlRotation();
	rotator.Pitch = 0;
	rotator.Roll = 0;

	const auto&& rVec = FRotationMatrix(rotator).GetScaledAxis(EAxis::Y);

	this->AddMovementInput(rVec, v);
}

void ATCharacter::PAttack()
{
	this->PlayAnimMontage(this->AttackAnim);

	this->GetWorldTimerManager().SetTimer(this->TimerHandle_PAttack, this, &ATCharacter::PAttack_Fire, 0.2);
}

void ATCharacter::PAttack_Fire()
{
	FVector handLocation = this->GetMesh()->GetSocketLocation("Muzzle_01");

	FTransform transform = FTransform(this->GetControlRotation(), handLocation);

	FActorSpawnParameters spawnParameters;
	spawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	this->GetWorld()->SpawnActor<AActor>(this->projectileClass, transform, spawnParameters);
}

void ATCharacter::PInteraction()
{
	this->InteractionComp->PrimaryInteract();
}

// Called every frame
void ATCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ATCharacter::moveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ATCharacter::moveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("PAttack", IE_Pressed, this, &ATCharacter::PAttack);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ATCharacter::Jump);
	PlayerInputComponent->BindAction("PInteraction", IE_Pressed, this, &ATCharacter::PInteraction);
}

