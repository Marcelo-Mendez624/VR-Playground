// Fill out your copyright notice in the Description page of Project Settings.


#include "S_Pawn.h"

#include "MotionControllerComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
AS_Pawn::AS_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("VR Root"));
	RootComponent = RootScene;
	
	VRCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("VRCamera"));
	VRCamera->SetupAttachment(RootComponent);
	
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	BoxComponent->SetupAttachment(RootComponent);
	
	RightHand = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionRight"));
	RightHand->SetupAttachment(RootComponent);

	RightChildrenActor = CreateDefaultSubobject<UChildActorComponent>(TEXT("RightSaber"));
	RightChildrenActor->SetupAttachment(RightHand);
	
	LeftHand = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionLeft"));
	LeftHand->SetupAttachment(RootComponent);

	LeftChildrenActor = CreateDefaultSubobject<UChildActorComponent>(TEXT("LeftSaber"));
	LeftChildrenActor->SetupAttachment(LeftHand);

	
}

// Called when the game starts or when spawned
void AS_Pawn::BeginPlay()
{
	Super::BeginPlay();

	BoxComponent->OnComponentEndOverlap.AddDynamic(this, &AS_Pawn::OnComponentEndOverlap);
	
}


// Called to bind functionality to input
void AS_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AS_Pawn::OnComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	OtherActor->Destroy();
}

