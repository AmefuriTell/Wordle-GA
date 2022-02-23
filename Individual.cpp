#include "hpp/Individual.hpp"

Individual::Individual(Words *argd)
{
    for (int i = 0; i < CHROM_SIZE; i++)
    {
        chrom[i] = rand() % DATA_SIZE;
    }
    score = 0;

    data = argd;
    eliteLevel = 0;
}

Individual::~Individual()
{

}

void Individual::evaluate()
{
/*
    score = 0;
    std::bitset<26> alfa(0);

    for (int i = 0; i < CHROM_SIZE; i++)
    {
        int increaseAlfa = alfa.count();
        double increaseScore = 0;


        for (int j = 0; j < 26; j++)
        {
            if(data->words[chrom[i]].alfabet[j] ^ alfa[j])increaseScore += ((double)data->alfabetNum[j] / DATA_SIZE);
        }

        alfa = data->words[chrom[i]].alfabet | alfa;

        increaseScore *= (1.0 + (double)(CHROM_SIZE - i) / CHROM_SIZE) * (alfa.count() - increaseAlfa);
        score += increaseScore;
    }
*/
    score = 0;
    
    for (int ansd = 0; ansd < DATA_SIZE; ansd++)
    {
        std::bitset<DATA_SIZE> possibility;
        possibility.flip();

        Word ans = data->words[ansd];
        if(ansd == chrom[0] || ansd == chrom[1] || ansd == chrom[2])continue;
        //すべての単語解答に対して、どれだけ他の単語から絞れるか、それの最大値をスコアとする

        for (int i = 0; i < CHROM_SIZE; i++)
        {
            for (int j = 0; j < ans.word.size(); j++)
            {
                //std::cerr << ans.word[j] << " ";
                //std::cerr << data->words[chrom[i]].word[j] << std::endl;
                if(ans.word[j] == data->words[chrom[i]].word[j])
                {
                    possibility &= data->exist_or_just[(data->words[chrom[i]].word[j] - 'a') * 6 + j];
                }
                else if(ans.alfabet[data->words[chrom[i]].word[j] - 'a'])
                {
                    possibility &= ~data->exist_or_just[(data->words[chrom[i]].word[j] - 'a') * 6 + j] & data->exist_or_just[(data->words[chrom[i]].word[j] - 'a') * 6 + 5];
                }
                else
                {
                    possibility &= ~data->exist_or_just[(data->words[chrom[i]].word[j] - 'a') * 6 + 5];
                }
            }
        }

        score = std::max((int)possibility.count(), score);
    }

    score = DATA_SIZE - score;
}

void Individual::crossover(Individual *p1, Individual *p2)
{
    Individual tmp(data);
    int point = rand() % (CHROM_SIZE - 1);
    for (int i = 0; i < point; i++)
    {
        tmp.chrom[i] = p1->chrom[i];
    }
    for (int i = point; i < CHROM_SIZE; i++)
    {
        tmp.chrom[i] = p2->chrom[i];
    }

    *this = tmp;

/*
    Individual tmp1(data), tmp2(data), max(data);
    max.score = 0;

    for (int point = 0; point < CHROM_SIZE - 1; point++)
    {
        for (int i = 0; i < point; i++)
        {
            tmp1.chrom[i] = p1->chrom[i];
            tmp2.chrom[i] = p2->chrom[i];
        }
        for (int i = point; i < CHROM_SIZE; i++)
        {
            tmp1.chrom[i] = p2->chrom[i];
            tmp2.chrom[i] = p1->chrom[i];
        }
        
        tmp1.evaluate();
        tmp2.evaluate();

        if(max.score < tmp1.score)max = tmp1;
        if(max.score < tmp2.score)max = tmp2;
    }

    *this = max;
*/
}

void Individual::mutate()
{
    for (int i = 0; i < CHROM_SIZE; i++)
    {
        if(RAND_01 < MUTATE_PROB)
        {
            chrom[i] = rand() % DATA_SIZE;
        }
    }
}

void Individual::print()
{
    std::cout << score << std::endl;
    for (int i = 0; i < CHROM_SIZE; i++)
    {
        data->words[chrom[i]].print();
    }
}