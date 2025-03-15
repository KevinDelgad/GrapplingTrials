// Fill out your copyright notice in the Description page of Project Settings.


#include "PTriggerHoop.h"

APTriggerHoop::APTriggerHoop()
{
	HoopMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HoopMesh"));
	RootComponent = HoopMesh;
	
	CollisionComp->SetupAttachment(RootComponent);

	bActive = true;
}
