/*
  ==============================================================================

    AdsrDados.cpp
    Created: 31 Aug 2021 3:09:20pm
    Author:  Artur

  ==============================================================================
*/

#include "AdsrDados.h"

void AdsrDados::alterarADSR(const float attack, const float decay, const float sustain, const float release)
{
    adsrParams.attack = attack;
    adsrParams.decay = decay;
    adsrParams.sustain = sustain;
    adsrParams.release = release;

    setParameters(adsrParams);
};