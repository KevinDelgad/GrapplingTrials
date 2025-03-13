// Fill out your copyright notice in the Description page of Project Settings.


#include "PAction.h"

void UPAction::StartAction_Implementation(AActor* Instigator)
{
	UE_LOG(LogTemp, Display, TEXT("StartAction : %s"), *ActionName.ToString());

	bIsRunning = true;
}

void UPAction::StopAction_Implementation(AActor* Instigator)
{
	UE_LOG(LogTemp, Display, TEXT("StopAction : %s"), *ActionName.ToString());
	
	bIsRunning = false;
}

bool UPAction::CanStartAction_Implementation(AActor* Instigator)
{
	return !bIsRunning;
}

bool UPAction::IsRunning()
{
	return bIsRunning;
}
