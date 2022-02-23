#include "hpp/Word.hpp"

Word::Word()
{
    for (int i = 0; i < 26; i++)
    {
        alfabet[i] = false;
    }
    input();
}

void Word::input()
{
    std::cin >> word;
    for (int i = 0; i < word.size(); i++)
    {
        alfabet[word[i] - 'a'] = true;
    }
}

void Word::print()
{
    std::cout << word << std::endl;
}