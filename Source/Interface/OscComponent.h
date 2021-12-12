/*
  ==============================================================================

    OscComponent.h
    Created: 3 Sep 2021 10:45:04pm
    Author:  Artur

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "AuxiliarComponent.h"

//==============================================================================

class OscComponent  : public AuxiliarComponent
{
public:

    OscComponent(juce::AudioProcessorValueTreeState& apvts, juce::String waveSelectId);
    ~OscComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    juce::ComboBox oscWaveSelect;
    juce::Label waveSelectLabel{"WaveSelect","Wave Select"};
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> oscWaveSelectAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscComponent)
};
