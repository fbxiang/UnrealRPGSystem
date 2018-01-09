#pragma once

#include "CoreMinimal.h"
#include "GUI/HUDComponentBase.h"
#include "SingleSlotComponent.h"
#include "Widgets/SCanvas.h"
#include "MouseSlotHUDComponent.generated.h"

UCLASS()
class INVENTORY_API UMouseSlotHUDCComponent : public UHUDComponentBase
{
	GENERATED_BODY()
  public:

  virtual void Initialize() override;
  virtual void Open() override;
  virtual void Close() override;

  UFUNCTION(BlueprintCallable, Category = Inventory)
  void ConnectTo(USingleSlotComponent* slotComponent);

  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Appearence)
  float DisplayWidth = 100;

  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Appearence)
  float DisplayHeight = 100;
private:
  UPROPERTY()
  USingleSlotComponent* MouseSlotComponent;

  TSharedPtr<SCanvas> ItemCanvas;
  const FSlateBrush* GetItemImage();
  FVector2D GetItemSize();

  FReply HandleMouseMove(const FGeometry & geometry, const FPointerEvent & pointerEvent);
  FVector2D GetDrawPosition();
  FVector2D MousePosition;
};
