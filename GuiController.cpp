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

#include <algorithm>


GuiController::GuiController(GrainBoxAudioProcessorEditor* PluginEditor, GrainBoxAudioProcessor* PluginProcessor):
m_PluginEditor(PluginEditor),
m_PluginProcessor(PluginProcessor),
forwardFFT (fftOrder)
{
    //                                  set initial granular synth parameters       ******
    // all set to Mutation 1 on the GUI
    m_PluginProcessor->m_grainSpawner.setSpawnRate(m_GrainBoxGenerator.getGenome(0)->getGenes()[0] * 2 + 0.01);
    m_PluginProcessor->m_grainSpawner.setGrainDur(m_GrainBoxGenerator.getGenome(0)->getGenes()[1] * 2 + 0.01);
    m_PluginProcessor->m_grainSpawner.setSpawnPos(m_GrainBoxGenerator.getGenome(0)->getGenes()[2]);
    m_PluginProcessor->m_grainSpawner.setGrainSpeed(m_GrainBoxGenerator.getGenome(0)->getGenes()[3] * 10 - 5);
    m_PluginProcessor->m_grainSpawner.setPlaySpeed(m_GrainBoxGenerator.getGenome(0)->getGenes()[4] * 10 - 5);
    
    // set all dials to relevant positions
    m_gui.dial1->setValue(m_GrainBoxGenerator.getGenome(0)->getGenes()[0]);
    m_gui.dial2->setValue(m_GrainBoxGenerator.getGenome(0)->getGenes()[1]);
    m_gui.dial3->setValue(m_GrainBoxGenerator.getGenome(0)->getGenes()[2]);
    m_gui.dial4->setValue(m_GrainBoxGenerator.getGenome(0)->getGenes()[3]);
    m_gui.dial5->setValue(m_GrainBoxGenerator.getGenome(0)->getGenes()[4]);
    
    // set sound on and toggle to show it
    m_gui.playButton->setToggleState(true, dontSendNotification);
    m_PluginProcessor->nowPlaying = m_gui.playButton->getToggleState();
    
    // set label
    m_gui.MutationLabel->setText(TRANS("Mutation 1 Selected"), dontSendNotification);
    
    
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
                /*
                //
                m_PluginProcessor->m_sampleVector.resize(data.getNumSamples(), 0.0f);
                
                for(int i = 0; i < data.getNumSamples(); ++i)
                {
                    m_PluginProcessor->m_sampleVector[i] = data.getSample(0, i);
                }
                m_PluginProcessor->nowPlaying = true;
                //
                */
                
                // FFT stuff                 ******
                for (auto i = 0; i < data.getNumSamples(); ++i)
                {
                    pushNextSampleIntoFifo(data.getSample(0, i));
                }
                forwardFFT.performFrequencyOnlyForwardTransform(fftData.data());
                // now find the bin with the highest value in, which should be the fundamental
                auto result = std::max_element(fftData.begin(), fftData.end());
                std::cout << "max element at: " << std::distance(fftData.begin(), result) << '\n';
                std::cout << "FFT size: " << std::distance(fftData.begin(), fftData.end()) << '\n';
                float binWidth = m_PluginProcessor->m_sampleRate / fftSize;
                std::cout << "Bin width: " << binWidth << '\n';
                float binFrequency = std::distance(fftData.begin(), result) * binWidth;
                std::cout << "Bin Frequency: " << binFrequency << '\n';
                
                // Granular synth stuff      ******
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
        
        if (m_gui.GenomeGrader2->getSelectedId() == 6)
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
        
        if (m_gui.GenomeGrader3->getSelectedId() == 6)
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
        
        if (m_gui.GenomeGrader4->getSelectedId() == 6)
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
        
        if (m_gui.GenomeGrader5->getSelectedId() == 6)
        {
            //set lock if graded 5/5
            m_GrainBoxGenerator.getGenome(4)->lock = true;
        }else{
            m_GrainBoxGenerator.getGenome(4)->lock = false;
        }
    };
    
    
//    /*
    //                              Mutation Chance Slider                ******
    m_gui.MutationChanceSlider->onValueChange = [this]
    {
//        m_mutateValue = m_gui.MutationChanceSlider->getValue();
    };
//    */
    //                                  mutate button                    *******
    m_gui.MutateButton->onClick = [this]()
    {
        m_mutateValue = m_gui.MutationChanceSlider->getValue();
        m_GrainBoxGenerator.mutateGeneration(m_mutateValue);
        
        // set granular synth parameters to first mutant
        m_PluginProcessor->m_grainSpawner.setSpawnRate(m_GrainBoxGenerator.getGenome(0)->getGenes()[0] * 2 + 0.01);
        m_PluginProcessor->m_grainSpawner.setGrainDur(m_GrainBoxGenerator.getGenome(0)->getGenes()[1] * 2 + 0.01);
        m_PluginProcessor->m_grainSpawner.setSpawnPos(m_GrainBoxGenerator.getGenome(0)->getGenes()[2]);
        m_PluginProcessor->m_grainSpawner.setGrainSpeed(m_GrainBoxGenerator.getGenome(0)->getGenes()[3] * 10 - 5);
        m_PluginProcessor->m_grainSpawner.setPlaySpeed(m_GrainBoxGenerator.getGenome(0)->getGenes()[4] * 10 - 5);
        
        // set all dials to relevant positions
        m_gui.dial1->setValue(m_GrainBoxGenerator.getGenome(0)->getGenes()[0]);
        m_gui.dial2->setValue(m_GrainBoxGenerator.getGenome(0)->getGenes()[1]);
        m_gui.dial3->setValue(m_GrainBoxGenerator.getGenome(0)->getGenes()[2]);
        m_gui.dial4->setValue(m_GrainBoxGenerator.getGenome(0)->getGenes()[3]);
        m_gui.dial5->setValue(m_GrainBoxGenerator.getGenome(0)->getGenes()[4]);
        
        // set label
        m_gui.MutationLabel->setText(TRANS("Mutation 1 Selected"), dontSendNotification);
    };
    
    
    
    //                              mutation selection buttons             ******
    m_gui.Mutation1->onClick = [this]()
    {
        // set granular synth parameters
        m_PluginProcessor->m_grainSpawner.setSpawnRate(m_GrainBoxGenerator.getGenome(0)->getGenes()[0] * 2 + 0.01);
        m_PluginProcessor->m_grainSpawner.setGrainDur(m_GrainBoxGenerator.getGenome(0)->getGenes()[1] * 2 + 0.01);
        m_PluginProcessor->m_grainSpawner.setSpawnPos(m_GrainBoxGenerator.getGenome(0)->getGenes()[2]);
        m_PluginProcessor->m_grainSpawner.setGrainSpeed(m_GrainBoxGenerator.getGenome(0)->getGenes()[3] * 10 - 5);
        m_PluginProcessor->m_grainSpawner.setPlaySpeed(m_GrainBoxGenerator.getGenome(0)->getGenes()[4] * 10 - 5);
        
        // set all dials to relevant positions
        m_gui.dial1->setValue(m_GrainBoxGenerator.getGenome(0)->getGenes()[0]);
        m_gui.dial2->setValue(m_GrainBoxGenerator.getGenome(0)->getGenes()[1]);
        m_gui.dial3->setValue(m_GrainBoxGenerator.getGenome(0)->getGenes()[2]);
        m_gui.dial4->setValue(m_GrainBoxGenerator.getGenome(0)->getGenes()[3]);
        m_gui.dial5->setValue(m_GrainBoxGenerator.getGenome(0)->getGenes()[4]);
        
        // set label
        m_gui.MutationLabel->setText(TRANS("Mutation 1 Selected"), dontSendNotification);
    };
    
    m_gui.Mutation2->onClick = [this]()
    {
        // set granular synth parameters
        m_PluginProcessor->m_grainSpawner.setSpawnRate(m_GrainBoxGenerator.getGenome(1)->getGenes()[0] * 2 + 0.01);
        m_PluginProcessor->m_grainSpawner.setGrainDur(m_GrainBoxGenerator.getGenome(1)->getGenes()[1] * 2 + 0.01);
        m_PluginProcessor->m_grainSpawner.setSpawnPos(m_GrainBoxGenerator.getGenome(1)->getGenes()[2]);
        m_PluginProcessor->m_grainSpawner.setGrainSpeed(m_GrainBoxGenerator.getGenome(1)->getGenes()[3] * 10 - 5);
        m_PluginProcessor->m_grainSpawner.setPlaySpeed(m_GrainBoxGenerator.getGenome(1)->getGenes()[4] * 10 - 5);
        
        // set all dials to relevant positions
        m_gui.dial1->setValue(m_GrainBoxGenerator.getGenome(1)->getGenes()[0]);
        m_gui.dial2->setValue(m_GrainBoxGenerator.getGenome(1)->getGenes()[1]);
        m_gui.dial3->setValue(m_GrainBoxGenerator.getGenome(1)->getGenes()[2]);
        m_gui.dial4->setValue(m_GrainBoxGenerator.getGenome(1)->getGenes()[3]);
        m_gui.dial5->setValue(m_GrainBoxGenerator.getGenome(1)->getGenes()[4]);
        
        // set label
        m_gui.MutationLabel->setText(TRANS("Mutation 2 Selected"), dontSendNotification);
    };
    
    m_gui.Mutation3->onClick = [this]()
    {
        // set granular synth parameters
        m_PluginProcessor->m_grainSpawner.setSpawnRate(m_GrainBoxGenerator.getGenome(2)->getGenes()[0] * 2 + 0.01);
        m_PluginProcessor->m_grainSpawner.setGrainDur(m_GrainBoxGenerator.getGenome(2)->getGenes()[1] * 2 + 0.01);
        m_PluginProcessor->m_grainSpawner.setSpawnPos(m_GrainBoxGenerator.getGenome(2)->getGenes()[2]);
        m_PluginProcessor->m_grainSpawner.setGrainSpeed(m_GrainBoxGenerator.getGenome(2)->getGenes()[3] * 10 - 5);
        m_PluginProcessor->m_grainSpawner.setPlaySpeed(m_GrainBoxGenerator.getGenome(2)->getGenes()[4] * 10 - 5);
        
        // set all dials to relevant positions
        m_gui.dial1->setValue(m_GrainBoxGenerator.getGenome(2)->getGenes()[0]);
        m_gui.dial2->setValue(m_GrainBoxGenerator.getGenome(2)->getGenes()[1]);
        m_gui.dial3->setValue(m_GrainBoxGenerator.getGenome(2)->getGenes()[2]);
        m_gui.dial4->setValue(m_GrainBoxGenerator.getGenome(2)->getGenes()[3]);
        m_gui.dial5->setValue(m_GrainBoxGenerator.getGenome(2)->getGenes()[4]);
        
        // set label
        m_gui.MutationLabel->setText(TRANS("Mutation 3 Selected"), dontSendNotification);
    };
    
    m_gui.Mutation4->onClick = [this]()
    {
        // set granular synth parameters
        m_PluginProcessor->m_grainSpawner.setSpawnRate(m_GrainBoxGenerator.getGenome(3)->getGenes()[0] * 2 + 0.01);
        m_PluginProcessor->m_grainSpawner.setGrainDur(m_GrainBoxGenerator.getGenome(3)->getGenes()[1] * 2 + 0.01);
        m_PluginProcessor->m_grainSpawner.setSpawnPos(m_GrainBoxGenerator.getGenome(3)->getGenes()[2]);
        m_PluginProcessor->m_grainSpawner.setGrainSpeed(m_GrainBoxGenerator.getGenome(3)->getGenes()[3] * 10 - 5);
        m_PluginProcessor->m_grainSpawner.setPlaySpeed(m_GrainBoxGenerator.getGenome(3)->getGenes()[4] * 10 - 5);
        
        // set all dials to relevant positions
        m_gui.dial1->setValue(m_GrainBoxGenerator.getGenome(3)->getGenes()[0]);
        m_gui.dial2->setValue(m_GrainBoxGenerator.getGenome(3)->getGenes()[1]);
        m_gui.dial3->setValue(m_GrainBoxGenerator.getGenome(3)->getGenes()[2]);
        m_gui.dial4->setValue(m_GrainBoxGenerator.getGenome(3)->getGenes()[3]);
        m_gui.dial5->setValue(m_GrainBoxGenerator.getGenome(3)->getGenes()[4]);
        
        // set label
        m_gui.MutationLabel->setText(TRANS("Mutation 4 Selected"), dontSendNotification);
    };
    
    m_gui.Mutation5->onClick = [this]()
    {
        // set granular synth parameters
        m_PluginProcessor->m_grainSpawner.setSpawnRate(m_GrainBoxGenerator.getGenome(4)->getGenes()[0] * 2 + 0.01);
        m_PluginProcessor->m_grainSpawner.setGrainDur(m_GrainBoxGenerator.getGenome(4)->getGenes()[1] * 2 + 0.01);
        m_PluginProcessor->m_grainSpawner.setSpawnPos(m_GrainBoxGenerator.getGenome(4)->getGenes()[2]);
        m_PluginProcessor->m_grainSpawner.setGrainSpeed(m_GrainBoxGenerator.getGenome(4)->getGenes()[3] * 10 - 5);
        m_PluginProcessor->m_grainSpawner.setPlaySpeed(m_GrainBoxGenerator.getGenome(4)->getGenes()[4] * 10 - 5);
        
        // set all dials to relevant positions
        m_gui.dial1->setValue(m_GrainBoxGenerator.getGenome(4)->getGenes()[0]);
        m_gui.dial2->setValue(m_GrainBoxGenerator.getGenome(4)->getGenes()[1]);
        m_gui.dial3->setValue(m_GrainBoxGenerator.getGenome(4)->getGenes()[2]);
        m_gui.dial4->setValue(m_GrainBoxGenerator.getGenome(4)->getGenes()[3]);
        m_gui.dial5->setValue(m_GrainBoxGenerator.getGenome(4)->getGenes()[4]);
        
        // set label
        m_gui.MutationLabel->setText(TRANS("Mutation 5 Selected"), dontSendNotification);
    };
    
    m_gui.playButton->onClick = [this]()
    {
        m_PluginProcessor->nowPlaying = m_gui.playButton->getToggleState();
    };
    
}




GuiController::~GuiController()
{
}


void GuiController::pushNextSampleIntoFifo (float sample) noexcept
{
    if (fifoIndex == fftSize)    // [8]
    {
        if (! nextFFTBlockReady) // [9]
        {
            std::fill (fftData.begin(), fftData.end(), 0.0f);
            std::copy (fifo.begin(), fifo.end(), fftData.begin());
            nextFFTBlockReady = true;
        }
 
        fifoIndex = 0;
    }
 
    fifo[fifoIndex++] = sample;  // [9]
}
