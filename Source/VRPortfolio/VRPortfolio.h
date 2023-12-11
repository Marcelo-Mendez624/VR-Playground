// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


UENUM(BlueprintType, Blueprintable)
enum ECubeDirection
{
	Up UMETA(DispayName = "UP"),
	Down UMETA(DisplayName = "DOWN"),
	Left   UMETA(DisplayName = "LEFT"),
	Right  UMETA(DisplayName = "RIGHT")
};

UENUM(BlueprintType, Blueprintable)
enum EPlayerColor
{
	Primary UMETA(DispayName = "Primary"),
	Secondary UMETA(DisplayName = "Secondary"),
};