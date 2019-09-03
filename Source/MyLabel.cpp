#include "MyLabel.h"

MyLabel::MyLabel(AudioProcessorValueTreeState& state, const String& name): Label(name), state(state)
{
	getTextValue().referTo(state.state.getPropertyAsValue("SomeOtherValue", nullptr));
	setBorderSize(BorderSize<int>(20));
	setJustificationType(Justification::centred);
	setFont(Font(22.0f, Font::bold));
}

MyLabel::~MyLabel()
{
	
}