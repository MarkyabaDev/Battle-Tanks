// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"

#include "TankAIController.generated.h"

class UTankAimingComponent;

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 5000.0f;

private:
	void BeginPlay() override;
	void Tick(float DeltaTime) override;

	void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void OnTankDeath();


};
