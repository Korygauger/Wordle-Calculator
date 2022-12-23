#pragma once
#include <vector>
#include <string>
#include <set>
#include <iostream>

using namespace std;

struct wordle
{
    pair<bool, char> greenLetters [5];
    map<char,vector<int>> yellowLetters;
    set<char> badLetters;

    wordle();

    void insertGreen(char letter, int pos);
    void insertYellow(char letter, vector<int> pos);
    void insertGrey(char letter);

    void print();    

};

wordle::wordle()
{
    for (int i = 0; i < 5; i++)
    {
        greenLetters[i] = make_pair(false, '0');
    }
}

void wordle::insertGreen(char letter, int pos)
{
    greenLetters[pos] = make_pair(true, letter);
}

void wordle::insertYellow(char letter, vector<int> pos)
{
    yellowLetters[letter] = pos;
}

void wordle::insertGrey(char letter)
{
    badLetters.insert(letter);
}

void wordle::print()
{
    cout << endl << "Green Letters" << endl;
    cout << "=============" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << greenLetters[i].second << " " << i << endl;
    }

    cout << endl << "Yellow Letters" << endl;
    cout << "==============" << endl;
    for (auto itr = yellowLetters.begin(); itr != yellowLetters.end(); itr++)
    {
        cout << itr->first << " ";
        for (int i = 0; i < itr->second.size(); i++)
        {
            cout << itr->second[i] << ", ";
        }
        cout << endl;
    }

    cout << endl << "Bad Letters" << endl;
    cout << "===========" << endl;
    for (auto itr = badLetters.begin(); itr != badLetters.end(); itr++)
    {
        cout << *itr << ", ";
    }
}



