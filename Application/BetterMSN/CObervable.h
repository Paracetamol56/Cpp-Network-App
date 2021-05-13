#pragma once

#ifndef PATTERN_H_OBSERVABLE
#define PATTERN_H_OBSERVABLE

#include "CObserver.h"

class CObervable
{
private:
	CObserver* m_observer;

public:
	void atach(CObserver* observer);
	void detach();

	void notify();
};

#endif // PATTERN_H_OBSERVABLE