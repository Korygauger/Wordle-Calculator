#pragma once
#include <string>
#include <set>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>

using namespace std;

class WordGraph
{
    map<char, vector<string>> First;
    map<char, vector<string>> second;
    map<char, vector<string>> third;
    map<char, vector<string>> fourth;
    map<char, vector<string>> fifth;

    struct word
    {
        string word;
        bool firstReached;
    };

public:
    WordGraph();

    void insertWord(string word);
    set<string> retrieveWords(string positivePos, set<char> posChar, set<char> negChar, vector<string> negPos);

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

set<string> WordGraph::retrieveWords(string positivePos, set<char> posChar, set<char> negChar, vector<string> negPos)
{
    set<string> possibleWords;

    //these don't work together need to work on this added a struct that may help

    // for (int i = 0; i < First[positivePos[0]].size(); i++)
    //     possibleWords.insert(First[positivePos[0]][i]);

    // for (int i = 0; i < second[positivePos[1]].size(); i++)
    //     possibleWords.insert(second[positivePos[1]][i]);

    // for (int i = 0; i < third[positivePos[2]].size(); i++)
    //     possibleWords.insert(third[positivePos[2]][i]);

    // for (int i = 0; i < fourth[positivePos[3]].size(); i++)
    //     possibleWords.insert(fourth[positivePos[3]][i]);

    // for (int i = 0; i < fifth[positivePos[4]].size(); i++)
    //     possibleWords.insert(fifth[positivePos[4]][i]);


    return possibleWords; 
}