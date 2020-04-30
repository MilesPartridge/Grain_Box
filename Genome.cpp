/*
  ==============================================================================

    Genome.cpp
    Created: 29 Apr 2020 10:56:49am
    Author:  Miles Partridge

  ==============================================================================
*/

#include "Genome.h"

#include "iostream"

Genome::Genome(int size)
{
    for(int n = 0; n < size; ++n)
    {
        m_genes.push_back( rand() % 100 * 0.01 );            // THIS NEEDS TO BE VALUES THAT CAN BE PUT INTO GRANULAR PARAMETERS
        m_scores.push_back(GenomeScore::ThreeStar);     // here is the setting up scores, set default to 3 stars
    }
}



Genome::Genome(const Genome& other):
m_genes(other.m_genes),
m_scores(other.m_scores)        // remember all scores will need to be copied over now in every constructor
{
    
}


Genome::Genome(const Genome& a, const Genome& b, float crossOverPoint)
{
    
    
    long int smallest = a.m_genes.size();
    
    if(smallest > b.m_genes.size())
    {
        smallest = m_genes.size();
    }
    
    int crossP = crossOverPoint * smallest;
    
    for(int n = 0; n <  smallest; ++n ){
        if(n < crossP)
        {
            m_genes.push_back(a.m_genes[n]);
            m_scores.push_back(a.m_scores[n]);      // remember scores

        }else{
            m_genes.push_back(b.m_genes[n ]);
        }
    }
}


Genome::Genome(const Genome& other, float randomPercentage)
{
    if(lock)
    {
        int counter = 0;
        for(auto gene : other.m_genes)
        {
            m_genes.push_back(gene);
            m_scores.push_back(other.m_scores[counter]);  //remember scores
            counter++;
        }
        
    }else{
        
        int counter = 0;
        for(auto gene : other.m_genes){
            


            if( rand() % 100 < randomPercentage * 100 && other.m_scores[counter] != GenomeScore::Lock ){
                m_genes.push_back( rand() % 100 * 0.01 );       // THIS NEEDS TO BE VALUES THAT CAN BE PUT INTO GRANULAR PARAMETERS
                m_scores.push_back(GenomeScore::ThreeStar);        //remember scores
            }else{                                                  // else, put in previous value unchanged
                m_genes.push_back(gene);
                m_scores.push_back(other.m_scores[counter]);        //remember scores
            }
            counter++;
        }
    }
}


Genome::Genome(const Genome& other, float randomPoint, bool keepLeft, float randomPercentage)       //constructor overload, makes new genome that is chance mutated from another, but keeps part of the genome
{
    long int size = other.m_genes.size();
    int rPoint = randomPoint * size;
    
    for(int n = 0; n < size; ++n)
    {
        if( keepLeft )
        {
            if(n > rPoint && rand() % 100 < randomPercentage * 100 )
            {
                m_genes.push_back( rand() % 100 * 0.01 );       // THIS NEEDS TO BE VALUES THAT CAN BE PUT INTO GRANULAR PARAMETERS
            }else{
                m_genes.push_back(      other.m_genes[n] );
            }
            
        }else{
            
            if(n < rPoint && rand() % 100 < randomPercentage * 100 )
            {
                m_genes.push_back( rand() % 100 * 0.01 );       // THIS NEEDS TO BE VALUES THAT CAN BE PUT INTO GRANULAR PARAMETERS
            }else{
                m_genes.push_back(      other.m_genes[n] );
            }
            
        }
        
    }
    
}



std::string Genome::toString()
{
    std::stringstream ss;
    for(auto gene : m_genes)
    {
        ss << gene;
    }
    return ss.str();
}

Genes Genome::getGenes()
{
    return m_genes;
}



void Genome::setGeneScores(GenomeScore score, int index)
{
    m_scores[index] = score;
}
