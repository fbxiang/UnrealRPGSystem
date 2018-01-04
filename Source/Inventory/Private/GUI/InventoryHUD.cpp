#include "InventoryHUD.h"
#include "Widgets/SWeakWidget.h"

void AInventoryHUD::BeginPlay() {
  PlayerInventory = SNew(SPlayerInventory).Rows(4).Columns(10)
  .Style(InventoryStyle ? &(InventoryStyle->WidgetStyle) : NULL);
  GEngine->GameViewport->AddViewportWidgetContent(
      SNew(SWeakWidget).PossiblyNullContent(PlayerInventory.ToSharedRef()));
  PlayerInventory->SetVisibility(EVisibility::Visible);
}
