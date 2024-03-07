// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CustomStructs.h"
#include "Components/ActorComponent.h"
#include "PlayerNetwork.generated.h"

class MyNetworkMgr;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INKGUARD_API UPlayerNetwork : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerNetwork();
	~UPlayerNetwork();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


public:
	UFUNCTION(BlueprintCallable, Category = "MyNetworking")
	void SetPlayer(FPlayerStruct tPlayerData);

private:
	void SendPlayerTransform(float DeltaTime);
	void RecvPlayerTransform(float DeltaTime);

private:
	MyNetworkMgr* m_pNetworkMgr = nullptr;
	FPlayerStruct m_tPlayerStruct; //Player->True
	float m_fSyncTimer = 0.f;
};
