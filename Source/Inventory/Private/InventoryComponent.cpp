#include "InventoryComponent.h"
#include "ItemStack.h"


// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
  InventoryGrid->Initialize();

  // this line is for debug
  auto stack = UItemStack::Create(TEXT("DebugRing1"), 1, this);
  if (InventoryGrid->CanPutItemStackAt(0, 0, stack))
    InventoryGrid->PutItemStackAt(0, 0, stack);
}

// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
