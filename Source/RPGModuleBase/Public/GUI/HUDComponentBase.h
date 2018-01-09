#pragma once

#include "CoreMinimal.h"
#include "Object.h"
#include "HUDComponentBase.generated.h"

UCLASS(DefaultToInstanced, EditInlineNew, Blueprintable, Abstract)
class RPGMODULEBASE_API UHUDComponentBase : public UObject {
  GENERATED_BODY()
  public:

  UFUNCTION(BlueprintCallable, Category = HUDComponent)
  virtual void Initialize() PURE_VIRTUAL(UHUDComponentBase::Initialize,);

  UFUNCTION(BlueprintCallable, Category = HUDComponent)
  virtual void Open() PURE_VIRTUAL(UHUDComponentBase::Open,);

  UFUNCTION(BlueprintCallable, Category = HUDComponent)
  virtual void Close() PURE_VIRTUAL(UHUDComponentBase::Close,);
};
