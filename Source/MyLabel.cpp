#include "MyLabel.h"

MyLabel::MyLabel(AudioProcessorValueTreeState& state, const String& name, GUIState& myState): Label(name), state(state), myState(myState)
{
	//getTextValue().referTo(state.state.getPropertyAsValue("SomeOtherValue", nullptr));

	getTextValue().referTo(myState.getValue());

	setBorderSize(BorderSize<int>(20));
	setJustificationType(Justification::centred);
	setFont(Font(22.0f, Font::bold));
}

MyLabel::~MyLabel()
{
	
}