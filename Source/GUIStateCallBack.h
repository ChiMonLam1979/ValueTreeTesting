#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "GUIState.h"
#include "State.h"

class GUIStateCallBack : public Timer
{
public:


	GUIStateCallBack(State& state, GUIState& guiState);

	~GUIStateCallBack();


private:

	void timerCallback() override;

	State& state;

	GUIState& guiState;

};