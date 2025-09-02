// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONCOMBAT_API UPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:
	//the {} indicates that we want explicit type conversion and that
	//an error will throw if we try to assign the wrong type value -- bhd
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation)
	float CurrentVelocity{ 0.0f };
};
