/*
  ==============================================================================

    AuxiliarComponent.h
    Created: 18 Sep 2021 1:37:09pm
    Author:  Artur

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class AuxiliarComponent  : public juce::Component
{
public:
    AuxiliarComponent();
    ~AuxiliarComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:

protected:

    void setVerticalSliderParams(juce::Slider& slider);
    void setRotarySliderParams(juce::Slider& slider);
    void setComboBoxParams(juce::ComboBox& comboBox);
    void setLabel(juce::Label& label);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AuxiliarComponent)
};
