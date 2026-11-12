#include "Fast_Scoreboad.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <vector>
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define LIGHTBLUE    "\033[94m"
#define CYAN  "\033[36m"
using namespace std;

Fast_Scoreboad::Fast_Scoreboad()
{
	out = 0;
	Truns = 0;
	num = 0;
	balls = 0;
	MaxOvers = 0;
	MatchType = 0;
	overNum = 0.0;
	over = 0;
	Teamname = "NULL";
	team.clear();
}

Fast_Scoreboad::Fast_Scoreboad(int MatchType, string Teamname)
{
	out = 0;
	Truns = 0;
	num = 0;
	balls = 0;
	this->MatchType = MatchType;
	if (MatchType == 1)//Test Match
		MaxOvers = 120;
	else if (MatchType == 2)//3 Day Match
		MaxOvers = 70;
	else if (MatchType == 3)//ODI Match
		MaxOvers = 50;
	else if (MatchType == 4)//T-20 Match
		MaxOvers = 20;
	overNum = 0.0;
	over = 0.0;
	this->Teamname = Teamname;
	team.clear();
}

Fast_Scoreboad& Fast_Scoreboad::operator()(int MatchType, string Teamname)
{
	out = 0;
	Truns = 0;
	num = 0;
	balls = 0;
	this->MatchType = MatchType;
	overNum = 0.0;
	over = 0;
	this->Teamname = Teamname;
	if (MatchType == 1)//Test Match
		MaxOvers = 120;
	else if (MatchType == 2)//3 Day Match
		MaxOvers = 70;
	else if (MatchType == 3)//ODI Match
		MaxOvers = 50;
	else if (MatchType == 4)//T-20 Match
		MaxOvers = 20;
	return *this;
}

void Fast_Scoreboad::printTeam()
{
	for (int i = 0; i < team.size(); i++)
	{
		cout << team[i] << endl;
	}
}

void Fast_Scoreboad::printScore()
{
	int ov = 0;
	for (int i = 0; i < score.size(); i++)
	{
		cout <<" " << score[i] << " ";
		if ((i + 1) % 6 == 0)
		{
			cout << endl;
			ov++;
		}
	}
}

Fast_Scoreboad::~Fast_Scoreboad()
{
	team.clear();
	score.clear();
}



Match::Match():Fast_Scoreboad()
{
}

Match::Match(int MatchType, string Teamname) : Fast_Scoreboad(MatchType, Teamname)
{
}

void Match::TestScore(int MaxOvers)
{
	srand(time(NULL));
	int Num, temp=0, wickets = 0;
	for (int i = 0; i < MaxOvers * 6; i++)
	{
		do {
			Num = rand() % 8 - 1;
		} while (Num == 5);
			if (i >= 42)
			{
		temp = 0;
				if (Num == 6 || Num == 4 || Num == 3)
				{
					for (int j = i - 42; j < i; j++)
					{
						if (score[j] == 4 || score[j] == 6 || score[j] == 3)
							temp++;
					}
					if (temp >= 3)
					{
						if (Num == 3)
							Num -= 3;
						else if (Num == 4)
							Num -= 4;
						else if (Num == 6)
							Num -= 6;
					}
				}
			}
			else
			{
				if (Num == 6 || Num == 4 || Num == 3)
				{
					for (int j = 0; j < i; j++)
					{
						if (score[j] == 4 || score[j] == 6 || score[j] == 3)
							temp++;
					}
					if (temp >= 3)
					{
						if (Num == 3)
							Num -= 3;
						else if (Num == 4)
							Num -= 4;
						else if (Num == 6)
							Num -= 6;
					}
				}

			}
			if (Num == -1)
			{
			temp = 0;
				cout << i << "i ";
				if (i >= 132)
				{
					for (int j = i - 132; j < i; j++)
					{
						if (score[j] == -1)
							temp++;
					}
					if (temp >= 2)
					{
						Num++;
					}
				}
				else
				{
					for (int j = 0; j < i; j++)
					{
						if (score[j] == -1)
							temp++;
					}
					if (temp >= 2)
					{
						Num++;
					}
				}
			}
		
		if (Num == -1)
		{
			wickets++;
		}
		if (wickets == 10)
		{
			score.push_back(10);
			return;
		}
		score.push_back(Num);
	}
}

void Match::ThreeDScore(int MaxOvers)
{
	srand(time(NULL));
	int Num, temp = 0, wickets = 0;
	for (int i = 0; i < MaxOvers * 6; i++)
	{
		do {
			Num = rand() % 8 - 1;
		} while (Num == 5);
		if (i >= 30)
		{
			temp = 0;
			if (Num == 6 || Num == 4 || Num == 3)
			{
				for (int j = i - 30; j < i; j++)
				{
					if (score[j] == 4 || score[j] == 6 || score[j] == 3)
						temp++;
				}
				if (temp >= 3)
				{
					if (Num == 3)
						Num -= 3;
					else if (Num == 4)
						Num -= 4;
					else if (Num == 6)
						Num -= 6;
				}
			}
		}
		else
		{
			if (Num == 6 || Num == 4 || Num == 3)
			{
				for (int j = 0; j < i; j++)
				{
					if (score[j] == 4 || score[j] == 6 || score[j] == 3)
						temp++;
				}
				if (temp >= 3)
				{
					if (Num == 3)
						Num -= 3;
					else if (Num == 4)
						Num -= 4;
					else if (Num == 6)
						Num -= 6;
				}
			}

		}
		if (Num == -1)
		{
			temp = 0;
			cout << i << "i ";
			if (i >= 70)
			{
				for (int j = i - 70; j < i; j++)
				{
					if (score[j] == -1)
						temp++;
				}
				if (temp >= 2)
				{
					Num++;
				}
			}
			else
			{
				for (int j = 0; j < i; j++)
				{
					if (score[j] == -1)
						temp++;
				}
				if (temp >= 2)
				{
					Num++;
				}
			}
		}

		if (Num == -1)
		{
			wickets++;
		}
		if (wickets == 10)
		{
			score.push_back(10);
			return;
		}
		score.push_back(Num);
	}
}

void Match::ODIScore(int MaxOvers)
{
	srand(time(NULL));
	int Num, temp = 0, wickets = 0;
	for (int i = 0; i < MaxOvers * 6; i++)
	{
		do {
			Num = rand() % 8 - 1;
		} while (Num == 5);
		if (i >= 24)
		{
			temp = 0;
			if (Num == 6 || Num == 4 || Num == 3)
			{
				for (int j = i - 24; j < i; j++)
				{
					if (score[j] == 4 || score[j] == 6 || score[j] == 3)
						temp++;
				}
				if (temp >= 3)
				{
					if (Num == 3)
						Num -= 3;
					else if (Num == 4)
						Num -= 4;
					else if (Num == 6)
						Num -= 6;
				}
			}
		}
		else
		{
			if (Num == 6 || Num == 4 || Num == 3)
			{
				for (int j = 0; j < i; j++)
				{
					if (score[j] == 4 || score[j] == 6 || score[j] == 3)
						temp++;
				}
				if (temp >= 3)
				{
					if (Num == 3)
						Num -= 3;
					else if (Num == 4)
						Num -= 4;
					else if (Num == 6)
						Num -= 6;
				}
			}

		}
		if (Num == -1)
		{
			temp = 0;
			cout << i << "i ";
			if (i >= 50)
			{
				for (int j = i - 50; j < i; j++)
				{
					if (score[j] == -1)
						temp++;
				}
				if (temp >= 2)
				{
					Num++;
				}
			}
			else
			{
				for (int j = 0; j < i; j++)
				{
					if (score[j] == -1)
						temp++;
				}
				if (temp >= 2)
				{
					Num++;
				}
			}
		}

		if (Num == -1)
		{
			wickets++;
		}
		if (wickets == 10)
		{
			score.push_back(10);
			return;
		}
		score.push_back(Num);
	}
}

void Match::T20Score(int MaxOvers)
{
	srand(time(NULL));
	for (int i = 0; i < MaxOvers * 6; i++)
	{
		int Num, temp = 0, count=0;
		do {
			Num = rand() % 8 - 1;
			if (i >= 10 && (Num == 6 || Num == 4 || Num == 3))
			{
				for (int j = i - 10; j < i; j++)
				{
					if (score[j] == 4 || score[j] == 6 || score[j] == 3)
						temp++;
				}
				if (temp >= 3)
				{
					if (Num == 3)
						Num -= 3;
					else if (Num == 4)
						Num -= 4;
					else if (Num == 6)
						Num -= 6;
				}
			}
			temp = 0;
			if (Num == -1)
			{
				if (i >= 40)
				{
					for (int j = i - 40; j < i; j++)
					{
						if (score[j] == -1)
							temp++;
					}
					if (temp >=3)
					{
						Num++;
					}
				}
				else
				{
					for (int j = 0; j < i; j++)
					{
						if (score[j] == -1)
							temp++;
					}
					if (temp >=3)
					{
						Num++;
					}
				}
			}
		} while (Num == 5);
		if (Num == -1)
		{
			count++;
		}
		if (count == 10)
		{
			score.push_back(10);
			return;
		}
		score.push_back(Num);
	}
}

void Match::SuperOver()
{
	score.push_back(63);
	{
		srand(time(NULL));
		for (int i = 0; i < 6; i++)
		{
			int Num, temp = 0, count = 0;
			do {
				Num = rand() % 8 - 1;
			} while (Num == 5);
			score.push_back(Num);
		}
	}
}

int Match::SuperOverDisplay()
{
	int i = 0, Sruns = 0, Sout = 0, userRun, k = 0;
	while (score[i] != 63) 
	{
		i++;
	}
	i++;
	cout << "Press KeyBoard at any time to change the score\n";
	Sleep(2000);
	for (i; i < score.size(); i++)
	{
		if (_kbhit())
		{
			cout << "Enter runs on " << overNum << " over's ball (-1 for a wicket)\n";
			cin >> userRun;
			if (userRun >= -1 && userRun <= 6)
				score[i] = userRun;
			else
				cout << "Invalid runs";
		}
		if (score[i] == -1)
			out++;
		else
		Sruns += score[i];
		system("CLS");
		cout << "Total: " << Sruns << "/" << Sout << "\tOvers 19." << k;
		Sleep(2000);
			k++;
	}
	return Sruns;
}

void Match::SBdisplay()
{
	int userRun;
	cout << "Press KeyBoard at any time to change the score\n";
	Sleep(2000);
	for (int i = 0; i < score.size(); i++)
	{
		srand(time(NULL));
		system("CLS");
		if (_kbhit())
		{
			cout << "Enter runs on " << overNum << " over's ball (-1 for a wicket)\n";
			cin >> userRun;
			if (userRun >= -1 && userRun <= 6)
				score[i] = userRun;
			else
				cout << "Invalid runs";
		}
		int Num;
		if (score[i] == 10)
		{
			AllOut:
			cout <<CYAN "Team all out, Kya hi umdah bowling ki gai hai\n" RESET;
			Sleep(1000);
			break;
		}
		if (score[i] == -1&& i>=3)
		{
			int hatrik=0;
			for (int k = i - 3; k < i; k++)
			{
				if (score[k] == -1)
					hatrik++;
			}
				if (hatrik == 3)
					cout << CYAN "What a bowling, Hatrik" RESET;
				else if (hatrik == 2)
					cout << CYAN "Chance for a hatrik" RESET;
				else
				{
					Num = rand() % 2 + 1;
					if (Num == 1)
						cout << CYAN "Brilliant bowling, Sida wicket pe.Koi chance hi nai the batsman k pass\n" RESET;
					else
						cout << CYAN "OMG! What a catch\n" RESET;
				}
			out++;
			if (out == 10)
				goto AllOut;
		}
		if (score[i] == 4)
		{
			Num = rand() % 2 + 1;
			if (Num == 1)
				cout << CYAN "What a Four, Straight to the boundary \n" RESET;
			else
				cout << CYAN "Ye sida fielder k hatho main jata howa lekin catch drop hoga or bowl boundary se bhir jate hoi 4 runs k liye\n" RESET;
		}
		if (score[i] == 6)
		{
			Num = rand() % 2 + 1;
			if (Num == 1)
				cout << CYAN "Kya gazab shot hai , sida stadium se bahir\n" RESET;
			else
				cout << CYAN "Thora risky shot tha lekin batsman 6 runs lene main kamiyab\n" RESET;
		}
		Truns += score[i];
		if ((i + 1) % 6 == 0)
		{
			over++;
			balls = 0;
		}
		else
		{
			balls = (i + 1) % 6;
		}
		overNum = over + 0.1 * balls;
		cout << Teamname;
		cout << "\t\t"<< Truns << "/" << out << fixed << setprecision(1) << "(" << overNum <<" overs)" << endl;
		cout <<endl<< GetRunrate(Truns) << " run rate\n";
		Sleep(2000);
	}
}

double Match::GetRunrate(int Totalrun)
{
	double Runrate= Totalrun / overNum;
	return Runrate;
}

void Match::displayUmpires()
{
	vector<string>umpires = { " Sam Mitchell", "Emily Anderson", "Jake Patel","Aleem Dar", "Olivia Wilson",
		"Ethan Thompson", "Maya Roberts", " Liam Jackson", "Ava Turner", "Sophia Davis" };
	int Num[3] = { 0 }, ump = 0;
	cout <<"\tThe Staff for Ground Management\n ";
	cout << LIGHTBLUE "\n-----------------------------------------------------\n" RESET;
	cout << LIGHTBLUE "-----------------------------------------------------\n" RESET;
	srand(time(NULL));
		Num[0] = rand() % 4 ;
		Num[1] = rand() % 3 + 4;
		Num[2] = rand() % 3 + 7;
	for (int i = 0; i < 3; i++)
	{
		ump = Num[i];
		if (i == 0)
			cout <<"  On Field Umpires:\n";
		if(i==2)
			cout << "  Third Umpire:\n";
		cout << "\t\t" << umpires[ump]<<endl;
	}
	cout << LIGHTBLUE "-----------------------------------------------------\n" RESET;
	cout << LIGHTBLUE "-----------------------------------------------------\n" RESET;

}

void Match::displayComentator()
{
	vector<string>Commentator = { " Ian Bishop", "Harsha Bhogle", "Michael Holding", "David Lloyd",
		"Ravi Shastri", "Nasser Hussain", "Shane Warne", "Michael Atherton", "Sanjay Manjrekar", "Simon Doull" };
	int Num[3] = { 0 }, ump = 0;
	cout << "\tThe Commentators for this match are\n ";
	cout << LIGHTBLUE "\n-----------------------------------------------------\n" RESET;
	cout << LIGHTBLUE "-----------------------------------------------------\n" RESET;
	srand(time(NULL));
	Num[0] = rand() % 4;
	Num[1] = rand() % 3 + 4;
	Num[2] = rand() % 3 + 7;
	for (int i = 0; i < 3; i++)
	{
		int com = Num[i];
		cout << Commentator[com]<< endl;
	}
	cout << LIGHTBLUE "-----------------------------------------------------\n" RESET;
	cout << LIGHTBLUE "-----------------------------------------------------\n" RESET;

}

void Match::displayVenue()
{
	srand(time(NULL));
	int VENUE = rand() % 4;
	cout << "\tThe Venue for today's match is\n\n";
	cout << LIGHTBLUE "\n-----------------------------------------------------\n" RESET;
	cout << LIGHTBLUE "-----------------------------------------------------\n" RESET;
		switch (VENUE)
		{
		case 0:
			cout << "\tMelbourne Cricket Ground , Australia" << endl;
			break;
		case 1:
			cout << "\tOld Tr-afford Cricket Ground  , England" << endl;
			break;
		case 2:
			cout << "\tLancaster Park , New Zealand " << endl;
			break;
		case 3:
			cout << "\tEdgerton Cricket Ground , England" << endl;
			break;
		}
		cout << LIGHTBLUE "\n-----------------------------------------------------\n" RESET;
		cout << LIGHTBLUE "-----------------------------------------------------\n" RESET;
}

void Match::displayBroadcasting()
{
	cout << "\tOur Broadcasting Partners are \n";
	cout << LIGHTBLUE "\n-----------------------------------------------------\n" RESET;
	cout << LIGHTBLUE "-----------------------------------------------------\n" RESET;
		cout << "\t 	Asports" << endl;
	cout << "\t 	Sony sports" << endl;
	cout << "\t 	PTV sports " << endl;
	cout << "\t 	TEN sports" << endl;

	cout << LIGHTBLUE "\n-----------------------------------------------------\n" RESET;
	cout << LIGHTBLUE "-----------------------------------------------------\n" RESET;
}

void Match::displayGroundStaff()
{
	cout << "\tGround Staff \n";
	cout << LIGHTBLUE "\n-----------------------------------------------------\n" RESET;
	cout << LIGHTBLUE "-----------------------------------------------------\n" RESET;
	cout << "\t 	Hamza Ali" << endl;
	cout << "\t 	Roy Ward" << endl;
	cout << "\t 	Omar Khan " << endl;

	cout << LIGHTBLUE "\n-----------------------------------------------------\n" RESET;
	cout << LIGHTBLUE "-----------------------------------------------------\n" RESET;
}

string Match::toss(string TeamnameA,string TeamnameB)
{
	int result = 0;
		srand(time(NULL));
		result = rand() % 2 + 1;
		if (result == 1)
		{
			return TeamnameA;
		}
		else
		{
			return TeamnameB;
		}
}

void Match::Countdown()
{
	system("CLS");
	cout <<GREEN "\n\n\n\n\n\n\t\t\t\t\t\t MATCH STARTS IN";
	Sleep(2000);
	system("CLS");
	for (int j = 5; j > 0; j--)
	{
		cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t"<<j;
		Sleep(1000);
		system("CLS");
	}
	cout <<"\n\n\n\n\n\n\t\t\t\t\t\t LETS START" RESET;
	Sleep(1000);
	system("CLS");
}



Team::Team():Match()
{
}

Team::Team(int MatchType, string Teamname):Match(MatchType,Teamname)
{
}

bool Team::InputTeam(const string& Teamname)
{
	ifstream infile(Teamname+".txt");
	if (!infile.is_open())
	{
		cout << "FILE NOT FOUND\n";
		exit(-1);
	}
	string line;
	while (getline(infile, line))
	{
		team.push_back(line);
	}
	infile.close();
	return true;
}

/*void Team::PlayerScore()
{
	int j, ball = 0, pout = 0;
	double sRate = 0, pScore = 0;
	srand(time(NULL));
	for (int i = 0; i < score.size(); i++)
	{
		pout = rand() % 5;
		cout << "pout=" << pout << endl;
		pScore = 0;
		ball = 1;
		sRate = 0;
		for (j = i; j<score.size(); j++)
		{
			if (score[j] == -1)
				break;
			pScore += score[j];
			i++;
			ball++;
		}
		sRate = pScore / ball;
		StrikeRate.push_back(sRate);
		playerScore.push_back(pScore);
		BowlersOut[pout]++;
	}
}*/

/*void Team::Scoreboard()
{
	PlayerScore();
	srand(time(NULL));
	int pOut = 0;
	cout << "|\tPlayer name\t|"<<" |\tOut by\t|" <<" |\tScore\t|" <<" |\tStrike Rate\t|" << endl;
	for (int i = 0; i <= 11; i++)
	{
		do {
		pOut = rand() % 5;
		} while (BowlersOut[pOut] == 0);
		BowlersOut[pOut]--;
		string playerName = team[i].substr(0, team[i].find(" |"));
		string bowlerName = team[6+pOut].substr(0, team[6+pOut].find(" |"));

		cout << "|\t" << playerName << "\t|" << " |\t" << bowlerName
			<< "\t|" << " |\t" << playerScore[i] << "\t|" << " |\t" << StrikeRate[i] << "\t|" << endl;
	}
}

void Team::SetBowlersOut()
{
	int Bout = out;
	srand(time(NULL));
	int num = rand() % 4 + 1;
	int out0 = Bout / num;
	Bout -= Bout / num;
	int out1 = Bout / num;
	Bout -= Bout / num;
	int out2 = Bout / num;
	Bout -= Bout / num;
	int out3 = Bout / num;
	int out4 = Bout;
	BowlersOut.push_back(out0);
	BowlersOut.push_back(out1);
	BowlersOut.push_back(out2);
	BowlersOut.push_back(out3);
	BowlersOut.push_back(out4);
}
*/
Team::~Team()
{
	playerScore.clear();
	StrikeRate.clear();
	BowlersOut.clear();
}

/*void Team::ManOfTheMatch()
{
	double PBat[6]; double MaxBat; double MaxBall; int NameBat = 0; int NameBall = 6;
	for (int i = 0; i < 6; i++)
	{
		PBat[i] = StrikeRate[i] + playerScore[i];
	}
	MaxBat = PBat[0];
	MaxBall = BowlersOut[0];

	for (int i = 0; i <= 5; i++)
	{
		if (PBat[i] > MaxBat)
		{
			MaxBat = PBat[i];
			NameBat++;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (BowlersOut[i] > MaxBall)
		{
			MaxBall = BowlersOut[i];
			NameBall++;
		}
	}
	srand(time(NULL));
	int Man = rand() % 2 + 1;
	if (Man == 1)
		cout << "Man of the match goes to : " << team[NameBat].substr(0, 20) << endl;
	else
		cout << "Man of the match goes to :" << team[5+NameBall].substr(0, 20) << endl;
}*/


Cricket::Cricket()
{
	TeamA;
	TeamB;
	TeamnameA = "NULL";
	TeamnameB = "NULL";
	InningFirst = "NULL";
	tossWon = "NULL";
	Target = 0;
	MaxOv = 0;
	series = 0;
}

Cricket::Cricket(int MatchType, string TeamnameA, string TeamnameB,int series)
{
	this->series = series;
	this->TeamnameA = TeamnameA;
	this->TeamnameB= TeamnameB;
	InningFirst = "NULL";
	TeamA(MatchType, TeamnameA);
	TeamA.InputTeam(TeamnameA);
	TeamB(MatchType, TeamnameB);
	TeamB.InputTeam(TeamnameA);
	if (MatchType == 1)//Test Match
		MaxOv = 120;
	else if (MatchType == 2)//3 Day Match
		MaxOv = 70;
	else if (MatchType == 3)//ODI Match
		MaxOv = 50;
	else if (MatchType == 4)//T-20 Match
		MaxOv = 20;
}

Cricket& Cricket::operator()(int MatchType, string TeamnameA,string TeamnameB,int series)
{
	this->series = series;
	TeamA(MatchType, TeamnameA);
	this->TeamnameA = TeamnameA;
	TeamB(MatchType, TeamnameB);
	this->TeamnameB = TeamnameB;
	if (MatchType == 1)//Test Match
		MaxOv = 120;
	else if (MatchType == 2)//3 Day Match
		MaxOv = 70;
	else if (MatchType == 3)//ODI Match
		MaxOv = 50;
	else if (MatchType == 4)//T-20 Match
		MaxOv = 20;
	return *this;
}

string Cricket::operator[](int ind)
{
	cout << "\nSeries Match number: " << GetSeries()<<endl;
	return TeamnameA," vs ", TeamnameB;
}

void Cricket::StartMatch()
{
	TeamA.team.clear();
	TeamB.team.clear();
	char start;
	Sleep(1000);
	system("CLS");
	displayGroundStaff();
	Sleep(2000);
	system("CLS");
	displayBroadcasting();
	Sleep(2000);
	system("CLS");
	displayVenue();
	Sleep(2000);
	system("CLS");
	displayComentator();
	Sleep(2000);
	system("CLS");
	displayUmpires();
	Sleep(2000);
	system("CLS");
	TeamA.InputTeam(TeamnameA);
	cout <<"\t\t"<< TeamnameA << endl;
	TeamA.printTeam();
	Sleep(2000);
	TeamB.InputTeam(TeamnameB);
	system("CLS");
	cout <<"\t\t"<< TeamnameB << endl;
	TeamB.printTeam();
	Sleep(2000);
	system("CLS");
	Sleep(200);
	tossWon = toss(TeamnameA, TeamnameB);
	cout << "Toss is won by " << tossWon;
	FirstInnings(TeamnameA, TeamnameB);
	Sleep(2000);
	cout << "Press Any Key To Continue:";
	_getch();
	Countdown();
	if (InningFirst == TeamnameA)
	{
		if (MatchType == 1)
		{
			cout << "Match " << series << " of Test series Starting\n";
			Sleep(1000);
			TeamAInnings();
			system("CLS");
				SetTarget(TeamA.Truns);
				cout << GetTarget() << " Target set for " << TeamnameB;
				cout << "\n\t\tPress Enter to continue with " << TeamnameB<<" innings\n";
				_getch();
				Sleep(2000);
			TeamBInnings();
		}
		else if (MatchType == 2)
		{
			cout << "Match " << series << " of 3-Day series Starting\n";
			Sleep(1000);
			TeamAInnings();
			system("CLS");
			SetTarget(TeamA.Truns);
			cout << GetTarget() << " Target set for " << TeamnameB;
			cout << "\n\t\tPress Enter to continue with " << TeamnameB << " innings\n";
			_getch();
			Sleep(2000);
			TeamBInnings();
		}
		else if (MatchType == 3)
		{
			cout << "Match " << series << " of ODI Starting\n";
			Sleep(1000);
			TeamAInnings();
			system("CLS");
			SetTarget(TeamA.Truns);
			cout << GetTarget() << " Target set for " << TeamnameB;
			cout << "\n\t\tPress Enter to continue with " << TeamnameB << " innings\n";
			_getch();
			Sleep(2000);
			TeamBInnings();
		}
		else
		{
			cout << "Match " << series << " of T20 Starting\n";
			Sleep(1000);
			TeamAInnings();
			system("CLS");
			SetTarget(TeamA.Truns);
			cout << GetTarget() << " Target set for " << TeamnameB;
			cout << "\n\t\tPress Enter to continue with " << TeamnameB << " innings\n";
			_getch();
			Sleep(2000);
			TeamBInnings();
		}
	}
	else
	{
		if (MatchType == 1)
		{
			cout << "Match " << series << " of Test series Starting\n";
			Sleep(1000);
			TeamBInnings();
			system("CLS");
			SetTarget(TeamB.Truns);
			cout << GetTarget() << " Target set for " << TeamnameA;
				cout << "\n\t\tPress Enter to continue with " << TeamnameA << " innings\n";
				_getch();
			TeamAInnings();
		}
		else if (MatchType == 2)
		{
			cout << "Match " << series << " of 3-Day series Starting\n";
			Sleep(1000);
			TeamBInnings();
			system("CLS");
			SetTarget(TeamB.Truns);
			cout << GetTarget() << " Target set for " << TeamnameA;
			cout << "\n\t\tPress Enter to continue with " << TeamnameA << " innings\n";
			_getch();
			Sleep(2000);
			TeamAInnings();
		}
		else if (MatchType == 3)
		{
			cout << "Match " << series << " of ODI Starting\n";
			Sleep(1000);
			TeamBInnings();
			system("CLS");
			SetTarget(TeamB.Truns);
			cout << GetTarget() << " Target set for " << TeamnameA;
			cout << "\n\t\tPress Enter to continue with " << TeamnameA << " innings\n";
			_getch();
			Sleep(2000);
			TeamAInnings();
		}
		else
		{
			cout << "Match " << series << " of T20 Starting\n";
			Sleep(1000);
			TeamBInnings();
			system("CLS");
			SetTarget(TeamB.Truns);
			cout << GetTarget() << " Target set for " << TeamnameA;
			cout << "\n\t\tPress Enter to continue with " << TeamnameA << " innings\n";
			_getch();
			Sleep(2000);
			TeamAInnings();
		}
	}
	Sleep(2000);
	system("CLS");
	Winner();
	cout << "Press Enter To Continue:";
	_getch();
}

void Cricket::ReplayMatch()
{
	system("CLS");
	cout << "\t\t" << TeamnameA << endl;
	TeamA.printTeam();
	Sleep(2000);
	system("CLS");
	cout << "\t\t" << TeamnameB << endl;
	TeamB.printTeam();
	Sleep(2000);
	system("CLS");
	cout << "Toss is won by " << tossWon<<endl;
	TeamA.out = 0;
	TeamA.Truns = 0;
	TeamA.num = 0;
	TeamA.balls = 0;
	TeamA.overNum = 0.0;
	TeamA.over = 0;
	TeamB.out = 0;
	TeamB.Truns = 0;
	TeamB.num = 0;
	TeamB.balls = 0;
	TeamB.overNum = 0.0;
	TeamB.over = 0;
	if (InningFirst == TeamnameA)
	{
		TeamA.SBdisplay();
		system("CLS");
		SetTarget(TeamA.Truns);
		cout << GetTarget() << " Target set for " << TeamnameB;
		cout << "\n\t\tPress Enter to continue with " << TeamnameB << " innings\n";
		_getch();
		Sleep(2000);
		TeamB.SBdisplay();
	}
	else
	{
		TeamB.SBdisplay();
		system("CLS");
		SetTarget(TeamB.Truns);
		cout << GetTarget() << " Target set for " << TeamnameA;
		cout << "\n\t\tPress Enter to continue with " << TeamnameA << " innings\n";
		_getch();
		TeamA.SBdisplay();
	}
		
	Sleep(2000);
	system("CLS");
	Winner();
	cout << "Press Enter To Continue:";
	_getch();
}

void Cricket::TeamAInnings()
{
	if (MatchType == 1)
		TeamA.TestScore(MaxOv);
	else if (MatchType == 2)
		TeamA.ThreeDScore(MaxOv);
	else if (MatchType == 3)
		TeamA.ODIScore(MaxOv);
	else
		TeamA.T20Score(MaxOv);
	TeamA.SBdisplay();
}

void Cricket::TeamBInnings()
{
	if (MatchType == 1)
		TeamB.TestScore(MaxOv);
	else if (MatchType == 2)
		TeamB.ThreeDScore(MaxOv);
	else if (MatchType == 3)
		TeamB.ODIScore(MaxOv);
	else
		TeamB.T20Score(MaxOv);
	TeamB.SBdisplay();
}

void Cricket::FirstInnings(string TeamnameA, string TeamnameB)
{
	srand(time(NULL));
	int result = rand() % 2 + 1;
	if (result == 1)
	{
		cout << " ,decided to Bat first\n";
		InningFirst = TeamnameA;
	}
	else
	{
		cout << " ,decided to Bowl first\n";
		InningFirst = TeamnameB;
	}
}

int Cricket::GetTarget()
{
	return Target;
}

void Cricket::SetTarget(int Truns)
{
	Target = Truns + 1;
}

/*void Cricket::GetScoreBoard()
{
	cout << TeamnameA << endl;
	TeamA.Scoreboard();
	Sleep(2000);
	system("CLS");
	cout << TeamnameB << endl;
	TeamB.Scoreboard();
	Sleep(2000);
	system("CLS");
}*/

void Cricket::GetBallByBall()
{
	cout << TeamnameA << endl;
	TeamA.printScore();
	Sleep(2000);
	system("CLS");
	cout << TeamnameB << endl;
	TeamB.printScore();
	Sleep(2000);
	system("CLS");
}

int Cricket::GetSeries()
{
	return series;
}

/*void Cricket::GetTestMatch()
{
	int ining=0;
	for (int day = 1; day <= 5; day++)
	{
		cout << "Day " << day;
		TeamA.TestScore(90);
		TeamB.TestScore(90);
		ining++;
	}
}*/

void Cricket::Winner()
{
	int sA = 0, sB = 0;
	if (TeamA.Truns > TeamB.Truns)
	{
		cout << "Congratulation !! to team" <<GREEN " " << TeamnameA <<" " RESET << "for winning the match" << endl;
	}
	else if (TeamA.Truns < TeamB.Truns)
	{
		cout << "Congratulation !! to team" << GREEN " " << TeamnameB << " " RESET << "for winning the match"<< endl;
	}
	else if (TeamA.Truns = TeamB.Truns)
	{
		cout << "SCORES TIE, TIME FOR SUPER OVER " << endl;
		Sleep(2000);
		system("CLS");
		TeamA.SuperOver();
		sA = TeamA.SuperOverDisplay();
		TeamB.SuperOver();
		sB = TeamB.SuperOverDisplay();
		if (sA > sB)
		{
			cout << "Congratulation !! to team" << GREEN << TeamnameA << RESET << "for winning the match in the Super Over "<< endl;
		}
		else if (sA < sB)
		{
			cout << "Congratulation !! to team" << GREEN << TeamnameB << RESET << "for winning the match in the Super Over by "<< endl;
		}
		else
		{
			cout << "Match have been declared a tie\n";
		}
	}
}

ostream& operator<<(ostream& out,const Cricket& obj)
{
	out << obj.TeamnameA << " vs " << obj.TeamnameB;
	if (obj.MatchType == 1)
		out << "\nTest";
	else if (obj.MatchType == 2)
		out << "\n3-Day";
	else if (obj.MatchType == 3)
		out << "\nODI";
	else if (obj.MatchType == 4)
		out << "\nT20";
	out << " Series Match number: " << obj.series << endl;
	return out;
}
