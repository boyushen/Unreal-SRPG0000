// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlay/GridObjectBase.h"

// Sets default values
AGridObjectBase::AGridObjectBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGridObjectBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGridObjectBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

