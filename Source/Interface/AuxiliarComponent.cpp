/*
  ==============================================================================

    AuxiliarComponent.cpp
    Created: 18 Sep 2021 1:37:09pm
    Author:  Artur

  ==============================================================================
*/

#include <JuceHeader.h>
#include "AuxiliarComponent.h"

//==============================================================================
AuxiliarComponent::AuxiliarComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

AuxiliarComponent::~AuxiliarComponent()
{
}

void AuxiliarComponent::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
    g.drawText ("AuxiliarComponent", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text
}

void AuxiliarComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

void AuxiliarComponent::setVerticalSliderParams(juce::Slider& slider)
{
    slider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 25);
    addAndMakeVisible(slider);
}

void AuxiliarComponent::setRotarySliderParams(juce::Slider& slider)
{
    slider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 25);
    addAndMakeVisible(slider);
}

void AuxiliarComponent::setLabel(juce::Label& label)
{
    label.setColour(juce::Label::ColourIds::textColourId, juce::Colours::white);
    label.setJustificationType(juce::Justification::centred);
    label.setFont(20.0f);
    addAndMakeVisible(label);
}