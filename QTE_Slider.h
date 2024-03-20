// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "LineTrace.h"
#include "QTE_Slider.generated.h"

UCLASS()
class KATANASLIDER_API AQTE_Slider : public APawn
{
	GENERATED_BODY()

public:

	// Sets default values for this pawn's properties
	AQTE_Slider();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* SceneComponent;
	UPROPERTY(VisibleAnywhere)
	ULineTrace* LineTrace;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	FVector locator;
	UPROPERTY(BlueprintReadWrite)
	bool isRightEnd;
	float speedUp = 1.0f;
	void TraceStart();
	UPROPERTY(BlueprintReadWrite)
	int HP = 3; 
	bool Death = false;
	UPROPERTY(BlueprintReadWrite)
	int Score = 0;
	void DestroyActors();
	void SpawnActors();
	FTimerHandle TimerHandle;
};
