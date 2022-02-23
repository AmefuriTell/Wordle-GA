#ifndef _INDIVIDUAL_H_
#define _INDIVIDUAL_H_

#include <bits/stdc++.h>
#include "Words.hpp"
#include "Word.hpp"

#define CHROM_SIZE 3
#define DATA_SIZE 12972

#define MUTATE_PROB 1.0 / CHROM_SIZE

#define RAND_01 ((double)rand() / RAND_MAX)

class Individual
{
public:
    Individual(Words *argd);
    ~Individual();

    void evaluate();
    void crossover(Individual *p1, Individual *p2);
    void mutate();
    void print();
    void cerrPrint();

    int chrom[CHROM_SIZE];
    int score;

    Words *data;

    int eliteLevel;
};

#endif