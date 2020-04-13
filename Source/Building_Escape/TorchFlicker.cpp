// Copyright Brian Medendorp 2020


#include "TorchFlicker.h"
#include "GameFramework/Actor.h"
#include "Components/LightComponent.h"
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
	const float MinIntensity = 3.0;
	const float MaxIntensity = 5.0;
	const float MinTime = 0.05;
	const float MaxTime = 0.1;
	static float TotalTime = 0.0;
	static float TargetTime = FMath::RandRange(MinTime, MaxTime);

	if ((TotalTime += DeltaTime) >= TargetTime)
	{
		GetOwner()->FindComponentByClass<ULightComponent>()->SetIntensity(FMath::RandRange(MinIntensity, MaxIntensity));
		TotalTime = 0.0;
		TargetTime = FMath::RandRange(MinTime, MaxTime);
	}
}

