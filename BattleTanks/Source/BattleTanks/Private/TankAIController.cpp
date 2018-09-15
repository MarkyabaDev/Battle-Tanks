// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"



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
	AimingComponent->Fire();
}
