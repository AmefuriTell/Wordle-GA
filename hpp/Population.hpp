#ifndef _POPULATION_H_
#define _POPULATION_H_

#include <bits/stdc++.h>
#include "Individual.hpp"
#include "Words.hpp"
#include "Word.hpp"

#define POP_SIZE 10000
#define ELITE 1

class Population
{
public:

    Population();
    ~Population();

    void alternate();
    void printResult();

    Individual **ind;

private:

    void evaluate();
    int select();
    void sort(int left, int right);

    Individual **nextind;
    double scoreSum;
    Words *data;
};

#endif