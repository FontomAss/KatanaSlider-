// Fill out your copyright notice in the Description page of Project Settings.


#include "LineTrace.h"
#include "GreenZone.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/EngineTypes.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
ULineTrace::ULineTrace()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
 	// ...
}


// Called when the game starts
void ULineTrace::BeginPlay()
{
	Super::BeginPlay();
	// ...
	
}


// Called every frame
void ULineTrace::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{

}
void ULineTrace::LineTraceStart()
{
	FVector Start = GetOwner()->GetActorLocation();
	FVector End = ((GetForwardVector() * 500.0f) + Start);

	struct FHitResult HitResuld;
	TArray<AActor*> ActorsToIgnore;
	bool bHid = UKismetSystemLibrary::LineTraceSingle(this, Start, End, UEngineTypes::ConvertToTraceType(ECC_Camera), false, ActorsToIgnore, EDrawDebugTrace::ForDuration, HitResuld, true, FLinearColor::Yellow, FLinearColor::White, 0.1f);
	if (bHid)
	{
		if (HitResuld.GetActor()->GetName() == "GreenZone_C_3")
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, FString::Printf(TEXT("Trac")));
			Success = true;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString::Printf(TEXT("Trace Hit: %s"), *HitResuld.GetActor()->GetName()));
			Success = false;
		}
		
	}
}

