/*
  ==============================================================================

    SynthVoice.h
    Created: 24 Aug 2021 9:55:59pm
    Author:  Artur

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "SynthSound.h"
#include "Dados/AdsrDados.h"
#include "Dados/OscDados.h"

class SynthVoice : public juce::SynthesiserVoice
{
public:
    bool canPlaySound(juce::SynthesiserSound* sound) override;
    void startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition) override;
    void stopNote(float velocity, bool allowTailOff) override;
    void controllerMoved(int controllerNumber, int newControllerValue) override;
    void pitchWheelMoved(int newPitchWheelValue) override;
    void prepareToPlay(double sampleRate, int samplesPerBlock, int outputChannels);
    void alterar(const float attack, const float decay, const float sustain, const float release);
    void renderNextBlock(juce::AudioBuffer< float >& outputBuffer, int startSample, int numSamples) override;

    OscDados& getOscillator() { return osc; }

private:

    AdsrDados adsr;
    juce::AudioBuffer<float> synthBuffer;
    
    OscDados osc;
    //juce::dsp::Oscillator<float> osc{ [](float x) {return x / juce::MathConstants<float>::pi; } };
    juce::dsp::Gain<float> gain;
    bool estaPronto{ false };

    // return std::sin(x);                             Sine
    // return x / juce::MathConstants<float>::pi;      Saw
    // return x < 0.0f ? -1.0f : 1.0f;                 Square
    // return x * 4.0f - 4.0f;                         Triangle

};
