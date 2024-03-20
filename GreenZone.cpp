// Fill out your copyright notice in the Description page of Project Settings.


#include "GreenZone.h"

// Sets default values
AGreenZone::AGreenZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Tags.Add(FName("GreenZone"));
}

// Called when the game starts or when spawned
void AGreenZone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGreenZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

