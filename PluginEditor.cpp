/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GrainBoxAudioProcessorEditor::GrainBoxAudioProcessorEditor (GrainBoxAudioProcessor& p)
    :
AudioProcessorEditor (&p),
processor (p),
m_controller(this, &p)                          // setup the gui controller with relevant pointers
{
    addAndMakeVisible(m_controller.m_gui);      // remember GuiController.h holds the GUI itself
    
    
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (600, 400);
}

GrainBoxAudioProcessorEditor::~GrainBoxAudioProcessorEditor()
{
}

//==============================================================================
void GrainBoxAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void GrainBoxAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
