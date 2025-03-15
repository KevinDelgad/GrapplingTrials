// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PTrigger.h"
#include "PTriggerHoop.generated.h"

/**
 * 
 */
UCLASS()
class GRAPPLINGTRIALS_API APTriggerHoop : public APTrigger
{
	GENERATED_BODY()

protected:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* HoopMesh;

public:
	APTriggerHoop();
	
};
