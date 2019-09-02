#include "PluginProcessor.h"
#include "PluginEditor.h"

TestingValueTreeAudioProcessor::TestingValueTreeAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),treeState(*this, nullptr, "TreeState", createParameters())
#endif
{
	treeState.state.setProperty("SomeValue", 1, nullptr);
}

AudioProcessorValueTreeState::ParameterLayout TestingValueTreeAudioProcessor::createParameters()
{
	std::vector<std::unique_ptr<RangedAudioParameter>> parameters;

	return { parameters.begin(), parameters.end() };
}

TestingValueTreeAudioProcessor::~TestingValueTreeAudioProcessor()
{
}

const String TestingValueTreeAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool TestingValueTreeAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool TestingValueTreeAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool TestingValueTreeAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double TestingValueTreeAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int TestingValueTreeAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
}

int TestingValueTreeAudioProcessor::getCurrentProgram()
{
    return 0;
}

void TestingValueTreeAudioProcessor::setCurrentProgram (int index)
{
}

const String TestingValueTreeAudioProcessor::getProgramName (int index)
{
    return {};
}

void TestingValueTreeAudioProcessor::changeProgramName (int index, const String& newName)
{
}

void TestingValueTreeAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
}

void TestingValueTreeAudioProcessor::releaseResources()
{
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool TestingValueTreeAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void TestingValueTreeAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
    }
}

bool TestingValueTreeAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* TestingValueTreeAudioProcessor::createEditor()
{
    return new TestingValueTreeAudioProcessorEditor (*this);
}

void TestingValueTreeAudioProcessor::getStateInformation (MemoryBlock& destData)
{
	auto xml = treeState.state.createXml();

	copyXmlToBinary(*xml, destData);
}

void TestingValueTreeAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
	auto xmlState = getXmlFromBinary(data, sizeInBytes);

	if (xmlState != nullptr)
		if (xmlState->hasTagName(treeState.state.getType()))
			treeState.replaceState(ValueTree::fromXml(*xmlState));
}

AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new TestingValueTreeAudioProcessor();
}
