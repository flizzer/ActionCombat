// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/PlayerAnimInstance.h"

void UPlayerAnimInstance::UpdateSpeed()
{
	//this syntax is weird to me, but apparently can define the PawnRef variable
	//this way and use the {} syntax to enforce strong typing. Called "Direct Initialization"
	//only works when initializing new variables though -- bhd
	APawn* PawnRef{ TryGetPawnOwner() };

	if (!IsValid(PawnRef)) { return; }

	FVector Velocity{ PawnRef->GetVelocity() };

	//explicitly casting from double to float -- bhd
	CurrentSpeed = static_cast<float>(Velocity.Length());
	
}

void UPlayerAnimInstance::HandleUpdatedTarget(AActor* NewTargetActorRef)
{
	bIsInCombat = IsValid(NewTargetActorRef);
}

void UPlayerAnimInstance::UpdateDirection()
{
	APawn* PawnRef{ TryGetPawnOwner() };

	if (!IsValid(PawnRef)) { return; }

	if (!bIsInCombat) { return; }

	CurrentDirection = CalculateDirection(
		PawnRef->GetVelocity(),
		PawnRef->GetActorRotation()
	);
}

