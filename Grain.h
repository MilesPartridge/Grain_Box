/*
  ==============================================================================

    Grain.h
    Created: 21 Apr 2020 2:28:54pm
    Author:  Miles Partridge

  ==============================================================================
*/

#pragma once


//==============================================================================
/*
*/
#include "GrainTable.h"


class Grain{
    bool m_active;
    float m_startPos, m_duration, m_currentPosition, m_amp, m_grainSpeed, m_windowIndex;
    
public:
    
    Grain();
    
    void process(int index, float* leftChannel, float* rightChannel, GrainTable& m_audio, GrainTable& m_window);
    void spawn(float startpos, float duration, float grainSpeed = 1);
    bool isActive();
};

