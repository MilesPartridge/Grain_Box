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
    
    //fft stuff
    static constexpr auto fftOrder = 10;
    static constexpr auto fftSize  = 1 << fftOrder;
    void pushNextSampleIntoFifo (float sample) noexcept;
    
private:
    GrainBoxAudioProcessorEditor* m_PluginEditor;
    GrainBoxAudioProcessor* m_PluginProcessor;
    GUI m_gui;
    
    Genetics m_GrainBoxGenerator;
    
    float m_mutateValue = 0.0f;
    
    //fft variables
    dsp::FFT forwardFFT; 
    std::array<float, fftSize> fifo;
    std::array<float, fftSize * 2> fftData;
    int fifoIndex = 0;
    bool nextFFTBlockReady = false;
};
