/*
  ==============================================================================

    SynthSound.h
    Created: 24 Aug 2021 9:56:39pm
    Author:  Artur

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound
{
public:

    bool appliesToNote(int midiNoteNumber) override{ return true; }
    bool appliesToChannel(int midiNoteChannel) override{ return true; }
};