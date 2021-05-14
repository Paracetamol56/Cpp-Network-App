#pragma once

#ifndef COBSERVER_H_INCLUDED
#define COBSERVER_H_INCLUDED

class CObserver
{
public:
	virtual void update() = 0;
};

#endif // COBSERVER_H_INCLUDED