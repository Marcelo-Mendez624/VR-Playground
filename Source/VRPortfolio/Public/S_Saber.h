// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VRPortfolio/VRPortfolio.h"
#include "S_Saber.generated.h"

class UProceduralMeshComponent;

UCLASS()
class VRPORTFOLIO_API AS_Saber : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AS_Saber();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* Base;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* Blade;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	USceneComponent* PointComponent;

	UPROPERTY(VisibleAnywhere)
	UProceduralMeshComponent* ProceduralReference;
	
};
