// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerNetwork.h"
#include "MyNetWorking/MyNetworkMgr.h"

// Sets default values for this component's properties
UPlayerNetwork::UPlayerNetwork()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

UPlayerNetwork::~UPlayerNetwork()
{
	m_pNetworkMgr = nullptr;
}


// Called when the game starts
void UPlayerNetwork::BeginPlay()
{
	Super::BeginPlay();
	m_pNetworkMgr = MyNetworkMgr::GetInstance();
	// ...
	
}

// Called every frame
void UPlayerNetwork::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	m_fSyncTimer += DeltaTime;

	if (!m_pNetworkMgr)
	{
		m_pNetworkMgr = MyNetworkMgr::GetInstance();
	}

	SendPlayerTransform(DeltaTime);
	RecvPlayerTransform(DeltaTime);


	m_pNetworkMgr->SetSyncTime(false);

}

#pragma region Packet
void UPlayerNetwork::SendPlayerTransform(float DeltaTime)
{
	FVector vPlayerPosition{ m_tPlayerStruct.pPlayer->GetActorLocation() };
	FRotator tPlayerRotation{ m_tPlayerStruct.pPlayer->GetActorRotation() };
	FVector vPlayerVelocity{ m_tPlayerStruct.pPlayer->GetVelocity() };

	if (m_fSyncTimer > SERVER_SYNC_TIME){
		m_pNetworkMgr->SetSyncTime(true);
	}

	m_pNetworkMgr->SendPlayerTransform(vPlayerPosition, tPlayerRotation, vPlayerVelocity);
}

void UPlayerNetwork::RecvPlayerTransform(float DeltaTime)
{
	if (!m_pNetworkMgr->GetSyncTime())
		return;

	S2C_PACKET_PLAYER_TRANSFORM tRecvPacket;

	if (!m_pNetworkMgr->RecvPlayerTransform(tRecvPacket))
		return;

	m_fSyncTimer = 0.f;
}

#pragma endregion

void UPlayerNetwork::SetPlayer(FPlayerStruct tPlayerData)
{
	m_tPlayerStruct = tPlayerData;
}