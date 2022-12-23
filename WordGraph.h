#pragma once
#include <string>
#include <set>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "wordle.h"

using namespace std;

class WordGraph
{
    map<char, vector<string>> First;
    map<char, vector<string>> second;
    map<char, vector<string>> third;
    map<char, vector<string>> fourth;
    map<char, vector<string>> fifth;

public:
    WordGraph();

    void insertWord(string word);
    set<string> retrieveWords(wordle wordly);
    set<string> loadWords(char letter, int pos);
    set<string> setIntersect(set<string> words1, set<string> words2);
    set<string> setDisUnion(set<string> goodWords, set<string> badWords);

};

WordGraph::WordGraph()
{
    ifstream file("words.txt");

    string word;
    if (file.is_open())
    {
        while(file)
        {
            file >> word;
            //cout << word << endl;
            insertWord(word);

        }

        file.close();
    }

    else
        cout << "Words.txt not found" << endl;

    First['-'] = {};
    second['-'] = {};
    third['-'] = {};
    fourth['-'] = {};
    fifth['-'] = {};



}

void WordGraph::insertWord(string word)
{
    First[word[0]].push_back(word);
    second[word[1]].push_back(word);
    third[word[2]].push_back(word);
    fourth[word[3]].push_back(word);
    fifth[word[4]].push_back(word);
}

set<string> WordGraph::retrieveWords(wordle wordly)
{
    set<string> possibleWords;
    set<string> yelloWords;
    set<string> hold;

    bool firstIter = true;

    for (int i = 0; i < 5; i++)
    {
        if (!wordly.greenLetters[i].first)
            continue;

        if (firstIter)
        {
            possibleWords = loadWords(wordly.greenLetters[i].second, i);
            firstIter = false;
        }

        else
        {
            hold = loadWords(wordly.greenLetters[i].second, i);
            possibleWords = setIntersect(possibleWords, hold);
        }
        

    }

    // at this point all words with green letters in the right places will be in possible words

    firstIter = true;
    for (auto itr = wordly.yellowLetters.begin(); itr != wordly.yellowLetters.end(); itr++)
    {
        // put new yellow letter loader here
        if (firstIter)
        {
            for (int i = 0; i < itr->second.size(); i++)
            {
                hold = loadWords(itr->first, itr->second[i]);
                yelloWords.insert(hold.begin(), hold.end());
            }

            firstIter = false;
        }

        else
        {
            set<string> holdover;
            for (int i = 0; i < itr->second.size(); i++)
            {
                holdover = loadWords(itr->first, itr->second[i]);
                hold.insert(holdover.begin(),holdover.end());
            }
            yelloWords = setIntersect(yelloWords, hold);
        }
    } 

    possibleWords = setIntersect(yelloWords, possibleWords);

    set<string> wrongWords;
    for (auto itr = wordly.badLetters.begin(); itr != wordly.badLetters.end(); itr++)
    {
        for (int i = 0; i < 5; i++)
        {
            if (wordly.greenLetters[i].first)
                continue;

            hold = loadWords(*itr, i);
            wrongWords.insert(hold.begin(), hold.end());            
        }
    }

    possibleWords = setDisUnion(possibleWords, wrongWords);

    return possibleWords; 
}

set<string> WordGraph::loadWords(char letter, int pos)
{
    set<string> words;
    if (pos == 0)
        for (int i = 0; i < First[letter].size(); i++)
            words.insert(First[letter][i]);

    else if (pos == 1)
        for (int i = 0; i < second[letter].size(); i++)
            words.insert(second[letter][i]);

    else if (pos == 2)
        for (int i = 0; i < third[letter].size(); i++)
            words.insert(third[letter][i]);
    
    else if (pos == 3)
        for (int i = 0; i < fourth[letter].size(); i++)
            words.insert(fourth[letter][i]);
    
    else if (pos == 4)
        for (int i = 0; i < fifth[letter].size(); i++)
            words.insert(fifth[letter][i]);
    
    return words;
}

set<string> WordGraph::setIntersect(set<string> words1, set<string> words2)
{
    set<string> possibleWords;
    for (auto itr = words2.begin(); itr != words2.end(); itr++)
    {
        if (words1.find(*itr) != words1.end())
        {
            possibleWords.insert(*itr);
        }
    }

    return possibleWords;
}

set<string> WordGraph::setDisUnion(set<string> goodWords, set<string> badWords)
{
    set<string> possibleWords;
    for (auto itr = goodWords.begin(); itr != goodWords.end(); itr++)
    {
        if (badWords.find(*itr) == badWords.end())
        {
            possibleWords.insert(*itr);
        }
    }

    return possibleWords;
}