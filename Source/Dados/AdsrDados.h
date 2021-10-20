/*
  ==============================================================================

    AdsrDados.h
    Created: 31 Aug 2021 3:09:20pm
    Author:  Artur

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class AdsrDados : public juce::ADSR
{
public:

    void alterarADSR(const float attack, const float decay, const float sustain, const float release);

private:

    juce::ADSR::Parameters adsrParams;
    
};