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


private:
	void BeginPlay() override;
	void Tick(float DeltaTime) override;
	


	UPROPERTY(EditDefaultsOnly)
	float AcceptanceRadius = 30.0f;
};
