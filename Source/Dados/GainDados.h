/*
  ==============================================================================

    GainDados.h
    Created: 21 Oct 2021 3:06:34pm
    Author:  Artur

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class GainDados
{

public:

    void prepare(const juce::dsp::ProcessSpec& spec);
    void setGainLevel(const float newGain);
    void process(juce::dsp::ProcessContextReplacing<float>(audioBlock));
    void reset();

private:

    juce::dsp::Gain<float> gain;
};