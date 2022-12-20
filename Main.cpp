#include <string>
#include <set>
#include <vector>
#include <map>
#include <iostream>
#include "WordGraph.h"
#include "Wordle.h"

using namespace std;

// g++ Main.cpp -o Wordle-Calculator.exe && ./Wordle-Calculator

int main()
{
    WordGraph words;
    wordle currWordle;

    bool green = true;
    bool yellow = false;

    while (true)
    {      
        char letter;
        int pos;

        if (green)
            cout << "Enter in a green letter (0 to Continue)" << endl;
          
        if (yellow)
            cout << "Enter a Yellow letter (0 to Continue)" << endl;

        cin >> letter;

        if (letter == '0' && !green)
            break;

        if (letter == '0')
        {
            green = false;
            yellow = true;
        }

        if (green)
        {

            cout << "Enter its position 12345" << endl;

            cin >> pos;

            if (pos < 5 && pos > 0)
                currWordle.insertGreen(letter, pos - 1);

            else 
                cout << "invalid position" << endl;

        }

        else
        {
            vector<int> poss;

            cout << "Enter its possible positions 12345" << endl << "Enter 0 to Continue" << endl;

            while (true)
            {
            
                cin >> pos;

                if (pos == 0)
                    break;

                poss.push_back(pos - 1);
            }
            
            currWordle.insertYellow(letter, poss);
        }
    }

    cout << "Enter any bad letters" << endl;
    cout << "0 to Continue" << endl;

    while (true)
    {
        char letter;
        cin >> letter;

        if (letter == '0')
            break;

        currWordle.insertGrey(letter);

    }

    currWordle.print();
    
    words.retrieveWords(currWordle);



    return 0;
}