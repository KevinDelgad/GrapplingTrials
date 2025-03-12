// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PAction.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class GRAPPLINGTRIALS_API UPAction : public UObject
{
	GENERATED_BODY()

protected:
	
	bool bIsRunning;
	
public:

	UFUNCTION(BlueprintNativeEvent, Category = "Action")
	void StartAction(AActor* Instigator);

	UFUNCTION(BlueprintNativeEvent, Category = "Action")
	void StopAction(AActor* Instigator);
	
	UPROPERTY(EditAnywhere, Category = "Action")
	FName ActionName;
	
	UFUNCTION(BlueprintNativeEvent, Category = "Action")
	bool CanStartAction(AActor* Instigator);
	
	UPROPERTY(EditDefaultsOnly, Category="Actions")
	bool bAutoStart;

	UFUNCTION()
	bool IsRunning();

};
