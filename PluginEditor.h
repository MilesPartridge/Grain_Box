/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"


#include "GuiController.h"

//==============================================================================
/**
*/
class GrainBoxAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    GrainBoxAudioProcessorEditor (GrainBoxAudioProcessor&);
    ~GrainBoxAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    
    friend class GrainBoxAudioProcessor;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    GrainBoxAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GrainBoxAudioProcessorEditor)
    
    GuiController m_controller;
    
    
    friend class GuiController;
};
