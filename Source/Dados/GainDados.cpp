/*
  ==============================================================================

    GainDados.cpp
    Created: 21 Oct 2021 3:06:34pm
    Author:  Artur

  ==============================================================================
*/

#include "GainDados.h"

void GainDados::prepare(const juce::dsp::ProcessSpec& spec)
{
    gain.prepare(spec);
}

void GainDados::setGainLevel(const float newGain)
{
    gain.setGainLinear(newGain);
}

void GainDados::process(juce::dsp::ProcessContextReplacing<float>(audioBlock))
{
    gain.process(juce::dsp::ProcessContextReplacing<float>(audioBlock));
}

void GainDados::reset()
{
    gain.reset();
}