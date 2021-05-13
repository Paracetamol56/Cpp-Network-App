#pragma once

#ifndef PATTERN_H_OBSERVER
#define PATTERN_H_OBSERVER

class CObserver
{
public:
	virtual void update() = 0;
};

#endif // PATTERN_H_OBSERVER