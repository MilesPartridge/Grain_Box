/*
  ==============================================================================

    GrainSpawner.cpp
    Created: 21 Apr 2020 2:30:50pm
    Author:  Miles Partridge

  ==============================================================================
*/

#include "GrainSpawner.h"


GrainSpawner::GrainSpawner():
m_sampleRate(44100),
m_playing(false),
m_samplesToNextSpawn(0),
m_spawnPos(0),
m_grainDuration(44100),
m_spawnRate(44100),
m_grainSpeed(1),
m_playBackSpeed(0)
{
    m_window.fillHann();
    m_audio.setSize(44100);
    int numGrains = 64;
    
    for(int n = 0 ; n < numGrains; ++n)
    {
        m_grains.push_back(Grain());
    }
}



void GrainSpawner::setAudioSize(long long int size)
{
    m_audio.setSize(size);
}


void GrainSpawner::setSample(long long int pos, float sample)
{
    m_audio.setSample(pos, sample);
}


void GrainSpawner::prepare(float sampleRate)
{
    m_sampleRate = sampleRate;
    m_playBackPhasor.setSampleRate(sampleRate);
    
    //recalculate speed
    m_playBackPhasor.setFrequency( (m_playBackSpeed* m_sampleRate) / float( m_audio.getSize())  );
    
}


void GrainSpawner::setPlayState(bool state)
{
    m_playing = state;
}


void GrainSpawner::process(float* left, float* right, int numSamples)
{
    // return;
    if(m_playing == true)
    {
        
        for(int n = 0 ; n < numSamples; ++n)
        {
            m_audio.writeSample(left[n]);
            
            
            if(m_samplesToNextSpawn <= 0 )
            {
                //spawn a grain
                bool needsToSpawn = true;
                for(auto& grain : m_grains)
                {
                    if(grain.isActive() == false && needsToSpawn == true  )
                    {
                        float playPos = (m_playBackPhasor.getPhase() * m_audio.getSize());
                        while (playPos < 0) playPos += m_audio.getSize();
                        while (playPos > m_audio.getSize()) playPos -= m_audio.getSize();
                        
                        grain.spawn(m_spawnPos + playPos, m_grainDuration, m_grainSpeed);
                        needsToSpawn = false;
                        m_samplesToNextSpawn = m_spawnRate;
                        break;
                    }
                }
            }
            
            for(auto& grain : m_grains)
            {
                grain.process(n, left, right, m_audio, m_window);
            }
            --m_samplesToNextSpawn;
            m_playBackPhasor.tick();
        }
    }
}


void GrainSpawner::setSpawnPos(float val)
{
    while(val < 0)val += 1;
    while(val > 1)val -= 1;
    
    m_spawnPos = val * m_audio.getSize();
}


void GrainSpawner::setGrainDur(float durInSeconds)
{
    m_grainDuration = durInSeconds * m_sampleRate * m_grainSizeLoweringAmount;
}


void GrainSpawner::setSpawnRate(float rateInSeconds)
{
    m_spawnRate = rateInSeconds * m_sampleRate * 0.5;
}


void GrainSpawner::setGrainSpeed(int n)
{
    float var = m_sampleRate / m_grainDuration;
    var /= pow(2, (n / 12));   // find note in equal temperament 'n' steps away from current note
    m_grainSpeed = var;
}


void GrainSpawner::setPlaySpeed(float speed)
{
    m_playBackSpeed = speed;
    
    m_playBackPhasor.setFrequency( (m_playBackSpeed * m_sampleRate) / float( m_audio.getSize())  );

}
