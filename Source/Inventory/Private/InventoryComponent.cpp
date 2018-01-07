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
  UItemStack::Create(TEXT("DebugRing1"), 1, this);
  // InventoryGrid->PutItemStackAt(0, 0, UItemStack::Create(TEXT("DebugRing1"), 1, this));
}

// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
