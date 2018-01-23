// Fill out your copyright notice in the Description page of Project Settings.

//#include "BattleTanks.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	auto controlledTank = GetControlledTank();

	if (!controlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No tank to control available"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is being controled by Player"), *(controlledTank->GetName()));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	// Get World location if linetrace through crosshair
	// If it hits the landscape
		// Tell controlled tank to aim at this point
}


