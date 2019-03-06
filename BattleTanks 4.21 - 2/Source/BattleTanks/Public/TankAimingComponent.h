// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Classes/Kismet/GameplayStatics.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"



// Enum for Aiming state
UENUM()
enum class EFiringStatus : uint8
{
	Locked,
	Aiming,
	Reloading,
	OutOfAmmo
};

// Forward Declaration
class UTankBarrel;	
class UTankTurret;
class AProjectile;

// Holds parameters for barrel's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation);


	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

	EFiringStatus GetFiringState() const;

	UFUNCTION(BlueprintCallable, Category = "Firing")
	int32 GetRoundsLeft() const;
	
protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringStatus FiringStatus = EFiringStatus::Reloading;

private:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	FVector AimDirection = FVector::ZeroVector;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000;
	double LastFireTime = 0;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	void MoveBarrelTowards(FVector AimDirecion);

	bool IsBarrelMoving();

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	int32 RoundsLeft;
};
