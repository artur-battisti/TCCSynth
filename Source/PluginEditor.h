/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Interface/AdsrComponent.h"
#include "Interface/OscComponent.h"
#include "Interface/FiltroComponent.h"
#include "Interface/GainComponent.h"

//==============================================================================

class TCCSynthAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    TCCSynthAudioProcessorEditor (TCCSynthAudioProcessor&);
    ~TCCSynthAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:

    TCCSynthAudioProcessor& audioProcessor;
    OscComponent osc1;
    AdsrComponent adsr;
    FiltroComponent filtro;
    GainComponent gain;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TCCSynthAudioProcessorEditor)
};
