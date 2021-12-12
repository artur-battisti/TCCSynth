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
#include "Dados/GainDados.h"

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
    void setCurrentPlaybackSampleRate(const double newRate) override;

    OscDados& getOscillator() { return osc; }
    GainDados& getGain() { return gain; }
    double currentSampleRate;
private:

    AdsrDados adsr;
    juce::AudioBuffer<float> synthBuffer;
    
    OscDados osc;
    GainDados gain;
    bool isOk{ false };
};
