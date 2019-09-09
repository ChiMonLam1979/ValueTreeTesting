#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class State
{
public:

	int getValue();

	void setValue(const int& value);

	int myValue;

	CriticalSection objectLock;

private:

};