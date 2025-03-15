// Fill out your copyright notice in the Description page of Project Settings.


#include "PAction_Grapple.h"

#include "CableComponent.h"
#include "PCharacter.h"
#include "PGrapple.h"

UPAction_Grapple::UPAction_Grapple()
{
	HandSocketName = FName("hand_l");
}

void UPAction_Grapple::Grapple(APCharacter* InstigatorCharacter)
{
	if (ensureAlways(GrappleClass))
	{
		FVector HandLocation = InstigatorCharacter->GetMesh()->GetSocketLocation(HandSocketName);
		
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		SpawnParams.Instigator = InstigatorCharacter;

		FHitResult Hit;
		FVector TraceStart = InstigatorCharacter->GetPawnViewLocation();
		// endpoint far into the look-at distance (not too far, still adjust somewhat towards crosshair on a miss)
		FVector TraceEnd = TraceStart + (InstigatorCharacter->GetControlRotation().Vector() * 5000);
		FCollisionShape Shape;
		Shape.SetSphere(20.0f);
		// Ignore Player
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(InstigatorCharacter);
		FCollisionObjectQueryParams ObjParams;
		ObjParams.AddObjectTypesToQuery(ECC_WorldDynamic);
		ObjParams.AddObjectTypesToQuery(ECC_WorldStatic);
		ObjParams.AddObjectTypesToQuery(ECC_Pawn);
		FRotator ProjRotation;
		// true if we got to a blocking hit (Alternative: SweepSingleByChannel with ECC_WorldDynamic)
		if (GetWorld()->SweepSingleByObjectType(Hit, TraceStart, TraceEnd, FQuat::Identity, ObjParams, Shape, Params))
		{
			// Adjust location to end up at crosshair look-at
			ProjRotation = FRotationMatrix::MakeFromX(Hit.ImpactPoint - HandLocation).Rotator();
		}
		else
		{
			// Fall-back since we failed to find any blocking hit
			ProjRotation = FRotationMatrix::MakeFromX(TraceEnd - HandLocation).Rotator();
		}
		FTransform SpawnTM = FTransform(ProjRotation, HandLocation);
		
		CreatedGrapple = GetWorld()->SpawnActor<AActor>(GrappleClass, SpawnTM, SpawnParams);

		if (CreatedGrapple)
		{
			UCableComponent* CableComponent = CreatedGrapple->FindComponentByClass<UCableComponent>();

			if (ensureAlwaysMsgf(CableComponent, TEXT("Cable Component Not Found!")))
			{
				CableComponent->AttachToComponent(InstigatorCharacter->GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, HandSocketName);
			}
		}

	}
	//StopAction(InstigatorCharacter);
	//UE_LOG(LogTemp, Warning, TEXT("Grapple"));
}

void UPAction_Grapple::StartAction_Implementation(AActor* Instigator)
{
	Super::StartAction_Implementation(Instigator);
	APCharacter* Character = Cast<APCharacter>(Instigator);

	if (ensure(Character))
	{
		Grapple(Character);
	}
}

void UPAction_Grapple::StopAction_Implementation(AActor* Instigator)
{
	Super::StopAction_Implementation(Instigator);

	if (CreatedGrapple)
	{
		CreatedGrapple->Destroy();
	}
}
