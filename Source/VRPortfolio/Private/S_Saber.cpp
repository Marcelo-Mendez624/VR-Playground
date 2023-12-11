// Fill out your copyright notice in the Description page of Project Settings.


#include "S_Saber.h"

#include "Kismet/KismetMathLibrary.h"

// Sets default values
AS_Saber::AS_Saber()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Base = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	RootComponent = Base;

	Blade =  CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BladeMesh"));
	Blade->SetupAttachment(Base);

	PointComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Point"));
	PointComponent->SetupAttachment(Blade);

}

// Called when the game starts or when spawned
void AS_Saber::BeginPlay()
{
	Super::BeginPlay();


}


