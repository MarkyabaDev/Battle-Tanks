// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Tank.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto controlledTank = GetPawn();
	auto playerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	if(!ensure(playerTank && controlledTank)) { return; }
	

	// Move Towards the Player
	MoveToActor(playerTank, AcceptanceRadius);// TODO Check Radius is in cm
	
	auto AimingComponent = controlledTank->FindComponentByClass<UTankAimingComponent>();

	AimingComponent->AimAt(playerTank->GetActorLocation());	

	if (AimingComponent->GetFiringState() == EFiringStatus::Locked)
	{
		AimingComponent->Fire();
	}
}

void ATankAIController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossesedTank = Cast<ATank>(InPawn);
		if (!ensure(PossesedTank)) { return; }

		// Subscribe our local Method to the tank's death event
		PossesedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnTankDeath);
	}
}

void ATankAIController::OnTankDeath()
{
	if (!GetPawn()) { return; }

	GetPawn()->DetachFromControllerPendingDestroy();
}
