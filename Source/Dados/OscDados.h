/*
  ==============================================================================

    OscDados.h
    Created: 3 Sep 2021 9:58:20pm
    Author:  Artur

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class OscDados : public juce::dsp::Oscillator<float>
{
public:

    void prepareToPlay(juce::dsp::ProcessSpec& spec);
    void getNextAudioBlock(juce::dsp::AudioBlock<float>& block);
    void setWaveFreq(const int midiNoteNumber);
    void setWaveType(const int choice);
};
