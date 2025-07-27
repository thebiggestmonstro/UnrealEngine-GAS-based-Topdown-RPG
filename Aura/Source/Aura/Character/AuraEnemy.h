// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/HighlightInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IHighlightInterface
{
	GENERATED_BODY()
	
public:
	AAuraEnemy();
	
	/** Highlight Interface */
	virtual void HighlightActor_Implementation() override;
	virtual void UnHighlightActor_Implementation() override;
	/** end Highlight Interface */

	/** Combat Interface */
	virtual int32 GetPlayerLevel_Implementation() override;
	/** end Combat Interface */

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;

protected:
	/*
	* Property Section
	*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	int32 Level = 1;
};
