// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingBlock.h"

// Sets default values
AMovingBlock::AMovingBlock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
}

// Called when the game starts or when spawned
void AMovingBlock::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

	MoveDirection = MoveDirection.GetSafeNormal();
	
}

// Called every frame
void AMovingBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentOffset += MoveSpeed * DeltaTime * MoveSign;

	if (CurrentOffset >= MaxRange)
	{
		CurrentOffset = MaxRange;
		MoveSign = -1.0f;
	}
	
	else if (CurrentOffset <= -MaxRange)
	{
		CurrentOffset = -MaxRange;
		MoveSign = 1.0f;
	}
	
	SetActorLocation(StartLocation + MoveDirection * CurrentOffset);
}

