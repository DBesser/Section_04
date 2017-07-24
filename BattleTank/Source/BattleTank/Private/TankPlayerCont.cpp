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
		UE_LOG(LogTemp, Error, TEXT("PlayerController possessing: %s"), *ControlledTank->GetName());
	}
}


ATank* ATankPlayerCont::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}