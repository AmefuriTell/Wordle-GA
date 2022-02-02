#ifndef _WORDS_H_
#define _WORDS_H_

#include <bits/stdc++.h>
#include "Word.hpp"

class Words
{
public:
    Words(int argn);
    ~Words();

    void Print();

    int wordsNum, alfabetNum[26];
    Word *words;
};

#endif