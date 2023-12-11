// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "S_Pawn.generated.h"

class UCameraComponent;
class UBoxComponent;
class UMotionControllerComponent;

UCLASS()
class VRPORTFOLIO_API AS_Pawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AS_Pawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
protected:
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Components")
	USceneComponent* RootScene;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Components")
	UCameraComponent* VRCamera;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Components")
	UMotionControllerComponent* RightHand;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Components")
	UChildActorComponent* RightChildrenActor;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Components")
	UMotionControllerComponent* LeftHand;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Components")
	UChildActorComponent* LeftChildrenActor;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Components")
	UBoxComponent* BoxComponent;

public:
	UFUNCTION()
	void OnComponentEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
