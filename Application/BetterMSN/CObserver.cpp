#include "CObserver.h"

void CObserver::atach(CObervable* observable)
{
	m_observable = m_observable;
}

void CObserver::detach()
{
	m_observable = nullptr;
}

CObserver::~CObserver()
{
	if (m_observable != nullptr)
	{
		m_observable->detach();
	}
}
