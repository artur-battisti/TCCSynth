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
    gainAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, "GAIN", gainSlider);
    gainSlider.setTextValueSuffix(" dB");
    setRotarySliderParams(gainSlider);
    setLabel(gainLabel);
}

GainComponent::~GainComponent()
{
}

void GainComponent::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colour::fromRGB(123, 104, 238));
}

void GainComponent::resized()
{
    const auto bounds = getLocalBounds().reduced(10);
    const auto padding = 10;
    const auto sliderWidth = bounds.getWidth() * 8/10;
    const auto sliderHeight = bounds.getWidth() * 8/10;

    gainSlider.setBounds(bounds.getWidth()/2 - bounds.getWidth()/3, padding*2, sliderWidth, sliderHeight);
    gainLabel.setBounds(gainSlider.getX()+padding*2, gainSlider.getBottom()+padding, getWidth()/2, 20);
}
