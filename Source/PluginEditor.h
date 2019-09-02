#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

class TestingValueTreeAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    TestingValueTreeAudioProcessorEditor (TestingValueTreeAudioProcessor&);
    ~TestingValueTreeAudioProcessorEditor();

    void paint (Graphics&) override;
    void resized() override;

	void doSomething();

private:
    TestingValueTreeAudioProcessor& processor;

	TextButton button1{ "Button One" };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TestingValueTreeAudioProcessorEditor)
};
