/*
  ==============================================================================

    AdsrComponent.cpp
    Created: 31 Aug 2021 3:07:29pm
    Author:  Artur

  ==============================================================================
*/

#include <JuceHeader.h>
#include "AdsrComponent.h"

//==============================================================================
AdsrComponent::AdsrComponent(juce::AudioProcessorValueTreeState& apvts)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

    attackAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, "ATTACK", attackSlider);
    decayAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, "DECAY", decaySlider);
    sustainAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, "SUSTAIN", sustainSlider);
    releaseAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, "RELEASE", releaseSlider);

    setVerticalSliderParams(attackSlider);
    setVerticalSliderParams(decaySlider);
    setVerticalSliderParams(sustainSlider);
    setVerticalSliderParams(releaseSlider);

    setLabel(attackLabel);
    setLabel(decayLabel);
    setLabel(sustainLabel);
    setLabel(releaseLabel);
    
}

AdsrComponent::~AdsrComponent()
{
}


void AdsrComponent::paint (juce::Graphics& g)
{

    g.fillAll(juce::Colour::fromRGB(123, 104, 238));
    //g.drawRect(getLocalBounds());
}


void AdsrComponent::resized()
{

    const auto bounds = getLocalBounds().reduced(10);
    const auto padding = 10;
    const auto sliderWidth = bounds.getWidth() / 4- padding;
    const auto sliderHeight = bounds.getHeight();
    const auto sliderStartX = padding;
    const auto sliderStartY = 0;

    attackSlider.setBounds(sliderStartX, sliderStartY, sliderWidth, sliderHeight);
    decaySlider.setBounds(attackSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    sustainSlider.setBounds(decaySlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    releaseSlider.setBounds(sustainSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);

    attackLabel.setBounds(attackSlider.getX(), attackSlider.getY() + attackSlider.getHeight(), attackSlider.getWidth(), padding * 2);
    decayLabel.setBounds(decaySlider.getX(), decaySlider.getY() + decaySlider.getHeight(), decaySlider.getWidth(), padding * 2);
    sustainLabel.setBounds(sustainSlider.getX(), sustainSlider.getY() + sustainSlider.getHeight(), sustainSlider.getWidth(), padding * 2);
    releaseLabel.setBounds(releaseSlider.getX(), releaseSlider.getY() + releaseSlider.getHeight(), releaseSlider.getWidth(), padding * 2);
}