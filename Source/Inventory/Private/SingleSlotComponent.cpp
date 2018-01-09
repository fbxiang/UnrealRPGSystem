#include "SingleSlotComponent.h"

USingleSlotComponent::USingleSlotComponent() {
  PrimaryComponentTick.bCanEverTick = true;
}

void USingleSlotComponent::BeginPlay() {
  Super::BeginPlay();
  ItemSlot->PutItemStack(UItemStack::Create(TEXT("Debugger"), 1, this));
}

void USingleSlotComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
  Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

UItemStack* USingleSlotComponent::GetItemStack() {
  if (ItemSlot)
    return ItemSlot->GetItemStack();
  return NULL;
}
