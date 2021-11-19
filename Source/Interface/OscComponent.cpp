/*
  ==============================================================================

    OscComponent.cpp
    Created: 3 Sep 2021 10:45:04pm
    Author:  Artur

  ==============================================================================
*/

#include <JuceHeader.h>
#include "OscComponent.h"

//==============================================================================
OscComponent::OscComponent(juce::AudioProcessorValueTreeState& apvts, juce::String waveSelectId, juce::String voiceSelectId)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

    oscWaveSelectAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(apvts, waveSelectId, oscWaveSelect);
    juce::StringArray choicesOsc{ "Sine", "Saw", "Square" };
    oscWaveSelect.addItemList(choicesOsc,1);
    setComboBoxParams(oscWaveSelect);
    setLabel(waveSelectLabel);
    
}

OscComponent::~OscComponent()
{
}

void OscComponent::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colour::fromRGB(123, 104, 238));
}

void OscComponent::resized()
{

    const auto padding = 10;
    waveSelectLabel.setBounds(getWidth()/2 - getWidth()/4, padding, getWidth()/2, 20);
    oscWaveSelect.setBounds(waveSelectLabel.getBottom(), padding*6, getWidth()-padding*6, 30);
}
