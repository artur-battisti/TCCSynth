/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TCCSynthAudioProcessorEditor::TCCSynthAudioProcessorEditor(TCCSynthAudioProcessor& p)
    : AudioProcessorEditor(&p),
    audioProcessor(p),
    osc1 (audioProcessor.apvts, "OSC1WAVETYPE"),
    adsr(audioProcessor.apvts),
    filtro(audioProcessor.apvts),
    gain(audioProcessor.apvts)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (800, 600);

    addAndMakeVisible(osc1);
    addAndMakeVisible(adsr);
    addAndMakeVisible(filtro);
    addAndMakeVisible(gain);
    setPluginNameStyle(pluginName);
    
}

TCCSynthAudioProcessorEditor::~TCCSynthAudioProcessorEditor()
{
}

//==============================================================================
void TCCSynthAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colour::fromRGB(106, 90, 205));
}

void TCCSynthAudioProcessorEditor::resized()
{
    const auto bounds = getLocalBounds().reduced(10);
    const auto padding = 18;
    const auto centerX = bounds.getWidth() / 2 - bounds.getWidth() / 4;

    osc1.setBounds(padding, getHeight() * 1/3, getWidth() / 4, getHeight() * 20/100);
    gain.setBounds(padding, osc1.getBottom() + padding, getWidth() / 4, getHeight() * 40/100);
    adsr.setBounds(osc1.getRight()+padding, getHeight() * 1 / 3, getWidth() /3, getHeight() * 6/10 + padding);
    filtro.setBounds(adsr.getRight() + padding, getHeight() * 1 / 3, getWidth() / 3 - padding / 2, getHeight() * 6 / 10 + padding);
    pluginName.setBounds(padding, padding, bounds.getWidth() - padding, 150);
}

void TCCSynthAudioProcessorEditor::setPluginNameStyle(juce::Label& pluginName)
{
    pluginName.setColour(juce::Label::ColourIds::textColourId, juce::Colour::fromRGB(240, 220, 255));
    pluginName.setColour(juce::Label::ColourIds::backgroundColourId, juce::Colour::fromRGB(123, 104, 238));
    pluginName.setJustificationType(juce::Justification::centred);
    pluginName.setFont(juce::Font(75.0f, juce::Font::bold));
    addAndMakeVisible(pluginName);
}