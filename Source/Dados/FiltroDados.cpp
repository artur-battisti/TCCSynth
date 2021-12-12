/*
  ==============================================================================

    FiltroDados.cpp
    Created: 17 Sep 2021 10:16:29pm
    Author:  Artur

  ==============================================================================
*/

#include "FiltroDados.h"

void FiltroDados::prepareToPlay(double sampleRate, int samplesPerBlock, int numChannels)
{
    filtroHP.reset();
    filtroLP.reset();

    juce::dsp::ProcessSpec spec;
    spec.maximumBlockSize = samplesPerBlock;
    spec.sampleRate = sampleRate;
    spec.numChannels = numChannels;

    filtroHP.prepare(spec);
    filtroLP.prepare(spec);

    isOk = true;

}

void FiltroDados::process(juce::AudioBuffer<float>& buffer)
{

    jassert(isOk);

    juce::dsp::AudioBlock<float> block{ buffer };
    filtroHP.process(juce::dsp::ProcessContextReplacing<float> {block} );
    filtroLP.process(juce::dsp::ProcessContextReplacing<float> {block});
}

void FiltroDados::alterarParametros(const float freqHP, const float ressonanciaHP, const float freqLP, const float ressonanciaLP)
{

    filtroHP.setType(juce::dsp::StateVariableTPTFilterType::highpass);
    filtroHP.setCutoffFrequency(freqHP);
    filtroHP.setResonance(ressonanciaHP);

    filtroLP.setType(juce::dsp::StateVariableTPTFilterType::lowpass);
    filtroLP.setCutoffFrequency(freqLP);
    filtroLP.setResonance(ressonanciaLP);
}