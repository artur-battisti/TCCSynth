/*
  ==============================================================================

    GainComponent.cpp
    Created: 21 Oct 2021 3:07:33pm
    Author:  Artur

  ==============================================================================
*/

#include <JuceHeader.h>
#include "GainComponent.h"

//==============================================================================
GainComponent::GainComponent(juce::AudioProcessorValueTreeState& apvts)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    gainAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, "GAIN", gainSlider);
    setRotarySliderParams(gainSlider);
    setLabel(gainLabel);
}

GainComponent::~GainComponent()
{
}

void GainComponent::paint (juce::Graphics& g)
{

}

void GainComponent::resized()
{
    const auto bounds = getLocalBounds().reduced(10);
    const auto padding = 10;
    const auto sliderWidth = bounds.getWidth() * 3/5;
    const auto sliderHeight = bounds.getWidth() * 3/5;

    gainLabel.setBounds(bounds.getWidth()/2 - bounds.getWidth()/4, padding, getWidth()/2, 20);
    gainSlider.setBounds(gainLabel.getX(), gainLabel.getBottom(), sliderWidth, sliderHeight);
    
}
