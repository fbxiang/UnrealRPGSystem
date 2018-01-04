#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryGrid.h"
#include "InventoryComponent.generated.h"

UCLASS( Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INVENTORY_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()
  public:
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

  UPROPERTY(Instanced, EditAnywhere, BlueprintReadOnly, Category = Inventory)
  UInventoryGrid* InventoryGrid;
};
