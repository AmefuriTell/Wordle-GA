#include "hpp/Population.hpp"

Population::Population()
{
    data = new Words(DATA_SIZE);

    ind = new Individual* [POP_SIZE];
    nextind = new Individual* [POP_SIZE];

    for (int i = 0; i < POP_SIZE; i++)
    {
        ind[i] = new Individual(data);
        nextind[i] = new Individual(data);
    }

    evaluate();
}
Population::~Population()
{
    for (int i = 0; i < POP_SIZE; i++)
    {
        delete ind[i];
        delete nextind[i];
    }
    
    delete[] ind;
    delete[] nextind;
    delete data;
}

void Population::evaluate()
{
    scoreSum = 0;
    for (int i = 0; i < POP_SIZE; i++)
    {
        ind[i]->evaluate();
        scoreSum += ind[i]->score;
    }
    
    sort(0, POP_SIZE - 1);

    //for (int i = 0; i < POP_SIZE; i++)std::cerr << ind[i]->score << std::endl;
}
void Population::sort(int left, int right)
{
    Individual *tmp;

    if(left >= right)return;

    int last = left;
    for (int i = left + 1; i <= right; i++)
    {
        if(ind[i]->score <= ind[left]->score)continue;//降順ソート

        last++;
        tmp = ind[last];
        ind[last] = ind[i];
        ind[i] = tmp;

    }

    tmp = ind[left];
    ind[left] = ind[last];
    ind[last] = tmp;

    sort(left, last - 1);
    sort(last + 1, right);
    
}

void Population::alternate()
{
    for (int i = 0; i < ELITE; i++)
    {
        ind[i]->eliteLevel++;
        nextind[i] = ind[i];
    }

    if(ind[0]->eliteLevel % 500 == 500)
    {
        for (int i = ELITE; i < POP_SIZE; i++)
        {
            for (int j = 0; j < CHROM_SIZE; j++)
            {
                nextind[i]->chrom[j] = rand() % DATA_SIZE;
            }
        }
    }
    else
    {
        for (int i = ELITE; i < POP_SIZE; i++)
        {
            nextind[i]->eliteLevel = 0;
            nextind[i]->crossover(ind[select()], ind[select()]);
        }

        for (int i = ELITE; i < POP_SIZE; i++)
        {
            nextind[i]->mutate();
        }
    }

    Individual** tmp = nextind;
    nextind = ind;
    ind = tmp;
    
    evaluate();
}

int Population::select()
{
    double r = RAND_01;
    int rank;
    for (rank = 1; rank < POP_SIZE; rank++)
    {
        double prob = ind[rank - 1]->score / scoreSum;
        if(r <= prob)
        {
            break;
        }
        r -= prob;
    }
    
    return rank - 1;
}

void Population::printResult()
{
    ind[0]->print();
}