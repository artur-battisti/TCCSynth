/*
  ==============================================================================

    FiltroComponent.h
    Created: 18 Sep 2021 1:26:19pm
    Author:  Artur

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "AuxiliarComponent.h"

//==============================================================================
/*
*/
class FiltroComponent  : public AuxiliarComponent
{
public:
    FiltroComponent(juce::AudioProcessorValueTreeState& apvts);
    ~FiltroComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:

    // HIGH-PASS
    juce::Label highPassLabel{ "HighPass", "High Pass" };

    juce::Slider freqHPSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> freqHPAttachment;
    juce::Label freqHPLabel{ "FreqHP", "Frequency" };

    juce::Slider resHPSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> resHPAttachment;
    juce::Label resHPLabel{ "ResHP", "Resonance" };

    /*------------------------------------------------------------------------------------*/

    // LOW-PASS
    juce::Label lowPassLabel{ "LowPass", "Low Pass" };

    juce::Slider freqLPSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> freqLPAttachment;
    juce::Label freqLPLabel{ "FreqLP", "Frequency" };

    juce::Slider resLPSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> resLPAttachment;
    juce::Label resLPLabel{ "ResLP", "Resonance" };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FiltroComponent)
};
