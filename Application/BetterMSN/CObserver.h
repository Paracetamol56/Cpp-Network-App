#pragma once

#include "CObervable.h"

class CObserver
{
private:
	CObervable* m_observable = nullptr;

public:
	void atach(CObervable* observable);
	void detach();
	~CObserver();

	virtual void update() = 0;
};

