// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerCont.h"
#include "BattleTank.h"

void ATankPlayerCont::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("PlayController not possessing a tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName()));
	}
}

// Called every frame
void ATankPlayerCont::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	UE_LOG(LogTemp, Error, TEXT("Ticker is working, captain."));

}

ATank* ATankPlayerCont::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerCont::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	//Get World location if linetrace through crosshair
	//if it hits landscape
		//tell controlled tank to aim at this point
}