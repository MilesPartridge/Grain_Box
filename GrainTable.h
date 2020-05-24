/*
  ==============================================================================

    GrainTable.h
    Created: 21 Apr 2020 2:28:04pm
    Author:  Miles Partridge

  ==============================================================================
*/

#pragma once

#include <vector>
#include <iostream>
#include <math.h>

class Phasor
{
    float m_sampleRate, m_frequency, m_phase, m_delta;
    
public:
    
    Phasor(float sampleRate = 44100.0, float frequency = 1, float phase = 0 ):
    m_sampleRate(sampleRate),
    m_frequency(frequency),
    m_phase(phase),
    m_delta(frequency / sampleRate)
    {
    }
    
    
    void setSampleRate(float sampleRate)
    {
        m_sampleRate = sampleRate;
        m_delta = m_frequency / m_sampleRate;
    }
    
    
    float getFrequency()
    {
        return m_frequency;
    }
    
    
    void setFrequency(float freq)
    {
        m_frequency = freq;
        m_delta = m_frequency / m_sampleRate;
    }
    
    
    float getPhase()
    {
        return m_phase;
    }
    
    
    void setPhase(float phase)
    {
        m_phase = phase;
    }
    
    
    void tick()
    {
        m_phase += m_delta;
        
        while(m_phase > 1)m_phase -= 1;
        while(m_phase < 0)m_phase += 1;
    }
    
};



class GrainTable
{
    long long int m_size;
    std::vector<float> m_data;
    long long int m_writePos;
    
public:
    
    GrainTable(long long int size = 512):
    m_size(size),
    m_data(size),
    m_writePos(0)
    {
        std::cout << "Created a Grain Table Size: " << m_data.size()<<std::endl;
    }
    
    //THIS IS NOT THREAD SAFE .. look into double buffering
    void setSize(long long int size)
    {
        m_size = size;
        m_data = std::vector<float>(m_size);
    }
    
    
    void fillRamp()
    {
        
        for(int n = 0 ; n < m_size;++n)
        {
            m_data[n] = float(n)/float(m_size);
        }
    }
    
    
    void fillHann()
    {
        for(int n = 0 ; n < m_size ;++n)
        {
            m_data[n] = 0.5 * (1.0-cos((2*3.14159 * n)/m_size    )   );
        }
    }
    
    
    double CubicInterpolate(
                            double y0,double y1,
                            double y2,double y3,
                            double mu)
    {
        double a0,a1,a2,a3,mu2;
        
        mu2 = mu * mu;
        a0 = y3 - y2 - y0 + y1;
        a1 = y0 - y1 - a0;
        a2 = y2 - y0;
        a3 = y1;
        
        return(a0 * mu * mu2 + a1 * mu2 + a2 * mu + a3);
    }
    
    
    float operator [](const float& pos)
    {
        float intIndex, remain;
        remain = modf(pos, &intIndex);
        long long int size = m_size - 1;
        
        float y1(intIndex - 1), y2(intIndex), y3(intIndex + 1), y4(intIndex + 2);
        
        while(y1 > size) y1 -= size;
        while(y1 < 0) y1 += size;
        
        while(y2 > size) y2 -= size;
        while(y2 < 0) y2 += size;
        
        while(y3 > size) y3 -= size;
        while(y3 < 0) y3 += size;
        
        while(y4 > size) y4 -= size;
        while(y4 < 0) y4 += size;
        
        return CubicInterpolate(m_data[y1], m_data[y2], m_data[y3], m_data[y4], remain);
    }
    
    void setSample(long long int pos,float value)
    {
        if(pos > 0 && pos < m_size)
        {
            m_data[pos] = value;
        }
    }
    
    
    void writeSample(float value)
    {
        m_data[m_writePos] += value;
        ++m_writePos;
        while (m_writePos> m_size) m_writePos -= m_size;
        while (m_writePos<  0) m_writePos += m_size;
    }
    
    
    long long int getSize()
    {
        return m_size -1;
    }
    
};
