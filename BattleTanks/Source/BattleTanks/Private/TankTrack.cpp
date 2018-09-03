// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

void UTankTrack::SetThrottle(float throttle)
{
	//float Time = GetWorld()->GetTimeSeconds();


	// TODO Clamp actual throttle value so player can't one-drive
	auto ForceApplied = GetForwardVector() * throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();

	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}


