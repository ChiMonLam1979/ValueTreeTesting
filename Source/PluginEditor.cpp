#include "PluginProcessor.h"
#include "PluginEditor.h"

TestingValueTreeAudioProcessorEditor::TestingValueTreeAudioProcessorEditor (TestingValueTreeAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    setSize (400, 300);

	addAndMakeVisible(button1);

	button1.onClick = [this] { doSomething(); };
}

TestingValueTreeAudioProcessorEditor::~TestingValueTreeAudioProcessorEditor()
{
}

void TestingValueTreeAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void TestingValueTreeAudioProcessorEditor::resized()
{

	auto window = getLocalBounds();

	auto topSection = window.removeFromTop(window.getHeight() / 2);

	auto bottomLeftCorner = window.removeFromLeft(window.getWidth() / 2);

	button1.setBounds(bottomLeftCorner);
}

void TestingValueTreeAudioProcessorEditor::doSomething()
{
	auto val = processor.treeState.state["SomeValue"];
	auto newVal = (int)val;
	processor.treeState.state.setProperty("SomeValue", ++newVal, nullptr);
}