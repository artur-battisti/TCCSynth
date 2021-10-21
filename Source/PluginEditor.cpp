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
    
}

TCCSynthAudioProcessorEditor::~TCCSynthAudioProcessorEditor()
{
}

//==============================================================================
void TCCSynthAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::darkslateblue);
}

void TCCSynthAudioProcessorEditor::resized()
{

    const auto padding = 18;

    osc1.setBounds(padding, getHeight() * 1/3, getWidth() / 4, getHeight() * 6/10);
    gain.setBounds(osc1.getX(), osc1.getBottom() - 200, getWidth() / 4, getHeight() * 4/10);
    filtro.setBounds(osc1.getRight()+padding, getHeight() * 1 / 3, getWidth() /3, getHeight() * 6/10);
    adsr.setBounds(filtro.getRight()+padding, getHeight() * 1 / 3, getWidth() /3, getHeight() * 6/10);

}

