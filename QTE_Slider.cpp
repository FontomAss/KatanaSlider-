
#include "QTE_Slider.h"
#include "Kismet/GameplayStatics.h"
#include "SpawnEnemy.h"
#include "Enemy.h"
#include "Components/SceneComponent.h"

// Sets default values
AQTE_Slider::AQTE_Slider() : Super()
{
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	SceneComponent->SetupAttachment(RootComponent);
	LineTrace = CreateDefaultSubobject<ULineTrace>(TEXT("LineTrace"));
	LineTrace->SetupAttachment(SceneComponent);
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
}


// Called when the game starts or when spawned
void AQTE_Slider::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AQTE_Slider::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (isRightEnd == false)
	{
		locator = GetActorLocation();
		locator.X = GetActorLocation().X + speedUp;
		SetActorLocation(locator);
	}
	else if (isRightEnd == true)
	{
		locator = GetActorLocation();
		locator.X = GetActorLocation().X - speedUp;
		SetActorLocation(locator);
	}
}

void AQTE_Slider::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction(TEXT("MouseLB"), IE_Pressed, this, &AQTE_Slider::TraceStart);
}

void AQTE_Slider::TraceStart()
{
	LineTrace->LineTraceStart();
	if (LineTrace->Success == true)
	{
		Score = Score + 1;
		DestroyActors();
		GetWorldTimerManager().SetTimer(TimerHandle, this, &AQTE_Slider::SpawnActors, 0.5f);
	}
	else
	{
		if (HP >= 2) 
		{
			HP = HP - 1;
		}
		else 
		{
			Death = true;
			HP = 3; 
			Score = 0;
			speedUp = 1;
		}
	}
	if (speedUp < 7)
	{
		speedUp = speedUp + 0.4;
	}
	
}

void AQTE_Slider::SpawnActors()
{
	{
		//Find the Actor Spawner in the world, and invoke it's Spawn Actor function
		AActor* ActorSpawnerTofind = UGameplayStatics::GetActorOfClass(GetWorld(), ASpawnEnemy::StaticClass());

		ASpawnEnemy* ActorSpawnerReference = Cast<ASpawnEnemy>(ActorSpawnerTofind);
		if (ActorSpawnerReference)
		{
			ActorSpawnerReference->SpawnActor();
		}
	}

}

void AQTE_Slider::DestroyActors()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemy::StaticClass(), FoundActors);
	for (AActor* ActorFound : FoundActors)
	{
		ActorFound->Destroy();
	}
}



