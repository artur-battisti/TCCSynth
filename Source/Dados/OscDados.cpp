/*
  ==============================================================================

    OscDados.cpp
    Created: 3 Sep 2021 9:58:20pm
    Author:  Artur

  ==============================================================================
*/

#include "OscDados.h"

void OscDados::prepareToPlay(juce::dsp::ProcessSpec& spec)
{
	prepare(spec);
}

void OscDados::getNextAudioBlock(juce::dsp::AudioBlock<float>& block)
{
	
	for (int channel = 0; channel < block.getNumChannels(); channel++)
	{
		
		for (int sample = 0; sample < block.getNumSamples(); sample++)
		{
		}
	}

	process(juce::dsp::ProcessContextReplacing<float>(block));

}

void OscDados::setWaveFreq(const int midiNoteNumber)
{
	setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber));
}

void OscDados::setWaveType(const int choice)
{
	switch (choice)
	{
	case 0:
		//sine
		initialise([](float x) {return std::sin(x); });
		break;

	case 1:
		//saw
		initialise([](float x) {return x / juce::MathConstants<float>::pi; });
		break;

	case 2:
		//square
		initialise([](float x) {return x < 0.0f ? -1.0f : 1.0f; });
		break;

	case 3:
		//triangle
		initialise([](float x) {return std::asin(std::cos(x)) / (juce::MathConstants<float>::pi/2); });
		break;

	default:
		jassertfalse;
		break;
	}
}