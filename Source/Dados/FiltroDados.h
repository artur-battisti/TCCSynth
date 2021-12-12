/*
  ==============================================================================

    FiltroDados.h
    Created: 17 Sep 2021 10:16:29pm
    Author:  Artur

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class FiltroDados
{

public:

    void prepareToPlay(double sampleRate, int samplesPerBlock, int numChannels);
    void process(juce::AudioBuffer<float>& buffer);
    void alterarParametros(const float freq, const float ressonancia, const float freqLP, const float ressonanciaLP);

private:

    juce::dsp::StateVariableTPTFilter<float> filtroHP;
    juce::dsp::StateVariableTPTFilter<float> filtroLP;
    bool isOk = false;

};