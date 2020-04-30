/*
  ==============================================================================

    GuiController.cpp
    Created: 22 Apr 2020 11:19:45am
    Author:  Miles Partridge

  ==============================================================================
*/

#include "GuiController.h"

#include "PluginProcessor.h"
#include "PluginEditor.h"


GuiController::GuiController(GrainBoxAudioProcessorEditor* PluginEditor, GrainBoxAudioProcessor* PluginProcessor):
m_PluginEditor(PluginEditor),
m_PluginProcessor(PluginProcessor)
{
    //                                  set initial granular synth parameters       ******
    m_PluginProcessor->m_grainSpawner.setSpawnRate(m_GrainBoxGenerator.getGenome(0)[0][0] * 2 + 0.01);
    m_PluginProcessor->m_grainSpawner.setGrainDur(m_GrainBoxGenerator.getGenome(0)[0][1] * 2 + 0.01);
    m_PluginProcessor->m_grainSpawner.setSpawnPos(m_GrainBoxGenerator.getGenome(0)[0][2]);
    m_PluginProcessor->m_grainSpawner.setGrainSpeed(m_GrainBoxGenerator.getGenome(0)[0][3] * 10 - 5);
    m_PluginProcessor->m_grainSpawner.setPlaySpeed(m_GrainBoxGenerator.getGenome(0)[0][4] * 10 - 5);
    
    
    //                                  load file popup         ******
    m_PluginProcessor->m_formatManager.registerBasicFormats();
    
    m_gui.loadSoundButton->onClick = [this]()
    {
        
        FileChooser fc("Select Sound File", File(), "*.wav");
        if(fc.browseForFileToOpen())
        {
            File selected = fc.getResult();
            
            if(selected.existsAsFile())
            {
                std::shared_ptr<AudioFormatReader> reader(m_PluginProcessor->m_formatManager.createReaderFor(selected));
                
                AudioBuffer<float> data(reader->numChannels, reader->lengthInSamples);
                reader->read(&data, 0, reader->lengthInSamples, 0, true, false);
                
                m_PluginProcessor->m_grainSpawner.setAudioSize(data.getNumSamples());
                
                for(int n = 0; n < data.getNumSamples(); ++n)
                {
                    m_PluginProcessor->m_grainSpawner.setSample(   n,  data.getSample(0, n)   );
                }
                
                m_PluginProcessor->m_grainSpawner.prepare(m_PluginProcessor->m_sampleRate);
                m_PluginProcessor->m_grainSpawner.setPlayState(true);
            }
        }
    };
    //
    
    //                                    combo boxes               *******
    m_gui.GenomeGrader1->onChange = [this]
    {
        m_GrainBoxGenerator.getGenome(0)->weight = m_gui.GenomeGrader1->getSelectedId() - 1; // - 1 because my combo box starts at 0, but juce combobox starts at 1
        if (m_gui.GenomeGrader1->getSelectedId() == 6)
        {
            //set lock if graded 5/5
            m_GrainBoxGenerator.getGenome(0)->lock = true;
        }else{
            m_GrainBoxGenerator.getGenome(0)->lock = false;
        }
    };
    
    
    m_gui.GenomeGrader2->onChange = [this]
    {
        m_GrainBoxGenerator.getGenome(1)->weight = m_gui.GenomeGrader1->getSelectedId() - 1;
        
        if (m_gui.GenomeGrader1->getSelectedId() == 6)
        {
            //set lock if graded 5/5
            m_GrainBoxGenerator.getGenome(1)->lock = true;
        }else{
            m_GrainBoxGenerator.getGenome(1)->lock = false;
        }
    };
    
    
    m_gui.GenomeGrader3->onChange = [this]
    {
        m_GrainBoxGenerator.getGenome(2)->weight = m_gui.GenomeGrader1->getSelectedId() - 1;
        
        if (m_gui.GenomeGrader1->getSelectedId() == 6)
        {
            //set lock if graded 5/5
            m_GrainBoxGenerator.getGenome(2)->lock = true;
        }else{
            m_GrainBoxGenerator.getGenome(2)->lock = false;
        }
    };
    
    
    m_gui.GenomeGrader4->onChange = [this]
    {
        m_GrainBoxGenerator.getGenome(3)->weight = m_gui.GenomeGrader1->getSelectedId() - 1;
        
        if (m_gui.GenomeGrader1->getSelectedId() == 6)
        {
            //set lock if graded 5/5
            m_GrainBoxGenerator.getGenome(3)->lock = true;
        }else{
            m_GrainBoxGenerator.getGenome(3)->lock = false;
        }
    };
    
    
    m_gui.GenomeGrader5->onChange = [this]
    {
        m_GrainBoxGenerator.getGenome(4)->weight = m_gui.GenomeGrader1->getSelectedId() - 1;
        
        if (m_gui.GenomeGrader1->getSelectedId() == 6)
        {
            //set lock if graded 5/5
            m_GrainBoxGenerator.getGenome(4)->lock = true;
        }else{
            m_GrainBoxGenerator.getGenome(4)->lock = false;
        }
    };
    
    
    //                                  mutate button                    *******
    m_gui.MutateButton->onClick = [this]()
    {
        float mutateValue = 0.5;                // MAKE THIS HOOK UP TO EITHER SELECTOR OR SOME OTHER METHOD OF CALCULATION                                      //************************
                    
        m_GrainBoxGenerator.mutateGeneration(mutateValue);
        
        // set granular synth parameters 
        m_PluginProcessor->m_grainSpawner.setSpawnRate(m_GrainBoxGenerator.getGenome(0)[0][0] * 2 + 0.01);
        m_PluginProcessor->m_grainSpawner.setGrainDur(m_GrainBoxGenerator.getGenome(0)[0][1] * 2 + 0.01);
        m_PluginProcessor->m_grainSpawner.setSpawnPos(m_GrainBoxGenerator.getGenome(0)[0][2]);
        m_PluginProcessor->m_grainSpawner.setGrainSpeed(m_GrainBoxGenerator.getGenome(0)[0][3] * 10 - 5);
        m_PluginProcessor->m_grainSpawner.setPlaySpeed(m_GrainBoxGenerator.getGenome(0)[0][4] * 10 - 5);
    };
    
    
}




GuiController::~GuiController()
{
}
