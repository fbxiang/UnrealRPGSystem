#include "MouseSlotHUDComponent.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/SWeakWidget.h"
#include "Application/SlateApplication.h"

void UMouseSlotHUDCComponent::Initialize() {
  TAttribute<const FSlateBrush*> itemImageAttribute = TAttribute<const FSlateBrush*>::Create(
      TAttribute<const FSlateBrush*>::FGetter::CreateUObject(this, &UMouseSlotHUDCComponent::GetItemImage));
  ItemCanvas = SNew(SCanvas)
  +SCanvas::Slot()
  .Size(TAttribute<FVector2D>::Create(
      TAttribute<FVector2D>::FGetter::CreateUObject(this, &UMouseSlotHUDCComponent::GetItemSize)))
  .Position(TAttribute<FVector2D>::Create(
      TAttribute<FVector2D>::FGetter::CreateUObject(this, &UMouseSlotHUDCComponent::GetDrawPosition)))
  [
      SNew(SImage).Image(itemImageAttribute)
   ];
  ItemCanvas->SetOnMouseMove(FPointerEventHandler::CreateUObject(this, &UMouseSlotHUDCComponent::HandleMouseMove));
}

void UMouseSlotHUDCComponent::Open() {
  GEngine->GameViewport->AddViewportWidgetContent(
      SNew(SWeakWidget).PossiblyNullContent(ItemCanvas.ToSharedRef()));
  ItemCanvas->SetVisibility(EVisibility::Visible);
}

void UMouseSlotHUDCComponent::Close() {
  ItemCanvas->SetVisibility(EVisibility::Hidden);
}

void UMouseSlotHUDCComponent::ConnectTo(USingleSlotComponent* slotComponent) {
  MouseSlotComponent = slotComponent;
}

const FSlateBrush* UMouseSlotHUDCComponent::GetItemImage() {
  if (!MouseSlotComponent) return NULL;
  UItemStack* stack = MouseSlotComponent->GetItemStack();
  if (!stack) return NULL;
  return stack->Item->GetTextureBrush();
}

FVector2D UMouseSlotHUDCComponent::GetItemSize() {
  if (!MouseSlotComponent) return FVector2D(0, 0);
  UItemStack* stack = MouseSlotComponent->GetItemStack();
  if (!stack) return FVector2D(0, 0);
  return FVector2D(stack->Item->Width * DisplayWidth, stack->Item->Height * DisplayHeight);
}

FReply UMouseSlotHUDCComponent::HandleMouseMove(const FGeometry & geometry, const FPointerEvent & pointerEvent) {
  MousePosition = geometry.AbsoluteToLocal(pointerEvent.GetScreenSpacePosition());
  return FReply::Handled();
}

FVector2D UMouseSlotHUDCComponent::GetDrawPosition() {
  return MousePosition - GetItemSize() / 2;
}
