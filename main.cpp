#include <bits/stdc++.h>

#include "hpp/Population.hpp"

#define GEN_MAX 100000

int main()
{
    Population *pop;

    srand((unsigned int)time(NULL));

    pop = new Population();

    for (int i = 1; i <= GEN_MAX; i++)
    {
        pop->alternate();
        if(pop->ind[0]->eliteLevel == 1)
        {
            std::cout << "第" << i << "世代 : score = ";
            pop->ind[0]->print();
        }
        std::cerr << "第" << i << "世代 : score = " << pop->ind[0]->score << std::endl;
    }

    delete pop;
}