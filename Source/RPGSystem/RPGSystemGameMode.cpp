// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "RPGSystemGameMode.h"
#include "RPGSystemCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARPGSystemGameMode::ARPGSystemGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
