/*
  ==============================================================================

    Genome.h
    Created: 29 Apr 2020 10:56:49am
    Author:  Miles Partridge

  ==============================================================================
*/

#pragma once
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <algorithm>    // std::copy
#include <memory>

typedef float Gene;
typedef std::vector<Gene> Genes;

enum GenomeScore {              // setting up a 5 star scoring system
    ZeroStars = 0,
    OneStar,
    TwoStar,
    ThreeStar,
    FourStar,
    FiveStar,
    Lock,
    NumOptions
};

typedef std::vector<int> GeneScores;

class Genome {
    
    Genes m_genes;
    GeneScores m_scores;
    
public:
    
    int weight = 3;
    bool lock = false;
    
    
    Genome(int size = 5);
    
    
    Genome(const Genome& other);
    
    
    Genome(const Genome& a, const Genome& b, float crossOverPoint);
    
    
    Genome(const Genome& other, float randomPercentage);
    
    
    Genome(const Genome& other, float randomPoint, bool keepLeft, float randomPercentage);
    
    
    std::string toString();
    
    Genes getGenes();
    
    void setGeneScores(GenomeScore score = GenomeScore::ThreeStar, int index = 0);
    
    
    void operator = (const Genome& other)
    {
        std::copy( other.m_genes.begin(), other.m_genes.end(), m_genes.begin()   );
    };
    
    Gene operator[](int index)
    {
        if(index >= 0 && index < m_genes.size())
        {
            return m_genes[index];
        }else{
            return 0;
        }
    }
    
};

    typedef  std::shared_ptr<Genome> GenomePtr;


