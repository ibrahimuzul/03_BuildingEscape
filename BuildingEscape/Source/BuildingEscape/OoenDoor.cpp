// Copyright Ben Tristem 2016

#include "OoenDoor.h"

#include "BuildingEscape.h"
#include "Gameframework/Actor.h"
#include "Grabber.h"

#define OUT

// Sets default values for this component's properties
UOoenDoor::UOoenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOoenDoor::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetOwner();
	//ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	//OpenDoor();
}




// Called every frame
void UOoenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the Trigger Volume
	if (GetTotalMassOfActorsOnPlate() > TriggerMass) // TODO make into a parameter
	{
		OnOpen.Broadcast();
	
	}
	else
	{
		OnClose.Broadcast();
	}
}

float UOoenDoor::GetTotalMassOfActorsOnPlate()
{
	float TotalMass = 0.f;

	// Find all the overlapping actors
	TArray<AActor*> OverlappingActors;
	if (!PressurePlate) { return TotalMass; }
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);

	// Iterate through them adding their masses
	for (const auto& Actor : OverlappingActors)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate"), *Actor->GetName());
	}
	UE_LOG(LogTemp, Warning, TEXT("%f total mass"), TotalMass);
	return TotalMass;
}