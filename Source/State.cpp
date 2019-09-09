#include "State.h"

int State::getValue()
{

	const ScopedLock scopedLock(objectLock);

	return myValue;

	//std::shared_ptr<Value> valueToUse = std::atomic_load(&myCurrentValue);

	//myValue = std::atomic_load(&myCurrentValue)->getValue();

	//return myValue;

	//return *valueToUse;
}

void State::setValue(const int& value)
{
	const ScopedLock scopedLock(objectLock);

	myValue = value;     

	//std::shared_ptr<Value> myNewValue = std::make_shared<Value>(value);

	//std::atomic_store(&myCurrentValue, myNewValue);

	//myValue = std::atomic_load(&myCurrentValue)->getValue();
}