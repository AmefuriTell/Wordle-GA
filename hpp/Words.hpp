#ifndef _WORDS_H_
#define _WORDS_H_

#include <bits/stdc++.h>
#include "Word.hpp"

#define DATA_SIZE 12972

class Words
{
public:
    Words(int argn);
    ~Words();

    void Print();
    void cerrPrint();

    int wordsNum, alfabetNum[26];
    Word *words;

    std::vector<std::bitset<DATA_SIZE>> exist_or_just;
};

#endif