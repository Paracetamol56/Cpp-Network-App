#pragma once

#ifndef COBSERVABLE_H_INCLUDED
#define COBSERVABLE_H_INCLUDED

#include "CObserver.h"
#include <wx/wx.h>

class CObservable
{
private:
	CObserver* m_observer;

public:
	void atach(CObserver* observer);
	void detach();

	virtual void notify();
};

#endif // COBSERVABLE_H_INCLUDED