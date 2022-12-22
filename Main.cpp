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

    cout << "Enter 0 for new UI 1 for old" << endl;
    int selection;
    cin >> selection;
    
    bool green = true;
    bool yellow = false;

    if (!selection)
    {
        while (true)
        {
            cout << "Enter one of your guesses (0 to continue)" << endl;

            string guess;
            cin >> guess;

            if (guess == "0")
                break;

            set<int> correctPos;
            cout << "Which positions are green 12345 (0 to continue)" << endl;
            while (true)
            {
                int pos;
                cin >> pos;
                if (pos == 0)
                    break;
                
                currWordle.insertGreen(guess[pos-1], pos-1);
                correctPos.insert(pos-1);
            }

            cout << "Which positions are yellow 12345 (0 to continue)" << endl;
            vector<int> yellowPos;
            while (true)
            {
                int pos;
                cin >> pos;
                if (pos == 0)
                    break;
                
                yellowPos.push_back(pos-1);
                correctPos.insert(pos-1);
            }

            for (int i = 0; i < yellowPos.size(); i++)
            {
                vector<int> possiblePoss;
                for (int j = 0; j < 5; j++)
                {
                    if (j != yellowPos[i])
                        possiblePoss.push_back(j);
                }

                currWordle.insertYellow(guess[yellowPos[i]], possiblePoss);
                possiblePoss.clear();
            }

            for (int i = 0; i < 5; i++)
            {
                if (correctPos.find(i) == correctPos.end())
                    currWordle.insertGrey(guess[i]);
            }
        }
    }

    if (selection)
    {
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
                continue;
            }

            if (green)
            {

                cout << "Enter its position 12345" << endl;

                cin >> pos;

                if (pos <= 5 && pos > 0)
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
    }

    //currWordle.print();

    cout << endl;
    
    set<string> possibleWords = words.retrieveWords(currWordle);

    if (possibleWords.empty())
        cout << "No words match" << endl;

    for (auto itr = possibleWords.begin(); itr != possibleWords.end(); itr++)
    {
        cout << *itr << ", ";
    }

    cout << endl << "press any button to exit";
    cin >> selection;

    return 0;
}