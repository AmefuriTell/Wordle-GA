#ifndef _WORD_H_
#define _WORD_H_

#include <bits/stdc++.h>

class Word
{
public:
    Word();

    void input();
    void print();

    std::bitset<26> alfabet;
    std::string word;
};

#endif