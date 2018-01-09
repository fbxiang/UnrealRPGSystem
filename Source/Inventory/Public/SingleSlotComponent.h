#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemSlot.h"
#include "ItemStack.h"
#include "SingleSlotComponent.generated.h"

UCLASS( Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INVENTORY_API USingleSlotComponent : public UActorComponent {
  GENERATED_BODY()
  public:
  USingleSlotComponent();

protected:
  virtual void BeginPlay() override;

public:
  virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

  UPROPERTY(Instanced, EditAnywhere, BlueprintReadOnly, Category = Inventory)
  UItemSlot* ItemSlot;

  UFUNCTION(BlueprintCallable, Category = Inventory)
  UItemStack* GetItemStack();
};
