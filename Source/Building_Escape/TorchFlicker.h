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

private:
	UPROPERTY(EditAnywhere, Category = FlickerAttributes)
	float MinFlickerIntensity = 3.0;
	UPROPERTY(EditAnywhere, Category = FlickerAttributes)
	float MaxFlickerIntensity = 5.0;
	UPROPERTY(EditAnywhere, Category = FlickerAttributes)
	float MinFlickerSourceRadius = 0.0;
	UPROPERTY(EditAnywhere, Category = FlickerAttributes)
	float MaxFlickerSourceRadius = 5.0;
	UPROPERTY(EditAnywhere, Category = FlickerAttributes)
	float MinFlickerTime = 0.05;
	UPROPERTY(EditAnywhere, Category = FlickerAttributes)
	float MaxFlickerTime = 0.1;

	float SetNewSourceRadius(const float Intensity);
	float SetNewIntensity();
};
