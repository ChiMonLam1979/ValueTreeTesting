#include "GUIState.h"

Value GUIState::getValue()
{
	return myValue;
}

void GUIState::setValue(int value)
{
	myValue = value;
}