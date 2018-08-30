// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "TankAimingComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();

protected: 
	UTankAimingComponent* TankAimingComponent = nullptr;
private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint; //Alternative TSubClass<>

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 100000;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimeInSeconds = 3;

	// Sets default values for this pawn's properties
	ATank();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UTankBarrel* Barrel = nullptr;

	double LastFireTime = 0;
};
