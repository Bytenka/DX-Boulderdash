#pragma once
#include "GameObject.h"

class Diamond : public GameObject
{
public:
	enum DiamondType
	{
		Green,
		Blue
	};

public:
	Diamond(DiamondType);
	~Diamond();
	void update();

private:
	DiamondType m_type;

private:
	void fall();
};

