#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Containers/Map.h"
#include "HUDComponentBase.h"
#include "RPGHUD.generated.h"

UCLASS()
class RPGMODULEBASE_API ARPGHUD : public AHUD {
  GENERATED_BODY()
  public:
  UPROPERTY(Instanced, EditAnywhere, BlueprintReadWrite)
  TMap<FName, UHUDComponentBase*> Components;
};
