#include "GUIStateCallBack.h"

GUIStateCallBack::GUIStateCallBack(State& state, GUIState& guiState) :state(state), guiState(guiState)
{
	startTimer(30);
}

GUIStateCallBack::~GUIStateCallBack()
{
	
}

void GUIStateCallBack::timerCallback()
{
	guiState.setValue(state.getValue());
}