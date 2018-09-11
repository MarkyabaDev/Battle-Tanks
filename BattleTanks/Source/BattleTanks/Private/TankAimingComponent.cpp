// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankTurret.h"
#include "TankBarrel.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	// ...
}

void UTankAimingComponent::Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{
	if (!BarrelToSet) { return; }
	if (!TurretToSet) { return; }

	Barrel = BarrelToSet;
	Turret = TurretToSet;
}


void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	FCollisionResponseParams CollisionResponse;
	TArray<AActor*> ActorsToIgnore;

	bool bSuggestionWorked = UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity,StartLocation, HitLocation, LaunchSpeed, false, 0,0,ESuggestProjVelocityTraceOption::DoNotTrace,  CollisionResponse, ActorsToIgnore);

	if (bSuggestionWorked) // Calculate the OutLaunchVelocity
	{
		FVector AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirecion)
{
	if (!Barrel || !Turret) { return; }
	// Work-out difference between current barrel rotation, and AimDirection
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirecion.Rotation();

	FRotator DeltaRotator = AimAsRotator - BarrelRotator;

	

	Barrel->Elevate(DeltaRotator.Pitch);	
	Turret->RotateAround(DeltaRotator.Yaw);
	// Move the barrel the right amount this frame

	// Given a max elevation speed, and the frame time

}

