#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "ArenaGameplayAbility.generated.h"


UCLASS()
class AICOMBATARENA_API UArenaGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	bool bShouldShowInAbilitiesBar = false;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	UTexture2D* AbilityIcon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	FLinearColor AbilityColor = FLinearColor::White;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	FText KeyBinding;
};
