#include "ArenaAbilitySystemComponent.h"

#include "Characters/ArenaCharacterBase.h"

UArenaAbilitySystemComponent::UArenaAbilitySystemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UArenaAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UArenaAbilitySystemComponent::OnRep_ActivateAbilities()
{
	Super::OnRep_ActivateAbilities();
	
	AArenaCharacterBase* Character = Cast<AArenaCharacterBase>(GetOwner());
	if (!Character)
	{
		return;
	}
	
	bool bAbilitiesChanged = false;
	if (LastActivatableAbilities.Num() != ActivatableAbilities.Items.Num())
	{
		bAbilitiesChanged = true;
	}
	else
	{
		for (int32 i = 0; i < LastActivatableAbilities.Num(); i++)
		{
			if (LastActivatableAbilities[i].Ability != ActivatableAbilities.Items[i].Ability)
			{
				bAbilitiesChanged = true;
				break;
			}
		}
	}
	if (bAbilitiesChanged)
	{
		Character->SendAbilitiesChangedEvent();
		LastActivatableAbilities = ActivatableAbilities.Items;
	}
	
}

void UArenaAbilitySystemComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                 FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

