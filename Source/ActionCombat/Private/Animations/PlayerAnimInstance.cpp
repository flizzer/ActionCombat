// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/PlayerAnimInstance.h"

void UPlayerAnimInstance::UpdateVelocity()
{
	//this syntax is weird to me, but apparently can define the PawnRef variable
	//this way and use the {} syntax to enforce strong typing. Called "Direct Initialization"
	//only works when initializing new variables though -- bhd
	APawn* PawnRef{ TryGetPawnOwner() };

	if (!IsValid(PawnRef)) { return; }

	FVector Velocity{ PawnRef->GetVelocity() };

	//explicitly casting from double to float -- bhd
	CurrentVelocity = static_cast<float>(Velocity.Length());
	
}
