#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "GUIState.h"

class MyLabel : public Label
{
public:

	MyLabel(AudioProcessorValueTreeState& state, const String& name, GUIState& myState);

	~MyLabel();

private:

	AudioProcessorValueTreeState& state;

	GUIState& myState;
};
