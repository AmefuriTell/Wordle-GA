#include "hpp/Words.hpp"

Words::Words(int argn)
{
    wordsNum = argn;

    //データ入力
    words = new Word[wordsNum];

    //スコア計算前処理 bitを立てていく作業
    /*
        1文字目に入ってる
        2文字目に入ってる
        3文字目に入ってる
        4文字目に入ってる
        5文字目に入ってる
        文字列に含まれている
    */
    exist_or_just.resize(26 * 6);
    for (int i = 0; i < wordsNum; i++)
    {
        Word w = words[i];
        for (int j = 0; j < w.word.size(); j++)
        {
            exist_or_just[(w.word[j] - 'a') * 6 + j][i] = 1;
            exist_or_just[(w.word[j] - 'a') * 6 + 5][i] = 1;

            //std::cerr << exist_or_just[(w.word[j] - 'a') * 6 + 5] << " " << (w.word[j] - 'a') * 6 + j << " " << w.word[j] << std::endl;
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