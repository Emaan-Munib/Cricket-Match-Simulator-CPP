#pragma once
#include <string>
#include <vector>
using namespace std;


class Fast_Scoreboad
{
public:
	int out, Truns, num, balls, MaxOvers, MatchType;
	double overNum, over;
	string Teamname;
	vector<string> team;
	vector<int> score;
	Fast_Scoreboad();
	Fast_Scoreboad(int MatchType, string Teamname);
	Fast_Scoreboad& operator()(int MatchType, string Teamname);
	void printTeam();
	void printScore();
	~Fast_Scoreboad();
};

class Match:public Fast_Scoreboad
{
public:
	Match();
	Match(int MatchType, string Teamname);
	void TestScore(int MaxOvers);
	void ThreeDScore(int MaxOvers);
	void ODIScore(int MaxOvers);
	void T20Score(int MaxOvers);
	void SuperOver();
	int SuperOverDisplay();
	void SBdisplay();
	double GetRunrate(int Totalrun);
	void displayUmpires();
	void displayComentator();
	void displayVenue();
	void displayBroadcasting();
	void displayGroundStaff();
	string toss(string TeamnameA, string TeamnameB);
	void Countdown();
};

class Team : public Match
{
protected:
	vector<int> playerScore;
	vector<double> StrikeRate;
	vector<int> BowlersOut = { 0,0,0,0,0 };
public:
	Team();
	Team(int MatchType, string Teamname);
	bool InputTeam(const string& Teamname);
	//void PlayerScore();
	//void ManOfTheMatch();
	//void Scoreboard();
	//void SetBowlersOut();
	~Team();
};

class Cricket : public Team
{
	Team TeamA;
	Team TeamB;
	string TeamnameA, TeamnameB, InningFirst ,tossWon;
	int Target,MaxOv, series;
public:
	Cricket();
	Cricket(int MatchType, string TeamnameA, string TeamnameB,int series);
	Cricket& operator()(int MatchType, string TeamnameA, string TeamnameB, int series);
	string operator[](int ind);
	friend ostream& operator<<(ostream& out,const Cricket& obj);
	void StartMatch();
	void ReplayMatch();
	void TeamAInnings();
	void TeamBInnings();
	void FirstInnings(string TeamnameA, string TeamnameB);
	int GetTarget();
	void SetTarget(int Truns);
	//void GetScoreBoard();
	void GetBallByBall();
	//void GetSummary();
	int GetSeries();
	//void GetTestMatch();
	void Winner();
};