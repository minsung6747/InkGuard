#pragma once
#include "GameObject.h"
#include "Include.h"

class CSoldier : public CGameObject
{
public:
	enum SOLDIER_TYPE { SOLDIER_SPEAR, SOLDIER_DAKA, SOLDIER_END };
	enum TERRITORY_TYPE { TERRITORY_A, TERRITORY_B, TERRITORY_C, TERRITORY_END, };

public:
	struct SOLDIERINFO //�������� �ε��� ��ȣ�� �߰��Ǿ���. Ŭ��� ����ü ������ �ٸ�.
	{
		SOLDIER_TYPE eSoldierType = SOLDIER_END;
		TERRITORY_TYPE eTargetTerritory = TERRITORY_END;
		int iSoldierIndex;
	};

public:// virtual
	virtual void Initialize() override;
	virtual void Release() override;

	virtual void SetSoldierInfo(const SOLDIER_TYPE eNewSoldierType, const TERRITORY_TYPE eNewTargetTerritoryType);
	virtual void SetSoldierInfo(const SOLDIERINFO tNewSoldierInfo) { m_tSoldierInfo = tNewSoldierInfo; };
	virtual void SetTargetTerritory(TERRITORY_TYPE eNewTargetTerritory) { m_tSoldierInfo.eTargetTerritory = eNewTargetTerritory; }
	
	virtual const SOLDIERINFO& GetSoldierInfo() { return m_tSoldierInfo; }

public:// normal
	void SetSoldierIndex(int iNewSoldierIndex) { m_tSoldierInfo.iSoldierIndex = iNewSoldierIndex; }

protected:
	SOLDIERINFO m_tSoldierInfo;
};
