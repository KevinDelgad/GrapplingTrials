// Fill out your copyright notice in the Description page of Project Settings.


#include "PTrigger.h"

// Sets default values
APTrigger::APTrigger()
{
	CollisionComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CollisionComp"));
	bActive = false;
}

void APTrigger::TriggerFire_Implementation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void APTrigger::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &APTrigger::TriggerFire);
}

void APTrigger::OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                               UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	TriggerFire(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}




