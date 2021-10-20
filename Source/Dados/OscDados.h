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
    //void setFmParams(const float depth, const float frequency);

private:

    juce::dsp::Oscillator<float> fmOsc{ [](float x) {return std::sin(x); } };

    float fmMod { 0.0f };
    float fmDepth { 0.0f };
    int lastMidiNote { 0 };
};
