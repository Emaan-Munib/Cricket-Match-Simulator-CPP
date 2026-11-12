#include "Fast_Scoreboad.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <windows.h>
#include <vector>
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define LIGHTBLUE    "\033[94m"
#define CYAN  "\033[36m"
using namespace std;

int main()
{
    int Mtype = 0, choice = 0, choice2 = 0, i = 0, T20 = 0, ODI = 0, TDay = 0, Test = 0;
    char co;
    string TA, TB;
    vector<Cricket> matches;
    for (;;)
    {
    start:
        system("CLS");
        cout << "                          MAIN MENU\n\n";
        cout << " SELECT TEAMS                ";
        cout << LIGHTBLUE "\n---------------------------------------------------------\n" RESET;
        cout << "\t\t 1.Pakistan VS India          \n";
        cout << "\t\t 2.Pakistan Vs Australia      \n";
        cout << "\t\t 3.Pakistan Vs New Zealand      \n";
        cout << "\t\t 4.Exit                       \n";
        cout << LIGHTBLUE "---------------------------------------------------------\n" RESET;
        cout << "Enter your choice:" << endl;
        cin >> choice;
        if (choice == 1)
        {
            TA = "Pakistan";
            TB = "India";
        }
        else if (choice == 2)
        {
            TA = "Pakistan";
            TB = "Australia";
        }
        else if (choice == 3)
        {
            TA = "Pakistan";
            TB = "New Zealand";
        }
        else if (choice == 4)
            return 0;
        else
        {
            cout << "Invalid input\n";
            Sleep(1000);
            goto start;
        }
        system("CLS");
        cout << "\t\tSELECT MATCH TYPE \n";
        cout << LIGHTBLUE "\n---------------------------------------------------\n" RESET;
        cout << "\t\t 1.International Test       \n";
        cout << "\t\t 2.3-Day Match             \n";
        cout << "\t\t 3.One-Day Match           \n";
        cout << "\t\t 4.T20 Match               \n";
        cout << "\t\t 5.Back                    \n";
        cout << LIGHTBLUE "-----------------------------------------------------\n" RESET;
        cout << "Enter your choice : " << endl;
        cin >> Mtype;
    MatchStart:
        if (Mtype == 5)
            goto start;
        else if (Mtype == 1)
        {
            Test++;
            matches.push_back(Cricket(Mtype, TA, TB, Test));
            matches.back().StartMatch();
        }
        else if (Mtype == 2)
        {
            TDay++;
            matches.push_back(Cricket(Mtype, TA, TB, TDay));
            matches.back().StartMatch();
        }
        else if (Mtype == 3)
        {
            ODI++;
            matches.push_back(Cricket(Mtype, TA, TB, ODI));
            matches.back().StartMatch();
        }
        else if (Mtype == 4)
        {
            T20++;
            matches.push_back(Cricket(Mtype, TA, TB, T20));
            matches.back().StartMatch();
        }
        else
        {
            cout << "Invalid Input";
            i++;
            goto start;
        }

    EndMatch:
        system("CLS");
        cout << "\t\t Other Options \n";
        cout << LIGHTBLUE "\n------------------------------------------------\n" RESET;
        cout << "\t\t 1.Ball by Ball Score   \n";
        cout << "\t\t 2.Replay Match         \n";
        cout << "\t\t 3.New Match            \n";
        cout << "\t\t 4.Exit                 \n";
        cout << LIGHTBLUE "------------------------------------------------\n" RESET;
        cout << "Enter your choice  :        \n";
        cin >> choice2;

        if (choice2 == 1)
        {
            matches.back().GetBallByBall();
        }
        else if (choice2 == 2)
        {
            int rep = 0;
            for (int j = 0; j < matches.size(); j++)
            {
                cout << j + 1 << "." << matches[j] << endl;
            }
            cout << "Enter the match you want to replay: ";
            cin >> rep;
            matches[rep - 1].ReplayMatch();
            goto EndMatch;
        }
        else if (choice2 == 3)
        {
            goto start;
        }
        else if (choice2 == 4)
        {
            matches.clear();
            i = -1;
            return 0;
        }

        cout << "Press\n1.Back" << endl << "Any other key to exit\n";
        cin >> co;
        if (co == '1')
            goto EndMatch;
        else
            return 0;
    }

    return 0;
}

