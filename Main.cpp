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

    map<char,vector<int>> goodLetters;
    set<char> badLetters;

    cout << "Enter any good letters" << endl;
    cout << "0 to Exit and Continue" << endl;

    while (true)
    {
        char letter;
        cin >> letter;

        if (letter == '0')
            break;

        cout << "Enter its possible positions 01234" << endl;
        cout << "Enter 5 to continue" << endl;
        while (true)
        {
            int position;
            cin >> position;

            if (position == 5)
                break;

            goodLetters[letter].push_back(position);
        }

        cout << "Enter more? 0 to exit" << endl;
    }

    cout << "Enter any bad letters" << endl;
    cout << "0 to Exit and Continue" << endl;

    while (true)
    {
        char letter;
        cin >> letter;

        if (letter == '0')
            break;

        badLetters.insert(letter);

    }

    

    return 0;
}