// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "LineTrace.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class KATANASLIDER_API ULineTrace : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULineTrace();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable)
	virtual void LineTraceStart();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Success = false; 
	AActor* MyActor;
		
};
