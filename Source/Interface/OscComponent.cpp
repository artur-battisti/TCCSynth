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
OscComponent::OscComponent(juce::AudioProcessorValueTreeState& apvts, juce::String waveSelectId)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

    juce::StringArray choices{ "Sine", "Saw", "Square" };
    oscWaveSelect.addItemList(choices, 1);
    addAndMakeVisible(oscWaveSelect);
    setLabel(waveSelectLabel);

    oscWaveSelectAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(apvts, waveSelectId, oscWaveSelect);

}

OscComponent::~OscComponent()
{
}

void OscComponent::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colour::fromRGB(80, 60, 120));
}

void OscComponent::resized()
{

    const auto padding = 10;
    waveSelectLabel.setBounds(padding, padding, getWidth()/2, 20);
    oscWaveSelect.setBounds(waveSelectLabel.getRight() + padding, padding, getWidth()/3, 20);

}
