/*
  ==============================================================================

    GainComponent.h
    Created: 21 Oct 2021 3:07:33pm
    Author:  Artur

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "AuxiliarComponent.h"

//==============================================================================
class GainComponent  : public AuxiliarComponent
{
public:

    GainComponent(juce::AudioProcessorValueTreeState& apvts);
    ~GainComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:

    juce::Slider gainSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> gainAttachment;
    juce::Label gainLabel{ "Gain", "Gain" };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GainComponent)
};
