// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PGrapple.generated.h"


class UProjectileMovementComponent;
class USphereComponent;
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



	//UPROPERTY(VisibleAnywhere)
	//USphereComponent* Hook;

	//UPROPERTY(EditDefaultsOnly, Category = "Grapple")
	//float GrappleRange;
	
	//UPROPERTY(VisibleAnywhere)
	//UProjectileMovementComponent* ProjectMovementComponent;

	//void Fire();
	
	//void AttemptGrapple();

	UPROPERTY(VisibleAnywhere)
	USphereComponent* SphereComp;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UProjectileMovementComponent* MovementComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCableComponent* CableComp;
};
