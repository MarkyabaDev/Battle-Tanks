// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	FCollisionResponseParams CollisionResponse;
	TArray<AActor*> ActorsToIgnore;

	bool bSuggestionWorked = UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity,StartLocation, HitLocation, LaunchSpeed, false, 0,0,ESuggestProjVelocityTraceOption::DoNotTrace,  CollisionResponse, ActorsToIgnore, true);
	
	if (bSuggestionWorked) // Calculate the OutLaunchVelocity
	{
		FVector AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
		float Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: Aim solution found"), Time);
	}
	else
	{
		float Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: So aim solve found"), Time);
	}// If no solution found, do nothing
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirecion)
{
	// Work-out difference between current barrel rotation, and AimDirection
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirecion.Rotation();

	FRotator DeltaRotator = AimAsRotator - BarrelRotator;

	

	Barrel->Elevate(5);	//TODO remove magic number

	// Move the barrel the right amount this frame

	// Given a max elevation speed, and the frame time

}

