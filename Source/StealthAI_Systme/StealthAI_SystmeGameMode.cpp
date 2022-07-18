// Copyright Epic Games, Inc. All Rights Reserved.

#include "StealthAI_SystmeGameMode.h"
#include "StealthAI_SystmeCharacter.h"
#include "UObject/ConstructorHelpers.h"

AStealthAI_SystmeGameMode::AStealthAI_SystmeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
