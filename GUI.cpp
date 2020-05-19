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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "GUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
GUI::GUI ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    comboBox.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBox.get());
    comboBox->setEditableText (false);
    comboBox->setJustificationType (Justification::centredLeft);
    comboBox->setTextWhenNothingSelected (String());
    comboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox->addItem (TRANS("1,2,3,4,5"), 1);
    comboBox->addListener (this);

    comboBox->setBounds (384, 456, 150, 24);

    comboBox2.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBox2.get());
    comboBox2->setEditableText (false);
    comboBox2->setJustificationType (Justification::centredLeft);
    comboBox2->setTextWhenNothingSelected (String());
    comboBox2->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox2->addItem (TRANS("1,2,3,4,5"), 1);
    comboBox2->addListener (this);

    comboBox2->setBounds (384, 488, 150, 24);

    comboBox3.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBox3.get());
    comboBox3->setEditableText (false);
    comboBox3->setJustificationType (Justification::centredLeft);
    comboBox3->setTextWhenNothingSelected (String());
    comboBox3->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox3->addItem (TRANS("1,2,3,4,5"), 1);
    comboBox3->addListener (this);

    comboBox3->setBounds (384, 520, 150, 24);

    comboBox4.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBox4.get());
    comboBox4->setEditableText (false);
    comboBox4->setJustificationType (Justification::centredLeft);
    comboBox4->setTextWhenNothingSelected (String());
    comboBox4->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox4->addItem (TRANS("1,2,3,4,5"), 1);
    comboBox4->addListener (this);

    comboBox4->setBounds (384, 552, 150, 24);

    comboBox5.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBox5.get());
    comboBox5->setEditableText (false);
    comboBox5->setJustificationType (Justification::centredLeft);
    comboBox5->setTextWhenNothingSelected (String());
    comboBox5->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox5->addItem (TRANS("1,2,3,4,5"), 1);
    comboBox5->addListener (this);

    comboBox5->setBounds (384, 584, 150, 24);

    loadSoundButton.reset (new TextButton ("new button"));
    addAndMakeVisible (loadSoundButton.get());
    loadSoundButton->setButtonText (TRANS("Load Sound"));
    loadSoundButton->addListener (this);
    loadSoundButton->setColour (TextButton::buttonColourId, Colour (0xff7e851c));

    loadSoundButton->setBounds (224, 32, 150, 24);

    GenomeGrader1.reset (new ComboBox ("Grade_Genome"));
    addAndMakeVisible (GenomeGrader1.get());
    GenomeGrader1->setEditableText (false);
    GenomeGrader1->setJustificationType (Justification::centredLeft);
    GenomeGrader1->setTextWhenNothingSelected (TRANS("3"));
    GenomeGrader1->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    GenomeGrader1->addItem (TRANS("0"), 1);
    GenomeGrader1->addItem (TRANS("1"), 2);
    GenomeGrader1->addItem (TRANS("2"), 3);
    GenomeGrader1->addItem (TRANS("3"), 4);
    GenomeGrader1->addItem (TRANS("4"), 5);
    GenomeGrader1->addItem (TRANS("5"), 6);
    GenomeGrader1->addListener (this);

    GenomeGrader1->setBounds (40, 120, 80, 24);

    GenomeGrader2.reset (new ComboBox ("Grade_Genome"));
    addAndMakeVisible (GenomeGrader2.get());
    GenomeGrader2->setEditableText (false);
    GenomeGrader2->setJustificationType (Justification::centredLeft);
    GenomeGrader2->setTextWhenNothingSelected (TRANS("3"));
    GenomeGrader2->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    GenomeGrader2->addItem (TRANS("0"), 1);
    GenomeGrader2->addItem (TRANS("1"), 2);
    GenomeGrader2->addItem (TRANS("2"), 3);
    GenomeGrader2->addItem (TRANS("3"), 4);
    GenomeGrader2->addItem (TRANS("4"), 5);
    GenomeGrader2->addItem (TRANS("5"), 6);
    GenomeGrader2->addListener (this);

    GenomeGrader2->setBounds (152, 120, 80, 24);

    GenomeGrader3.reset (new ComboBox ("Grade_Genome"));
    addAndMakeVisible (GenomeGrader3.get());
    GenomeGrader3->setEditableText (false);
    GenomeGrader3->setJustificationType (Justification::centredLeft);
    GenomeGrader3->setTextWhenNothingSelected (TRANS("3"));
    GenomeGrader3->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    GenomeGrader3->addItem (TRANS("0"), 1);
    GenomeGrader3->addItem (TRANS("1"), 2);
    GenomeGrader3->addItem (TRANS("2"), 3);
    GenomeGrader3->addItem (TRANS("3"), 4);
    GenomeGrader3->addItem (TRANS("4"), 5);
    GenomeGrader3->addItem (TRANS("5"), 6);
    GenomeGrader3->addListener (this);

    GenomeGrader3->setBounds (264, 120, 80, 24);

    GenomeGrader4.reset (new ComboBox ("Grade_Genome"));
    addAndMakeVisible (GenomeGrader4.get());
    GenomeGrader4->setEditableText (false);
    GenomeGrader4->setJustificationType (Justification::centredLeft);
    GenomeGrader4->setTextWhenNothingSelected (TRANS("3"));
    GenomeGrader4->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    GenomeGrader4->addItem (TRANS("0"), 1);
    GenomeGrader4->addItem (TRANS("1"), 2);
    GenomeGrader4->addItem (TRANS("2"), 3);
    GenomeGrader4->addItem (TRANS("3"), 4);
    GenomeGrader4->addItem (TRANS("4"), 5);
    GenomeGrader4->addItem (TRANS("5"), 6);
    GenomeGrader4->addListener (this);

    GenomeGrader4->setBounds (376, 120, 80, 24);

    GenomeGrader5.reset (new ComboBox ("Grade_Genome"));
    addAndMakeVisible (GenomeGrader5.get());
    GenomeGrader5->setEditableText (false);
    GenomeGrader5->setJustificationType (Justification::centredLeft);
    GenomeGrader5->setTextWhenNothingSelected (TRANS("3"));
    GenomeGrader5->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    GenomeGrader5->addItem (TRANS("0"), 1);
    GenomeGrader5->addItem (TRANS("1"), 2);
    GenomeGrader5->addItem (TRANS("2"), 3);
    GenomeGrader5->addItem (TRANS("3"), 4);
    GenomeGrader5->addItem (TRANS("4"), 5);
    GenomeGrader5->addItem (TRANS("5"), 6);
    GenomeGrader5->addListener (this);

    GenomeGrader5->setBounds (488, 120, 80, 24);

    MutateButton.reset (new TextButton ("Mutate"));
    addAndMakeVisible (MutateButton.get());
    MutateButton->setButtonText (TRANS("MUTATE!"));
    MutateButton->addListener (this);
    MutateButton->setColour (TextButton::buttonColourId, Colour (0xff61a45c));

    MutateButton->setBounds (224, 216, 150, 24);

    playButton.reset (new ToggleButton ("play"));
    addAndMakeVisible (playButton.get());
    playButton->setButtonText (TRANS("Play"));
    playButton->addListener (this);

    playButton->setBounds (408, 32, 64, 24);

    Mutation1.reset (new TextButton ("Mutation_1"));
    addAndMakeVisible (Mutation1.get());
    Mutation1->setButtonText (TRANS("Mutation 1"));
    Mutation1->addListener (this);

    Mutation1->setBounds (32, 80, 96, 24);

    Mutation2.reset (new TextButton ("Mutation_2"));
    addAndMakeVisible (Mutation2.get());
    Mutation2->setButtonText (TRANS("Mutation 2"));
    Mutation2->addListener (this);

    Mutation2->setBounds (144, 80, 96, 24);

    Mutation3.reset (new TextButton ("Mutation_3"));
    addAndMakeVisible (Mutation3.get());
    Mutation3->setButtonText (TRANS("Mutation 3"));
    Mutation3->addListener (this);

    Mutation3->setBounds (256, 80, 96, 24);

    Mutation4.reset (new TextButton ("Mutation_4"));
    addAndMakeVisible (Mutation4.get());
    Mutation4->setButtonText (TRANS("Mutation 4"));
    Mutation4->addListener (this);

    Mutation4->setBounds (368, 80, 96, 24);

    Mutation5.reset (new TextButton ("Mutation_5"));
    addAndMakeVisible (Mutation5.get());
    Mutation5->setButtonText (TRANS("Mutation 5"));
    Mutation5->addListener (this);

    Mutation5->setBounds (480, 80, 96, 24);

    MutationChanceSlider.reset (new Slider ("mutationChanceSlider1"));
    addAndMakeVisible (MutationChanceSlider.get());
    MutationChanceSlider->setRange (0, 10, 0);
    MutationChanceSlider->setSliderStyle (Slider::LinearHorizontal);
    MutationChanceSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    MutationChanceSlider->addListener (this);

    MutationChanceSlider->setBounds (168, 192, 256, 24);

    dial1.reset (new Slider ("StartPos"));
    addAndMakeVisible (dial1.get());
    dial1->setRange (0, 1, 0);
    dial1->setSliderStyle (Slider::Rotary);
    dial1->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    dial1->addListener (this);

    dial1->setBounds (68, 278, 80, 72);

    dial2.reset (new Slider ("GrainDur"));
    addAndMakeVisible (dial2.get());
    dial2->setRange (0, 1, 0);
    dial2->setSliderStyle (Slider::Rotary);
    dial2->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    dial2->addListener (this);

    dial2->setBounds (164, 278, 80, 72);

    dial3.reset (new Slider ("GrainSpeed"));
    addAndMakeVisible (dial3.get());
    dial3->setRange (0, 1, 0);
    dial3->setSliderStyle (Slider::Rotary);
    dial3->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    dial3->addListener (this);

    dial3->setBounds (260, 278, 80, 72);

    dial4.reset (new Slider ("SpawnRate"));
    addAndMakeVisible (dial4.get());
    dial4->setRange (0, 1, 0);
    dial4->setSliderStyle (Slider::Rotary);
    dial4->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    dial4->addListener (this);

    dial4->setBounds (364, 278, 80, 72);

    dial5.reset (new Slider ("PlaySpeed"));
    addAndMakeVisible (dial5.get());
    dial5->setRange (0, 1, 0);
    dial5->setSliderStyle (Slider::Rotary);
    dial5->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    dial5->addListener (this);

    dial5->setBounds (468, 278, 80, 72);

    MutationLabel.reset (new Label ("MutationLabel",
                                    TRANS("Mutation 1 Selected")));
    addAndMakeVisible (MutationLabel.get());
    MutationLabel->setFont (Font ("Rockwell", 15.00f, Font::plain).withTypefaceStyle ("Regular"));
    MutationLabel->setJustificationType (Justification::centredLeft);
    MutationLabel->setEditable (false, false, false);
    MutationLabel->setColour (TextEditor::textColourId, Colours::black);
    MutationLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    MutationLabel->setBounds (225, 257, 150, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..

    comboBox->setTooltip ("Grade Mutation 1!");
    comboBox2->setTooltip ("Grade Mutation 2!");
    comboBox3->setTooltip ("Grade Mutation 3!");
    comboBox4->setTooltip ("Grade Mutation 4!");
    comboBox5->setTooltip ("Grade Mutation 5!");
    loadSoundButton->setTooltip ("Load a sound with this!");
    GenomeGrader1->setTooltip ("Grade Mutation 1!");
    GenomeGrader2->setTooltip ("Grade Mutation 2!");
    GenomeGrader3 ->setTooltip ("Grade Mutation 3!");
    GenomeGrader4->setTooltip ("Grade Mutation 4!");
    GenomeGrader5->setTooltip ("Grade Mutation 5!");
    MutateButton->setTooltip ("Grade the mutations first, then press this to make a new generation of sounds");
    playButton->setTooltip ("This is a playButton with a label");
    Mutation1->setTooltip ("Hear this mutation!");
    Mutation2->setTooltip ("Hear this mutation!");
    Mutation3->setTooltip ("Hear this mutation!");
    Mutation4->setTooltip ("Hear this mutation!");
    Mutation5->setTooltip ("Hear this mutation!");
    MutationChanceSlider->setTooltip ("Set the percentage chance of a synth parameter mutating");
    dial1->setTooltip ("Setting for start position");
    dial2->setTooltip ("Setting for grain duration");
    dial3->setTooltip ("Setting for grain speed");
    dial4->setTooltip ("Setting for spawn rate");
    dial5->setTooltip ("Setting for play speed");
    dial1->setEnabled (false);
    dial2->setEnabled (false);
    dial3->setEnabled (false);
    dial4->setEnabled (false);
    dial5->setEnabled (false);

    //[/Constructor]
}

GUI::~GUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    comboBox = nullptr;
    comboBox2 = nullptr;
    comboBox3 = nullptr;
    comboBox4 = nullptr;
    comboBox5 = nullptr;
    loadSoundButton = nullptr;
    GenomeGrader1 = nullptr;
    GenomeGrader2 = nullptr;
    GenomeGrader3 = nullptr;
    GenomeGrader4 = nullptr;
    GenomeGrader5 = nullptr;
    MutateButton = nullptr;
    playButton = nullptr;
    Mutation1 = nullptr;
    Mutation2 = nullptr;
    Mutation3 = nullptr;
    Mutation4 = nullptr;
    Mutation5 = nullptr;
    MutationChanceSlider = nullptr;
    dial1 = nullptr;
    dial2 = nullptr;
    dial3 = nullptr;
    dial4 = nullptr;
    dial5 = nullptr;
    MutationLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void GUI::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff1c83b6));

    {
        int x = 180, y = 452, width = 200, height = 30;
        String text (TRANS("Grade Start Position"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 180, y = 484, width = 200, height = 30;
        String text (TRANS("Grade Grain Duration"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 180, y = 516, width = 200, height = 30;
        String text (TRANS("Grade Grain Speed"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 180, y = 548, width = 200, height = 30;
        String text (TRANS("Grade Spawn Rate"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 180, y = 580, width = 200, height = 30;
        String text (TRANS("Grade Play Speed"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 172, y = 412, width = 436, height = 34;
        String text (TRANS("These will be for individual parameters NOT YET IMPLEMENTED"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 196, y = 164, width = 200, height = 30;
        String text (TRANS("Mutation Chance"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Rockwell", 15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 164, y = 172, width = 276, height = 30;
        String text (TRANS("Low                                                  High"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Rockwell", 15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void GUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void GUI::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBox.get())
    {
        //[UserComboBoxCode_comboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox]
    }
    else if (comboBoxThatHasChanged == comboBox2.get())
    {
        //[UserComboBoxCode_comboBox2] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox2]
    }
    else if (comboBoxThatHasChanged == comboBox3.get())
    {
        //[UserComboBoxCode_comboBox3] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox3]
    }
    else if (comboBoxThatHasChanged == comboBox4.get())
    {
        //[UserComboBoxCode_comboBox4] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox4]
    }
    else if (comboBoxThatHasChanged == comboBox5.get())
    {
        //[UserComboBoxCode_comboBox5] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox5]
    }
    else if (comboBoxThatHasChanged == GenomeGrader1.get())
    {
        //[UserComboBoxCode_GenomeGrader1] -- add your combo box handling code here..
        //[/UserComboBoxCode_GenomeGrader1]
    }
    else if (comboBoxThatHasChanged == GenomeGrader2.get())
    {
        //[UserComboBoxCode_GenomeGrader2] -- add your combo box handling code here..
        //[/UserComboBoxCode_GenomeGrader2]
    }
    else if (comboBoxThatHasChanged == GenomeGrader3.get())
    {
        //[UserComboBoxCode_GenomeGrader3] -- add your combo box handling code here..
        //[/UserComboBoxCode_GenomeGrader3]
    }
    else if (comboBoxThatHasChanged == GenomeGrader4.get())
    {
        //[UserComboBoxCode_GenomeGrader4] -- add your combo box handling code here..
        //[/UserComboBoxCode_GenomeGrader4]
    }
    else if (comboBoxThatHasChanged == GenomeGrader5.get())
    {
        //[UserComboBoxCode_GenomeGrader5] -- add your combo box handling code here..
        //[/UserComboBoxCode_GenomeGrader5]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void GUI::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == loadSoundButton.get())
    {
        //[UserButtonCode_loadSoundButton] -- add your button handler code here..
        //[/UserButtonCode_loadSoundButton]
    }
    else if (buttonThatWasClicked == MutateButton.get())
    {
        //[UserButtonCode_MutateButton] -- add your button handler code here..
        //[/UserButtonCode_MutateButton]
    }
    else if (buttonThatWasClicked == playButton.get())
    {
        //[UserButtonCode_playButton] -- add your button handler code here..
        //[/UserButtonCode_playButton]
    }
    else if (buttonThatWasClicked == Mutation1.get())
    {
        //[UserButtonCode_Mutation1] -- add your button handler code here..
        //[/UserButtonCode_Mutation1]
    }
    else if (buttonThatWasClicked == Mutation2.get())
    {
        //[UserButtonCode_Mutation2] -- add your button handler code here..
        //[/UserButtonCode_Mutation2]
    }
    else if (buttonThatWasClicked == Mutation3.get())
    {
        //[UserButtonCode_Mutation3] -- add your button handler code here..
        //[/UserButtonCode_Mutation3]
    }
    else if (buttonThatWasClicked == Mutation4.get())
    {
        //[UserButtonCode_Mutation4] -- add your button handler code here..
        //[/UserButtonCode_Mutation4]
    }
    else if (buttonThatWasClicked == Mutation5.get())
    {
        //[UserButtonCode_Mutation5] -- add your button handler code here..
        //[/UserButtonCode_Mutation5]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void GUI::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == MutationChanceSlider.get())
    {
        //[UserSliderCode_MutationChanceSlider] -- add your slider handling code here..
        //[/UserSliderCode_MutationChanceSlider]
    }
    else if (sliderThatWasMoved == dial1.get())
    {
        //[UserSliderCode_dial1] -- add your slider handling code here..
        //[/UserSliderCode_dial1]
    }
    else if (sliderThatWasMoved == dial2.get())
    {
        //[UserSliderCode_dial2] -- add your slider handling code here..
        //[/UserSliderCode_dial2]
    }
    else if (sliderThatWasMoved == dial3.get())
    {
        //[UserSliderCode_dial3] -- add your slider handling code here..
        //[/UserSliderCode_dial3]
    }
    else if (sliderThatWasMoved == dial4.get())
    {
        //[UserSliderCode_dial4] -- add your slider handling code here..
        //[/UserSliderCode_dial4]
    }
    else if (sliderThatWasMoved == dial5.get())
    {
        //[UserSliderCode_dial5] -- add your slider handling code here..
        //[/UserSliderCode_dial5]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="GUI" componentName="" parentClasses="public Component"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="600"
                 initialHeight="400">
  <BACKGROUND backgroundColour="ff1c83b6">
    <TEXT pos="180 452 200 30" fill="solid: ff000000" hasStroke="0" text="Grade Start Position"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="180 484 200 30" fill="solid: ff000000" hasStroke="0" text="Grade Grain Duration"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="180 516 200 30" fill="solid: ff000000" hasStroke="0" text="Grade Grain Speed"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="180 548 200 30" fill="solid: ff000000" hasStroke="0" text="Grade Spawn Rate"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="180 580 200 30" fill="solid: ff000000" hasStroke="0" text="Grade Play Speed"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="172 412 436 34" fill="solid: ff000000" hasStroke="0" text="These will be for individual parameters NOT YET IMPLEMENTED"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="1"
          italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="196 164 200 30" fill="solid: ff000000" hasStroke="0" text="Mutation Chance"
          fontname="Rockwell" fontsize="15.0" kerning="0.0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="164 172 276 30" fill="solid: ff000000" hasStroke="0" text="Low                                                  High"
          fontname="Rockwell" fontsize="15.0" kerning="0.0" bold="0" italic="0"
          justification="36"/>
  </BACKGROUND>
  <COMBOBOX name="new combo box" id="deb4221cd2a7852c" memberName="comboBox"
            virtualName="" explicitFocusOrder="0" pos="384 456 150 24" editable="0"
            layout="33" items="1,2,3,4,5" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="df82696449890c36" memberName="comboBox2"
            virtualName="" explicitFocusOrder="0" pos="384 488 150 24" editable="0"
            layout="33" items="1,2,3,4,5" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="ae662b1d00b38c4e" memberName="comboBox3"
            virtualName="" explicitFocusOrder="0" pos="384 520 150 24" editable="0"
            layout="33" items="1,2,3,4,5" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="aff02fff3fd1f954" memberName="comboBox4"
            virtualName="" explicitFocusOrder="0" pos="384 552 150 24" editable="0"
            layout="33" items="1,2,3,4,5" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="b9bbf3274145fb58" memberName="comboBox5"
            virtualName="" explicitFocusOrder="0" pos="384 584 150 24" editable="0"
            layout="33" items="1,2,3,4,5" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <TEXTBUTTON name="new button" id="8ec4b411001de765" memberName="loadSoundButton"
              virtualName="" explicitFocusOrder="0" pos="224 32 150 24" bgColOff="ff7e851c"
              buttonText="Load Sound" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <COMBOBOX name="Grade_Genome" id="fd5b70478af37bbd" memberName="GenomeGrader1"
            virtualName="" explicitFocusOrder="0" pos="40 120 80 24" editable="0"
            layout="33" items="0&#10;1&#10;2&#10;3&#10;4&#10;5" textWhenNonSelected="3"
            textWhenNoItems="(no choices)"/>
  <COMBOBOX name="Grade_Genome" id="fa5ead35ffe9bc13" memberName="GenomeGrader2"
            virtualName="" explicitFocusOrder="0" pos="152 120 80 24" editable="0"
            layout="33" items="0&#10;1&#10;2&#10;3&#10;4&#10;5" textWhenNonSelected="3"
            textWhenNoItems="(no choices)"/>
  <COMBOBOX name="Grade_Genome" id="d7298bf74c619dc6" memberName="GenomeGrader3"
            virtualName="" explicitFocusOrder="0" pos="264 120 80 24" editable="0"
            layout="33" items="0&#10;1&#10;2&#10;3&#10;4&#10;5" textWhenNonSelected="3"
            textWhenNoItems="(no choices)"/>
  <COMBOBOX name="Grade_Genome" id="cb00d031a52dbf9d" memberName="GenomeGrader4"
            virtualName="" explicitFocusOrder="0" pos="376 120 80 24" editable="0"
            layout="33" items="0&#10;1&#10;2&#10;3&#10;4&#10;5" textWhenNonSelected="3"
            textWhenNoItems="(no choices)"/>
  <COMBOBOX name="Grade_Genome" id="ce53b51e0b0cc9b2" memberName="GenomeGrader5"
            virtualName="" explicitFocusOrder="0" pos="488 120 80 24" editable="0"
            layout="33" items="0&#10;1&#10;2&#10;3&#10;4&#10;5" textWhenNonSelected="3"
            textWhenNoItems="(no choices)"/>
  <TEXTBUTTON name="Mutate" id="f7fc477cb6ed2c9f" memberName="MutateButton"
              virtualName="" explicitFocusOrder="0" pos="224 216 150 24" bgColOff="ff61a45c"
              buttonText="MUTATE!" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="play" id="7a682951062ac653" memberName="playButton" virtualName=""
                explicitFocusOrder="0" pos="408 32 64 24" buttonText="Play" connectedEdges="0"
                needsCallback="1" radioGroupId="0" state="0"/>
  <TEXTBUTTON name="Mutation_1" id="23eec05fc589175a" memberName="Mutation1"
              virtualName="" explicitFocusOrder="0" pos="32 80 96 24" buttonText="Mutation 1"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Mutation_2" id="203693ef957fc809" memberName="Mutation2"
              virtualName="" explicitFocusOrder="0" pos="144 80 96 24" buttonText="Mutation 2"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Mutation_3" id="e17496ae4e5c62c4" memberName="Mutation3"
              virtualName="" explicitFocusOrder="0" pos="256 80 96 24" buttonText="Mutation 3"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Mutation_4" id="a6b43b76598f3740" memberName="Mutation4"
              virtualName="" explicitFocusOrder="0" pos="368 80 96 24" buttonText="Mutation 4"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Mutation_5" id="302f57a8ddbf4604" memberName="Mutation5"
              virtualName="" explicitFocusOrder="0" pos="480 80 96 24" buttonText="Mutation 5"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="mutationChanceSlider1" id="9794dbb2bdfc3761" memberName="MutationChanceSlider"
          virtualName="" explicitFocusOrder="0" pos="168 192 256 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="StartPos" id="39a0c0a7901dcb55" memberName="dial1" virtualName=""
          explicitFocusOrder="0" pos="68 278 80 72" min="0.0" max="1.0"
          int="0.0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="GrainDur" id="7454eb5f570f53d4" memberName="dial2" virtualName=""
          explicitFocusOrder="0" pos="164 278 80 72" min="0.0" max="1.0"
          int="0.0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="GrainSpeed" id="83548687e5528668" memberName="dial3" virtualName=""
          explicitFocusOrder="0" pos="260 278 80 72" min="0.0" max="1.0"
          int="0.0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="SpawnRate" id="31dca97c738d525a" memberName="dial4" virtualName=""
          explicitFocusOrder="0" pos="364 278 80 72" min="0.0" max="1.0"
          int="0.0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="PlaySpeed" id="1b5ec779fe6482cd" memberName="dial5" virtualName=""
          explicitFocusOrder="0" pos="468 278 80 72" min="0.0" max="1.0"
          int="0.0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="MutationLabel" id="ee537481f07baf61" memberName="MutationLabel"
         virtualName="" explicitFocusOrder="0" pos="225 257 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Mutation 1 Selected" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Rockwell"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

