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
  GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, "Begin Play Called, initializing");
  InventoryGrid->Initialize();

  auto stack1 = UItemStack::Create(TEXT("Debugger"), 1, this);
  auto stack2 = UItemStack::Create(TEXT("DebugRing1"), 1, this);
  if (InventoryGrid->CanPutItemStackAt(1, 2, stack1)) {
    InventoryGrid->PutItemStackAt(1, 2, stack1);
  }
  if (InventoryGrid->CanPutItemStackAt(0, 0, stack2)) {
    InventoryGrid->PutItemStackAt(0, 0, stack2);
  }
}

// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
