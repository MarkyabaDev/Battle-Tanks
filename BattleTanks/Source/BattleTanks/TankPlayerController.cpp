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

	FVector HitLocation;	// Out Parameter
	if (GetSightRayHitLocation(HitLocation))	// Has "side-effect", is going to line trace
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString());
		
		// TODO Tell controlled tank to aim at this point
	}
	
}

// Get World location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	
	// "De-project" the screen position of the crosshair to a world direction
	// Line-trace along that look direction, and see what we hit (up to max range)
	return true;
}


