/*
  ==============================================================================

    Genetics.h
    Created: 28 Apr 2020 9:04:12am
    Author:  Miles Partridge

  ==============================================================================
*/

#pragma once
#include "Genome.h"
#include <vector>



typedef std::vector<GenomePtr> GenomeVector;
typedef std::vector<GenomeVector> GenomeGeneration;

class Genetics {
    GenomeGeneration m_generations;
    int m_currentGeneration;
    const int m_generationSize;
    
    int proportionSelection();
    
public:
    
    void printGeneration(int index);
    
    
    Genetics(int generationSize = 5);
    
    void setGenomeWeighting(int genomeIndex, int weight);
    
    void mutateGeneration(float randomPercentage);
    
    Genome* getGenome(int index);
    
};


