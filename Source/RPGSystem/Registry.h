#pragma once

#include "CoreMinimal.h"
#include "Object.h"
#include "ItemRegistry.h"
#include "Registry.generated.h"

UCLASS(Blueprintable)
class RPGSYSTEM_API URegistry : public UObject
{
  GENERATED_BODY()
public:
	URegistry(const FObjectInitializer & objectInitializer);

  UPROPERTY(Instanced, EditAnywhere, BlueprintReadOnly, Category = Inventory)
  UItemRegistry* ItemRegistry;
};
