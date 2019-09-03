#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class MyLabel : public Label
{
public:

	MyLabel(AudioProcessorValueTreeState& state, const String& name);

	~MyLabel();

private:

	AudioProcessorValueTreeState& state;
};