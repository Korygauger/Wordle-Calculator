#include <string>
#include <set>
#include <vector>
#include <map>
#include <iostream>
#include "WordGraph.h"

using namespace std;

// g++ Main.cpp -o Wordle-Calculator.exe && ./Wordle-Calculator

int main()
{
    WordGraph words;
    set<char> posChar;
    set<char> negChar;
    string positivePos;
    vector<string> negPos;

    cout << "Enter the known correct characters" << endl;
    cout << "Type 0 to exit and continue" << endl;

    while (true)
    {
        char letter;
        cin >> letter;

        if (letter == '0')
            break;

        posChar.insert(letter);
    }

    cout << "Enter the known incorrect characters" << endl;
    cout << "Type 0 to exit and continue" << endl;

    while (true)
    {
        char letter;
        cin >> letter;

        if (letter == '0')
            break;

        negChar.insert(letter);
    }

    cout << "Enter the Positive Positions as a word" << endl;
    cout << "Ex: if a is in the first position enter a----" << endl;
    cout << "Type to exit and continue" << endl;

    cin >> positivePos;

    int count = 0;

    for (int i = 0; i < positivePos.length(); i++)
    {
        if (positivePos[i] == '-')
            count++;
    }

    cout << "Enter the Negative Positions" << endl;

    for (count; count > 0; count--)
    {
        string negWord;
        cin >> negWord;

        negPos.push_back(negWord);
    }

    set<string> PossibleWords = words.retrieveWords(positivePos, posChar, negChar, negPos);

    for (auto itr = PossibleWords.begin(); itr != PossibleWords.end(); itr++)
    {
        cout << *itr << ", ";
    }
    
    return 0;
}