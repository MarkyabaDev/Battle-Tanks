// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"




void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto controlledTank = GetControlledTank();
	

	if (!controlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No tank to control available"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is being controled by AI"), *(controlledTank->GetName()));
	}

	auto playerTank = GetPlayerTank();

	if (!playerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player tank could not be found"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Aiming at %s"), *(playerTank->GetName()));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
