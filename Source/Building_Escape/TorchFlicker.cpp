// Copyright Brian Medendorp 2020


#include "TorchFlicker.h"
#include "GameFramework/Actor.h"
#include "Components/PointLightComponent.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UTorchFlicker::UTorchFlicker()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTorchFlicker::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTorchFlicker::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	static float TotalTime = 0.0;
	static float TargetTime = FMath::RandRange(MinFlickerTime, MaxFlickerTime);

	if ((TotalTime += DeltaTime) >= TargetTime)
	{
		SetNewSourceRadius(SetNewIntensity());
		TotalTime = 0.0;
		TargetTime = FMath::RandRange(MinFlickerTime, MaxFlickerTime);
	}
}

float UTorchFlicker::SetNewSourceRadius(const float Intensity)
{
	float IntensityScale = (Intensity - MinFlickerIntensity) / (MaxFlickerIntensity - MinFlickerIntensity);
	float NewSourceRadius = IntensityScale * (MaxFlickerSourceRadius - MinFlickerSourceRadius) + MinFlickerSourceRadius;
	GetOwner()->FindComponentByClass<UPointLightComponent>()->SetSourceRadius(NewSourceRadius);
	return NewSourceRadius;
}

float UTorchFlicker::SetNewIntensity()
{
	float NewIntensity = FMath::RandRange(MinFlickerIntensity, MaxFlickerIntensity);
	GetOwner()->FindComponentByClass<UPointLightComponent>()->SetIntensity(NewIntensity);
	return NewIntensity;
}

