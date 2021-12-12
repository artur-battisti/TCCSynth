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
}

AuxiliarComponent::~AuxiliarComponent()
{
}

void AuxiliarComponent::paint (juce::Graphics& g)
{
}

void AuxiliarComponent::resized()
{
}

void AuxiliarComponent::setVerticalSliderParams(juce::Slider& slider)
{
    slider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 25);
    slider.setColour(juce::Slider::ColourIds::backgroundColourId, juce::Colour::fromRGB(70, 55, 130));
    slider.setColour(juce::Slider::ColourIds::textBoxBackgroundColourId, juce::Colour::fromRGB(106, 90, 205));
    slider.setColour(juce::Slider::ColourIds::textBoxOutlineColourId, juce::Colour::fromRGB(50, 40, 100));
    slider.setColour(juce::Slider::ColourIds::thumbColourId, juce::Colour::fromRGB(72, 209, 204));
    addAndMakeVisible(slider);
}

void AuxiliarComponent::setRotarySliderParams(juce::Slider& slider)
{
    slider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 60, 25);
    slider.setColour(juce::Slider::ColourIds::rotarySliderOutlineColourId, juce::Colour::fromRGB(70, 55, 130));
    slider.setColour(juce::Slider::ColourIds::textBoxBackgroundColourId, juce::Colour::fromRGB(106, 90, 205));
    slider.setColour(juce::Slider::ColourIds::textBoxOutlineColourId, juce::Colour::fromRGB(50, 40, 100));
    slider.setColour(juce::Slider::ColourIds::thumbColourId, juce::Colour::fromRGB(72, 209, 204));
    addAndMakeVisible(slider);
}

void AuxiliarComponent::setComboBoxParams(juce::ComboBox& comboBox)
{
    comboBox.setJustificationType(juce::Justification::centred);
    comboBox.setColour(juce::ComboBox::ColourIds::backgroundColourId, juce::Colour::fromRGB(106, 90, 205));
    comboBox.setColour(juce::ComboBox::ColourIds::outlineColourId, juce::Colour::fromRGB(50, 40, 100));
    comboBox.setColour(juce::ComboBox::ColourIds::textColourId, juce::Colour::fromRGB(255,255,255));
    addAndMakeVisible(comboBox);
}

void AuxiliarComponent::setLabel(juce::Label& label)
{
    label.setColour(juce::Label::ColourIds::textColourId, juce::Colours::white);
    label.setJustificationType(juce::Justification::centred);
    label.setFont(20.0f);
    addAndMakeVisible(label);
}

void AuxiliarComponent::setMiniLabel(juce::Label& label)
{
    label.setColour(juce::Label::ColourIds::textColourId, juce::Colours::white);
    label.setJustificationType(juce::Justification::centred);
    label.setFont(16.0f);
    addAndMakeVisible(label);
}