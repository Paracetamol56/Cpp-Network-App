#include "CObservable.h"

void CObservable::atach(CObserver* observer)
{
	m_observer = observer;
}

void CObservable::detach()
{
	m_observer = nullptr;
}

void CObservable::notify()
{
	m_observer->update();
}