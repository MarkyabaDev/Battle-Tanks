// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto controlledTank = Cast<ATank>(GetPawn());
	auto playerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (playerTank && controlledTank)
	{
		// Move Towards the Player
		MoveToActor(playerTank, AcceptanceRadius);// TODO Check Radius is in cm
		// Aimtowards the Player
		controlledTank->AimAt(playerTank->GetActorLocation());

		//controlledTank->Fire();	// TODO limit firing rate
	}
}
