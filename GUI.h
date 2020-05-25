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
             public Button::Listener,
             public ComboBox::Listener,
             public Slider::Listener
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
    void buttonClicked (Button* buttonThatWasClicked) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    TooltipWindow tooltipWindow;
    //[/UserVariables]

    //==============================================================================
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
    std::unique_ptr<Slider> MutationChanceSlider;
    std::unique_ptr<Slider> dial1;
    std::unique_ptr<Slider> dial2;
    std::unique_ptr<Slider> dial3;
    std::unique_ptr<Slider> dial4;
    std::unique_ptr<Slider> dial5;
    std::unique_ptr<Label> MutationLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GUI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

