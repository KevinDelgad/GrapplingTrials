// Fill out your copyright notice in the Description page of Project Settings.


#include "PActionComponent.h"

#include "PAction.h"

// Sets default values for this component's properties
UPActionComponent::UPActionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPActionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

	for (TSubclassOf<UPAction> ActionClass: DefaultActions)
	{
		AddAction(GetOwner(), ActionClass);
	}
	
}

void UPActionComponent::AddAction(AActor* Instigator, TSubclassOf<UPAction> ActionClass)
{
	if (!ensureMsgf(ActionClass, TEXT("Action Class Cannot be Null!"))) { return; }

	//Create new instance of Action
	UPAction* ActionToAdd = NewObject<UPAction>(GetOuter(), ActionClass);
	
	if (CheckForAction(ActionToAdd->ActionName))
	{
		UE_LOG(LogTemp, Warning, TEXT("Action: %s is already owned by player!"), *ActionToAdd->ActionName.ToString());
		return;
	}

	Actions.Add(ActionToAdd);
	
	if (ActionToAdd->bAutoStart && ActionToAdd->CanStartAction(Instigator))
	{
		ActionToAdd->StartAction(Instigator);
	}
	
}

bool UPActionComponent::StartActionByName(AActor* Instigator, FName ActionName)
{
	
	for (UPAction* Action: Actions)
	{
		UE_LOG(LogTemp, Warning, TEXT("Action: %s"), *ActionName.ToString());
		UE_LOG(LogTemp, Warning, TEXT("FocusedAction: %s"), *Action->ActionName.ToString());
		
		if (Action && Action->ActionName == ActionName)
		{
			if (!Action->CanStartAction(Instigator))
			{
				FString FailedMsg = FString::Printf(TEXT("Failed To run: %s"), *ActionName.ToString());
				GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, FailedMsg);
				return false;
			}
			
			Action->StartAction(Instigator);
			return true;
		}
	}
	return false;

}

bool UPActionComponent::StopActionByName(AActor* Instigator, FName ActionName)
{
	for (UPAction* Action: Actions)
	{
		if (Action && Action->ActionName == ActionName)
		{
			if (!Action->IsRunning())
			{
				FString FailedMsg = FString::Printf(TEXT("Failed To Stop: %s"), *ActionName.ToString());
				GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, FailedMsg);
				return false;
			}
			
			Action->StopAction(Instigator);
			return true;
		}
	}
	return false;
}

void UPActionComponent::RemoveAction(UPAction* ActionToRemove)
{
}

bool UPActionComponent::CheckForAction(FName ActionToCheck)
{
	for (UPAction* Action: Actions)
	{
		if (Action->ActionName == ActionToCheck)
		{
			return true;
		}
	}

	return false;
}