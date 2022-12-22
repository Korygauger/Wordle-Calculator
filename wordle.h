#pragma once
#include <vector>
#include <string>
#include <set>
#include <iostream>

using namespace std;

struct wordle
{
    bool greenPos [5] = {false, false, false, false, false};
    string goodLetters[5] = {"", "", "", "", ""};
    set<char> badLetters;

    void insertGreen(char letter, int pos);
    void insertYellow(char letter, vector<int> pos);
    void insertGrey(char letter);

    void print();    

};

void wordle::insertGreen(char letter, int pos)
{
    greenPos[pos] = true;

    goodLetters[pos] = letter;
}

void wordle::insertYellow(char letter, vector<int> pos)
{
    int size = pos.size();
    for (int i = 0; i < pos.size(); i++)
    {
        if (greenPos[i])
            continue;
        
        goodLetters[pos[i]] += letter;
    }
}

void wordle::insertGrey(char letter)
{
    badLetters.insert(letter);
}

void wordle::print()
{
    cout << "Good Letters" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << goodLetters[i] << " ";
        
        if (greenPos[i])
            cout << "Green"; 
        
        cout << endl;

    }

    cout << "Bad Letters" << endl;
    for (auto itr = badLetters.begin(); itr != badLetters.end(); itr++)
    {
        cout << *itr << ", ";
    }
}



