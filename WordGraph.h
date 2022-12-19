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

public:
    WordGraph();

    void insertWord(string word);
    set<string> retrieveWords(map<char,vector<int>> goodLetters, set<char> badLetters);

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

set<string> WordGraph::retrieveWords(map<char,vector<int>> goodLetters, set<char> badLetters)
{
    set<string> possibleWords;

    

    return possibleWords; 
}