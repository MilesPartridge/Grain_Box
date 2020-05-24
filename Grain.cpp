/*
  ==============================================================================

    Grain.cpp
    Created: 21 Apr 2020 2:28:54pm
    Author:  Miles Partridge

  ==============================================================================
*/

#include "Grain.h"


Grain::Grain():
    m_active(false),
    m_startPos(0),
    m_duration(0),
    m_currentPosition(0),
    m_amp(0),
    m_grainSpeed(0),
    m_windowIndex(0)
{
    
}



void Grain::spawn(float startpos, float duration, float grainSpeed)
{
    m_startPos = startpos;
    m_currentPosition = startpos;
    m_duration = duration ;
    m_grainSpeed = grainSpeed;
    m_amp = 0.7;
    m_windowIndex = 0;
    m_active = true;
}


void Grain::process(int index,
                    float* leftChannel,
                    float* rightChannel,
                    GrainTable& m_audio,
                    GrainTable& m_window )
{
    
    if(m_active == true && leftChannel != nullptr && rightChannel != nullptr )
    {
        float windowSize = m_window.getSize();
        //check the windowing here...
        float a = m_audio[m_startPos + m_currentPosition];
        float w = m_window[ (m_windowIndex / m_duration) * windowSize];
        float s =  a  *  w;
        
        leftChannel[index] += s;
        rightChannel[index] += s;
        
        
        ++m_windowIndex;
        m_currentPosition += m_grainSpeed;
        
        if(m_windowIndex >= m_duration)
        {
            m_active = false;
        }
    }
}


bool Grain::isActive()
{
    return m_active;
}
   
