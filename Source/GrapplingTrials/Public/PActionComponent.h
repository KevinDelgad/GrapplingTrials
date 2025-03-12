// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PActionComponent.generated.h"


class UPAction;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GRAPPLINGTRIALS_API UPActionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPActionComponent();

	void AddAction(AActor* Instigator, TSubclassOf<UPAction> ActionClass);

	bool StartActionByName(AActor* Instigator, FName ActionName);

	bool StopActionByName(AActor* Instigator, FName ActionName);

	void RemoveAction(UPAction* ActionToRemove);
	
	bool CheckForAction(FName ActionToCheck);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY()
	TArray<UPAction*> Actions;

	UPROPERTY(EditDefaultsOnly, Category = "Actions")
	TArray<TSubclassOf<UPAction>> DefaultActions;
};
