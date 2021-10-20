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
    filtro(audioProcessor.apvts)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (800, 600);

    addAndMakeVisible(osc1);
    addAndMakeVisible(adsr);
    addAndMakeVisible(filtro);
    
}

TCCSynthAudioProcessorEditor::~TCCSynthAudioProcessorEditor()
{
}

//==============================================================================
void TCCSynthAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(juce::Colours::darkslateblue);

    //g.setColour (juce::Colours::white);
    //g.setFont (15.0f);
    //g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void TCCSynthAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    const auto padding = 10;

    osc1.setBounds(getWidth() * 1 / 5, 10, 100, 30);
    adsr.setBounds(getWidth() * 3/4 - padding*8, getHeight() * 1/3, getWidth() / 3, getHeight() * 3 / 5);
    filtro.setBounds(getWidth() * 2 / 7, getHeight() * 1 / 3, getWidth() * 2 / 6, getHeight() * 3 / 5);

}

