/*
  ==============================================================================

    Genetics.cpp
    Created: 28 Apr 2020 9:04:12am
    Author:  Miles Partridge

  ==============================================================================
*/

#include "Genetics.h"
#include <iostream>

Genetics::Genetics(int generationSize):
    m_currentGeneration(0),
    m_generationSize(generationSize)
{
    GenomeVector newGeneration;
    
    for(int n = 0; n < m_generationSize; ++n)
    {
        newGeneration.push_back( std::make_shared<Genome>());
    }
    m_generations.push_back(newGeneration);
    printGeneration(0);
}


int Genetics::proportionSelection()
{
    
    int totalWeight = 0;
    for( auto genome : m_generations[m_currentGeneration]  )
    {
        totalWeight += genome->weight;
    }
    int randomOut = rand() % totalWeight;
    
    
    for( int index = 0 ; index <  m_generations[m_currentGeneration].size(); ++index )
    {
        randomOut -=  m_generations[m_currentGeneration][index]->weight;
        if(randomOut <= 0)
        {
            return index;       //scroll through all the genomes, and find the one at the random position denoted by randOut // think roulette wheel
        }
    }
    return 0;
}



void Genetics::printGeneration(int index)
{
    if(index >= 0 && index < m_generations.size())
    {
        std::cout << "Generation "<< index <<std::endl;
        
        for(auto gen : m_generations[index])
        {
            std::cout << "/t" << gen->toString() << std::endl;
        }
        
        std::cout << "***" <<std::endl;
    }
}


void Genetics::setGenomeWeighting(int genomeIndex, int weight)
{
    if(genomeIndex >= 0 && genomeIndex < m_generationSize)
    {
        m_generations[m_currentGeneration][genomeIndex]->weight = weight;
    }
}


void Genetics::mutateGeneration(float randomPercentage)
{
    
    int selection = proportionSelection();      //get a genome to base the next gen on
    
    GenomeVector newGeneration;
    
    for(int n = 0; n < m_generationSize; ++n)
    {
        if( m_generations[m_currentGeneration][n]->lock == false )
        {
            newGeneration.push_back(std::make_shared<Genome>(*m_generations[m_currentGeneration][selection], randomPercentage));
        }else{
            newGeneration.push_back(std::make_shared<Genome>(  *m_generations[m_currentGeneration][n] ) ) ;
        }       // this is where the constructor overload is called
    }
    m_generations.push_back(newGeneration);
    ++m_currentGeneration;
}


Genome* Genetics::getGenome(int index)
{
    if(index >= 0 && index < m_generations[m_currentGeneration].size())
    {
        return m_generations[m_currentGeneration][index].get();
    }else{
        return nullptr;
    }
}
