/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
TCCSynthAudioProcessor::TCCSynthAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
    : AudioProcessor(BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
        .withInput("Input", juce::AudioChannelSet::stereo(), true)
#endif
        .withOutput("Output", juce::AudioChannelSet::stereo(), true)
#endif
    ), apvts (*this, nullptr, "Parameters", createParameters())
#endif
{
    synth.addSound(new SynthSound());
}

TCCSynthAudioProcessor::~TCCSynthAudioProcessor()
{
}

//==============================================================================
const juce::String TCCSynthAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool TCCSynthAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool TCCSynthAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool TCCSynthAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else

    return false;
   #endif
}

double TCCSynthAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int TCCSynthAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int TCCSynthAudioProcessor::getCurrentProgram()
{
    return 0;
}

void TCCSynthAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String TCCSynthAudioProcessor::getProgramName (int index)
{
    return {};
}

void TCCSynthAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void TCCSynthAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..

    synth.setCurrentPlaybackSampleRate(sampleRate);
    auto& choiceVoices = *apvts.getRawParameterValue("NUMVOICES");
    changeNumVoices(choiceVoices);
    addVoicesToSynth();

    for (int i = 0; i < synth.getNumVoices(); i++)
    {
        if (auto voice = dynamic_cast<SynthVoice*> (synth.getVoice(i)))
        {
            voice->prepareToPlay(sampleRate, samplesPerBlock, getTotalNumOutputChannels());
        }
    }

    filtro.prepareToPlay(sampleRate, samplesPerBlock, getTotalNumOutputChannels());
    
}

void TCCSynthAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
    
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool TCCSynthAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout

   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void TCCSynthAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (int i = 0; i < synth.getNumVoices(); i++)
    {
        if (auto voice = dynamic_cast<SynthVoice*>(synth.getVoice(i))) {
            
            auto& osc1WaveType = *apvts.getRawParameterValue("OSC1WAVETYPE");

            auto& attack = *apvts.getRawParameterValue("ATTACK");
            auto& decay = *apvts.getRawParameterValue("DECAY");
            auto& sustain = *apvts.getRawParameterValue("SUSTAIN");
            auto& release = *apvts.getRawParameterValue("RELEASE");

            auto& gain = *apvts.getRawParameterValue("GAIN");

            //==============================================================================

            voice->getOscillator().setWaveType(osc1WaveType);
            voice->alterar(attack.load(), decay.load(), sustain.load(), release.load());
            voice->getGain().setGainLevel(gain);
        }
    }

    synth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());

    auto& freqHP = *apvts.getRawParameterValue("FILTERHIGHPASSFREQ");
    auto& ressonanciaHP = *apvts.getRawParameterValue("FILTERRESHP");

    auto& freqLP = *apvts.getRawParameterValue("FILTERLOWPASSFREQ");
    auto& ressonanciaLP = *apvts.getRawParameterValue("FILTERRESLP");

    filtro.alterarParametros(freqHP, ressonanciaHP, freqLP, ressonanciaLP);
    filtro.process(buffer);

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
    }
}

//==============================================================================
bool TCCSynthAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* TCCSynthAudioProcessor::createEditor()
{
    return new TCCSynthAudioProcessorEditor (*this);
}

//==============================================================================
void TCCSynthAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void TCCSynthAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new TCCSynthAudioProcessor();
}

juce::AudioProcessorValueTreeState::ParameterLayout TCCSynthAudioProcessor::createParameters()
{
    std::vector<std::unique_ptr<juce::RangedAudioParameter>> parameters;

    // Oscillator
    parameters.push_back(std::make_unique<juce::AudioParameterChoice>
        ("OSC1WAVETYPE", "Osc 1 Wave Type", juce::StringArray{"Sine","Sawtooth", "Square", "Triangle"}, 0));

    // Voices
    parameters.push_back(std::make_unique<juce::AudioParameterChoice>
        ("NUMVOICES", "Num Voices", juce::StringArray{ "Monophonic","Poliphonic"}, 1));

    // ADSR
    parameters.push_back(std::make_unique<juce::AudioParameterFloat>("ATTACK", "Attack", juce::NormalisableRange<float>{ 0.0f, 1.0f, 0.01f }, 0.01f));
    parameters.push_back(std::make_unique<juce::AudioParameterFloat>("DECAY", "Decay", juce::NormalisableRange<float>{ 0.0f, 1.0f, 0.01f }, 0.0f));
    parameters.push_back(std::make_unique<juce::AudioParameterFloat>("SUSTAIN", "Sustain", juce::NormalisableRange<float>{ 0.0f, 1.0f, 0.01f }, 1.0f));
    parameters.push_back(std::make_unique<juce::AudioParameterFloat>("RELEASE", "Release", juce::NormalisableRange<float>{ 0.0f, 5.0f, 0.01f, 0.4f }, 0.1f));

    // Filtro
    parameters.push_back(std::make_unique<juce::AudioParameterFloat>("FILTERHIGHPASSFREQ", "Filter HighPass", juce::NormalisableRange<float>{ 0.0f, 20000.0f, 1.0f, 0.3f }, 0.0f));
    parameters.push_back(std::make_unique<juce::AudioParameterFloat>("FILTERRESHP", "Filter Resonance HP", juce::NormalisableRange<float>{ 1.0f, 10.0f, 0.01f}, 1.0f));

    parameters.push_back(std::make_unique<juce::AudioParameterFloat>("FILTERLOWPASSFREQ", "Filter LowPass", juce::NormalisableRange<float>{ 0.0f, 20000.0f, 1.0f, 1.2f }, 20000.0f));
    parameters.push_back(std::make_unique<juce::AudioParameterFloat>("FILTERRESLP", "Filter Resonance LP", juce::NormalisableRange<float>{ 1.0f, 10.0f, 0.01f}, 1.0f));

    // Gain
    parameters.push_back(std::make_unique<juce::AudioParameterFloat>("GAIN", "Gain", juce::NormalisableRange<float>{ -100.0f, 0.0f, 0.1f }, -18.0f));

    return { parameters.begin(), parameters.end() };
}

void TCCSynthAudioProcessor::addVoicesToSynth()
{
    synth.clearVoices();
    for ( int voice= 0;  voice< numVoices; ++voice)
    {
        synth.addVoice(new SynthVoice());
    }
}

void TCCSynthAudioProcessor::changeNumVoices(int choice)
{
    switch (choice)
    {
    case 0:
        numVoices = 1;
        break;

    case 1:
        numVoices = 10;
        break;
    }
}