#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "ArenaAbilitySystemComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class AICOMBATARENA_API UArenaAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UArenaAbilitySystemComponent();
	
protected:
	
	TArray<FGameplayAbilitySpec> LastActivatableAbilities;

protected:
	virtual void BeginPlay() override;
	
	virtual void OnRep_ActivateAbilities() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
