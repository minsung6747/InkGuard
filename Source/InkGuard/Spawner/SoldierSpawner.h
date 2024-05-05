// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../MyNetWorking/Headers/Include.h"
#include "../Customs/CustomStructs.h"
#include "SoldierInterface.h"
#include "SoldierSpawner.generated.h"

UCLASS()
class INKGUARD_API ASoldierSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASoldierSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	void AppendNewDuty(const int& iSoldierType);

	UFUNCTION(BlueprintCallable, Category = "Setting to Object")
	void InitializeAboutSpawnerBySoldierInterface(AActor* pActor);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int iTargetTerritoryType = TERRITORY_END;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int iSpawnerColor = GAME_END;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSpawnDutyStruct> m_tSpawnInfos;
};