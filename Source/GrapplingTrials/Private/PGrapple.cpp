// Fill out your copyright notice in the Description page of Project Settings.


#include "PGrapple.h"
#include "CableComponent.h"
// Sets default values
APGrapple::APGrapple()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CableComp = CreateDefaultSubobject<UCableComponent>("CableComp");
	CableComp->SetVisibleFlag(false);
}

// Called when the game starts or when spawned
void APGrapple::BeginPlay()
{
	Super::BeginPlay();
}

void APGrapple::Fire()
{
}

void APGrapple::AttemptGrapple()
{
}


