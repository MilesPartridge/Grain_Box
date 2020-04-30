/*
  ==============================================================================

    GrainSpawner.h
    Created: 21 Apr 2020 2:30:50pm
    Author:  Miles Partridge

  ==============================================================================
*/

#pragma once

#include "Grain.h"
#include <vector>

typedef std::vector<Grain> GrainVector;


class GrainSpawner{
    GrainVector m_grains;
    GrainTable m_audio,m_window;
    bool m_playing;
    float m_sampleRate;
    int m_samplesToNextSpawn;
    
    float m_spawnPos,m_grainDuration,m_spawnRate,m_grainSpeed,m_playBackSpeed;
    Phasor m_playBackPhasor;
public:
    GrainSpawner();
    void setAudioSize(long long int size);
    void setSample(long long int pos, float sample);
    
    void prepare(float sampleRate);
    void process(float* left,float* right,int numSamples);
    
    void setPlayState(bool state);
    
    void setSpawnPos(float val);
    void setGrainDur(float durInSeconds);
    void setSpawnRate(float rateInSeconds);
    void setGrainSpeed(float speed);
    void setPlaySpeed(float speed);
};


