// Copyright Ben Tristem 2016

#include "OoenDoor.h"

#include "BuildingEscape.h"
#include "Gameframework/Actor.h"

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

	//Find the wning Actor
	AActor* Owner = GetOwner();

	//Create a rotator
	FRotator  NewRotation = FRotator(0.0f, -60.0f, 0.0f);
	//Set the door rotation
	Owner->SetActorRotation(NewRotation);
}


// Called every frame
void UOoenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

