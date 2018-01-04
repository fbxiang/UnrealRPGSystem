// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryWidgetStyle.h"


FInventoryStyle::FInventoryStyle()
{
}

FInventoryStyle::~FInventoryStyle()
{
}

const FName FInventoryStyle::TypeName(TEXT("FInventoryStyle"));

const FInventoryStyle& FInventoryStyle::GetDefault()
{
	static FInventoryStyle Default;
	return Default;
}

void FInventoryStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
  OutBrushes.Add(&SlotImage);
  OutBrushes.Add(&BackgroundImage);
	// Add any brush resources here so that Slate can correctly atlas and reference them
}

