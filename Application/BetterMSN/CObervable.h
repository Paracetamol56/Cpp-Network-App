#pragma once

#include "CObserver.h"

class CObervable
{
private:
	CObserver* m_observer = nullptr;

public:
	void atach(CObserver* observer);
	void detach();
	~CObervable();

	virtual void notify() = 0;
};

