#include "CObervable.h"

void CObervable::atach(CObserver* observer)
{
	m_observer = observer;
}

void CObervable::detach()
{
	m_observer = nullptr;
}

void CObervable::notify()
{
	m_observer->update();
}