/*
  ==============================================================================

    FiltroComponent.cpp
    Created: 18 Sep 2021 1:26:19pm
    Author:  Artur

  ==============================================================================
*/

#include <JuceHeader.h>
#include "FiltroComponent.h"

//==============================================================================
FiltroComponent::FiltroComponent(juce::AudioProcessorValueTreeState& apvts)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

    // HIGH-PASS
    freqHPAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, "FILTERHIGHPASSFREQ", freqHPSlider);
    setRotarySliderParams(freqHPSlider);
    setLabel(freqHPLabel);
    setLabel(highPassLabel);

    resHPAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, "FILTERRESHP", resHPSlider);
    setRotarySliderParams(resHPSlider);
    setLabel(resHPLabel);
    

    /*----------------------------------------------------------------------------------------------------------------------------*/

    // LOW-PASS
    setLabel(lowPassLabel);
    freqLPAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, "FILTERLOWPASSFREQ", freqLPSlider);
    setRotarySliderParams(freqLPSlider);
    setLabel(freqLPLabel);

    resLPAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, "FILTERRESLP", resLPSlider);
    setRotarySliderParams(resLPSlider);
    setLabel(resLPLabel);

}

FiltroComponent::~FiltroComponent()
{
}

void FiltroComponent::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll(juce::Colour::fromRGB(80,60,120));
    //g.drawRect(getLocalBounds(),5);
}

void FiltroComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

    const auto bounds = getLocalBounds().reduced(10);
    const auto padding = 10;
    const auto padding2 = padding * 2;
    const auto sliderWidth = bounds.getWidth() / 2;
    const auto sliderHeight = bounds.getHeight() / 3;
    const auto sliderStartX = 0;
    const auto sliderStartY = 0;

    // HIGH-PASS

    highPassLabel.setBounds(sliderStartX, padding, sliderWidth, padding2);
    freqHPSlider.setBounds(sliderStartX, highPassLabel.getBottom() + padding2, sliderWidth, sliderHeight);
    freqHPLabel.setBounds(freqHPSlider.getX(), freqHPSlider.getY() + freqHPSlider.getHeight(), freqHPSlider.getWidth(), padding2);

    resHPSlider.setBounds(sliderStartX, freqHPLabel.getBottom() + padding, sliderWidth, sliderHeight);
    resHPLabel.setBounds(resHPSlider.getX(), resHPSlider.getY() + resHPSlider.getHeight(), resHPSlider.getWidth(), padding2);

    /*----------------------------------------------------------------------------------------------------------------------------*/

    // LOW-PASS
    lowPassLabel.setBounds(highPassLabel.getRight() + padding2, padding, sliderWidth, padding2);

    freqLPSlider.setBounds(freqHPSlider.getRight()+padding2, lowPassLabel.getBottom() + padding2, sliderWidth, sliderHeight);
    freqLPLabel.setBounds(freqLPSlider.getX(), freqLPSlider.getY() + freqLPSlider.getHeight(), freqLPSlider.getWidth(), padding2);

    resLPSlider.setBounds(resHPSlider.getRight()+padding2, freqHPLabel.getBottom() + padding, sliderWidth, sliderHeight);
    resLPLabel.setBounds(resLPSlider.getX(), resLPSlider.getY() + resLPSlider.getHeight(), resLPSlider.getWidth(), padding2);
}
