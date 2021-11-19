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

	fmOsc.prepare(spec);
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
	lastMidiNote = midiNoteNumber;
}

void OscDados::setWaveType(const int choice)

	// return std::sin(x);                             Sine
	// return x / juce::MathConstants<float>::pi;      Saw
	// return x < 0.0f ? -1.0f : 1.0f;                 Square
{
	switch (choice)
	{
	case 0:
		//sine

		initialise([](float x) {return std::sin(x); });
		break;

	case 1:
		//square
		initialise([](float x){return x < 0.0f ? -1.0f : 1.0f; });
		break;

	case 2:
		//saw
		initialise([](float x) {return x / juce::MathConstants<float>::pi; });
		
		break;

	case 3:
		//triangle ??
		initialise([](float x) {return x < 0.0f ? x++ : x--; });
		break;

	default:
		jassertfalse;
		break;
	}
}

/*void OscDados::setFmParams(const float depth, const float frequency)
{
	fmOsc.setFrequency(frequency);
	fmDepth = depth;
	auto freqAtual = juce::MidiMessage::getMidiNoteInHertz(lastMidiNote) + fmMod;
	setFrequency(freqAtual >= 0.0f ? freqAtual : freqAtual * -1.0f);
}
*/