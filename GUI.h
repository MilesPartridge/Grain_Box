/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.7

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class GUI  : public Component,
             public ComboBox::Listener,
             public Button::Listener
{
public:
    //==============================================================================
    GUI ();
    ~GUI() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    friend class GrainBoxAudioProcessorEditor;
    friend class GuiController;
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<ComboBox> comboBox;
    std::unique_ptr<ComboBox> comboBox2;
    std::unique_ptr<ComboBox> comboBox3;
    std::unique_ptr<ComboBox> comboBox4;
    std::unique_ptr<ComboBox> comboBox5;
    std::unique_ptr<TextButton> loadSoundButton;
    std::unique_ptr<ComboBox> GenomeGrader1;
    std::unique_ptr<ComboBox> GenomeGrader2;
    std::unique_ptr<ComboBox> GenomeGrader3;
    std::unique_ptr<ComboBox> GenomeGrader4;
    std::unique_ptr<ComboBox> GenomeGrader5;
    std::unique_ptr<TextButton> MutateButton;
    std::unique_ptr<ToggleButton> playButton;
    std::unique_ptr<TextButton> Mutation1;
    std::unique_ptr<TextButton> Mutation2;
    std::unique_ptr<TextButton> Mutation3;
    std::unique_ptr<TextButton> Mutation4;
    std::unique_ptr<TextButton> Mutation5;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GUI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

