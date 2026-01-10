// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Aura/Aura.h"
#include "GameFramework/PlayerStart.h"
#include "Interaction/HighlightInterface.h"
#include "Checkpoint.generated.h"

class USphereComponent;

/**
 * 
 */
UCLASS()
class AURA_API ACheckpoint : public APlayerStart, public IHighlightInterface
{
	GENERATED_BODY()
	
public:
	ACheckpoint(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(BlueprintReadWrite, SaveGame)
	bool bReached = false;

	UPROPERTY(EditAnywhere)
	bool bBindOverlapCallback = true;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool ShouldLoadTransform();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void LoadActor();

	virtual void BeginPlay() override;

	/* Highlight Interface */
	virtual void SetMoveToLocation_Implementation(FVector& OutDestination) override;
	virtual void HighlightActor_Implementation() override;
	virtual void UnHighlightActor_Implementation() override;
	/* Highlight Interface */

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USceneComponent> MoveToComponent;

	UPROPERTY(EditDefaultsOnly)
	int32 CustomDepthStencilOverride = CUSTOM_DEPTH_TAN;

protected:
	UFUNCTION()
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintImplementableEvent)
	void CheckpointReached(UMaterialInstanceDynamic* DynamicMaterialInstance); 

	UFUNCTION(BlueprintCallable)
	void HandleGlowEffects();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> CheckpointMesh;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> Sphere;
};
