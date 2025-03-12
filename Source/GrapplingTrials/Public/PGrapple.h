// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PGrapple.generated.h"


class UCableComponent;

UCLASS()
class GRAPPLINGTRIALS_API APGrapple : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APGrapple();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UCableComponent* CableComp;


	void Fire();
	
	void AttemptGrapple();
	
};
