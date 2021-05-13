#include "CObervable.h"

void CObervable::atach(CObserver* observer)
{
	m_observer = observer;
}

void CObervable::detach()
{
	m_observer->detach();
	m_observer = nullptr;
}

CObervable::~CObervable()
{
	if (m_observer != nullptr)
	{
		m_observer->detach();
	}
}
