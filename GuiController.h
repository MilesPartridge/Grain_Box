/*
  ==============================================================================

    GuiController.h
    Created: 22 Apr 2020 11:19:45am
    Author:  Miles Partridge

  ==============================================================================
*/

#pragma once

class GrainBoxAudioProcessorEditor;
class GrainBoxAudioProcessor;

#include "GUI.h"
#include "Genetics.h"

class GuiController
{
public:
    GuiController(GrainBoxAudioProcessorEditor* PluginEditor, GrainBoxAudioProcessor* PluginProcessor);
    
    ~GuiController();
    
    friend class GrainBoxAudioProcessorEditor;
private:
    GrainBoxAudioProcessorEditor* m_PluginEditor;
    GrainBoxAudioProcessor* m_PluginProcessor;
    GUI m_gui;
    
    Genetics m_GrainBoxGenerator;
    
    float m_mutateValue = 0.0f;
};
