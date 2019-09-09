#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "MyLabel.h"
#include "GUIState.h"
#include "GUIStateCallBack.h"

class TestingValueTreeAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    TestingValueTreeAudioProcessorEditor (TestingValueTreeAudioProcessor&);
    ~TestingValueTreeAudioProcessorEditor();

    void paint (Graphics&) override;
    void resized() override;

	void doSomething();
	void doSomethingElse();

private:
    TestingValueTreeAudioProcessor& processor;

	State& myState;

	GUIState guiState;

	GUIStateCallBack guiStateCallBack{ myState, guiState};

	TextButton button1{ "Button One" };

	TextButton button2{ "Button Two" };

	MyLabel label{ processor.treeState, "label", guiState };

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TestingValueTreeAudioProcessorEditor)

};