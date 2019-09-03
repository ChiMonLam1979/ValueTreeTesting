#include "PluginProcessor.h"
#include "PluginEditor.h"

TestingValueTreeAudioProcessorEditor::TestingValueTreeAudioProcessorEditor (TestingValueTreeAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    setSize (400, 300);

	addAndMakeVisible(button1);
	addAndMakeVisible(button2);
	addAndMakeVisible(label);

	button1.onClick = [this] { doSomething(); };
	button2.onClick = [this] {doSomethingElse(); };
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
	button2.setBounds(window);
	label.setBounds(topSection.removeFromLeft(topSection.getWidth() / 2));
}

void TestingValueTreeAudioProcessorEditor::doSomething()
{
	//auto val = processor.treeState.state["SomeValue"];
	//auto newVal = (int)val;
	//processor.treeState.state.setProperty("SomeValue", ++newVal, nullptr);

	auto val = processor.treeState.state.getPropertyAsValue("SomeOtherValue", nullptr);
	auto myVal = (int)val.getValue();
	val = --myVal;
}

void TestingValueTreeAudioProcessorEditor::doSomethingElse()
{
	auto val = processor.treeState.state.getPropertyAsValue("SomeOtherValue", nullptr);
	//val = "oops!";
	auto myVal = (int)val.getValue();
	val = ++myVal;
}