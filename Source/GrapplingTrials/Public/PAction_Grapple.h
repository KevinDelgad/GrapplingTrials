// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PAction.h"
#include "PAction_Grapple.generated.h"

class APGrapple;
/**
 * 
 */
UCLASS()
class GRAPPLINGTRIALS_API UPAction_Grapple : public UPAction
{
	GENERATED_BODY()
protected:
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<APGrapple> GrappleClass;

	UFUNCTION()
	void Grapple(APCharacter* InstigatorCharacter);
	
	UPROPERTY(VisibleAnywhere, Category = "Effects")
	FName HandSocketName;

	UPROPERTY()
	AActor* CreatedGrapple;
	

public:
	
	virtual void StartAction_Implementation(AActor* Instigator) override;

	virtual void StopAction_Implementation(AActor* Instigator) override;

	UPAction_Grapple();
};
