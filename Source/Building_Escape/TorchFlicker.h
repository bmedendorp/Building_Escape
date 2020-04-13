// Copyright Brian Medendorp 2020

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TorchFlicker.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDING_ESCAPE_API UTorchFlicker : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTorchFlicker();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
