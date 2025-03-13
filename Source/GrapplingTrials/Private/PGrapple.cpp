// Fill out your copyright notice in the Description page of Project Settings.


#include "PGrapple.h"
#include "CableComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
// Sets default values
APGrapple::APGrapple()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	//SphereComp->SetCollisionProfileName("Projectile");
	RootComponent = SphereComp;
	
	MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComp");
	MovementComp->InitialSpeed = 1000.0f;
	MovementComp->bRotationFollowsVelocity = true;
	MovementComp->bInitialVelocityInLocalSpace = true;
	MovementComp->ProjectileGravityScale = 0.0f;
	
	CableComp = CreateDefaultSubobject<UCableComponent>("CableComp");
	CableComp->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APGrapple::BeginPlay()
{
	Super::BeginPlay();
}


