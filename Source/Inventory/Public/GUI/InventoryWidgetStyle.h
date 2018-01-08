// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyle.h"
#include "SlateWidgetStyleContainerBase.h"

#include "InventoryWidgetStyle.generated.h"

/**
 *
 */
USTRUCT()
struct INVENTORY_API FInventoryStyle : public FSlateWidgetStyle
{
	GENERATED_USTRUCT_BODY()

	FInventoryStyle();
	virtual ~FInventoryStyle();

	// FSlateWidgetStyle
	virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;
	static const FName TypeName;
	virtual const FName GetTypeName() const override { return TypeName; };
	static const FInventoryStyle& GetDefault();

  UPROPERTY(EditAnywhere, Category = Inventory)
  FSlateBrush SlotImage;

  UPROPERTY(EditAnywhere, Category = Inventory)
  FSlateBrush HoveredSlotImage;

  UPROPERTY(EditAnywhere, Category = Inventory)
  FSlateBrush BackgroundImage;

  UPROPERTY(EditAnywhere, Category = Inventory)
  float PanelWidth = 800;

  UPROPERTY(EditAnywhere, Category = Inventory)
  float PanelHeight = 1200;

  UPROPERTY(EditAnywhere, Category = Inventory)
  float SlotWidth = 65;

  UPROPERTY(EditAnywhere, Category = Inventory)
  float SlotHeight = 65;
};

/**
 */
UCLASS(DefaultToInstanced, EditInlineNew, hidecategories=Object, MinimalAPI)
class UInventoryWidgetStyle : public USlateWidgetStyleContainerBase
{
	GENERATED_BODY()

  public:
	/** The actual data describing the widget appearance. */
	UPROPERTY(Category=Appearance, EditAnywhere, meta=(ShowOnlyInnerProperties))
	FInventoryStyle WidgetStyle;

	virtual const struct FSlateWidgetStyle* const GetStyle() const override
	{
		return static_cast< const struct FSlateWidgetStyle* >( &WidgetStyle );
	}
};
