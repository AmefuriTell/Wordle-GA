#include "hpp/Words.hpp"

Words::Words(int argn)
{
    wordsNum = argn;

    //データ入力
    words = new Word[wordsNum];

    //アルファベットの出現頻度を数える。
    for (int i = 0; i < 26; i++)alfabetNum[i] = 0;
    for (int i = 0; i < wordsNum; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if(words[i].alfabet[j])alfabetNum[j] ++;
        }
    }
    
    //for (int i = 0; i < 26; i++)std::cout << (char)(i + 'a') << " " << (double)alfabetNum[i] / wordsNum << std::endl;

}

Words::~Words()
{
    delete[] words;
}

void Words::Print()
{
    for (int i = 0; i < wordsNum; i++)
    {
        std::cerr << words[i].word << std::endl;
    }
}