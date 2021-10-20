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

    oscWaveSelectAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(apvts, waveSelectId, oscWaveSelect);

}

OscComponent::~OscComponent()
{
}

void OscComponent::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll(juce::Colours::darkslateblue);
}

void OscComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

    oscWaveSelect.setBounds(0, 0, 90, 20);

}
