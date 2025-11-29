// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "DynamicGameplayEffect.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UDynamicGameplayEffect : public UGameplayEffect
{
	GENERATED_BODY()
	
public:
    virtual bool IsSupportedForNetworking() const override { return true; }

    virtual bool IsNameStableForNetworking() const override { return true; }
};
