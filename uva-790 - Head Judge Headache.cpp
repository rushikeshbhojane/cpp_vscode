#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <stdlib.h>
using namespace std;
struct TeamDetails {
    int teamNo;
    int totalProblemSolved = 0;
    int totalTimeTaken = 0;
    map <char, pair<char, int> > problems; // <problemname, <status, submissioncount>>
    TeamDetails(int _teamNo) {
        teamNo = _teamNo;

        for (int i = 0; i < 8; i++)
        {
            problems['A' + 0] = make_pair('N', 0);
        }
        
    }

    void addSubmission(char problemName, int timeConsumed, char status) {
        if (problems[problemName].first == 'Y') return;

        if (status == 'N') {
            problems[problemName].second++;
            return;
        }

        problems[problemName].first = status;

        totalTimeTaken += (timeConsumed + problems[problemName].second * 20);
        totalProblemSolved++;
    }
};

bool sortoverLoad(TeamDetails* t1, TeamDetails* t2) {
    if (t1 -> totalProblemSolved > t2 -> totalProblemSolved) {
        return true;
    } else if (t1 -> totalProblemSolved < t2 -> totalProblemSolved) {
        return false;
    }

    if (t1 -> totalTimeTaken < t2 -> totalTimeTaken) {
        return true;
    } else if (t1 -> totalTimeTaken > t2 -> totalTimeTaken) {
        return false;
    }

    return t1 -> teamNo < t2 -> teamNo;
}

int main()
{
    string line;
    map<int, TeamDetails*> teams;
    while (getline(cin, line))
    {
        if (line == "end") break; 
        int teamNo;
        char problemName, status;
        int hrs, mins;
        sscanf(line.c_str(), "%d %c %d:%d %c", &teamNo, &problemName, &hrs, &mins, &status);
        if (teams.find(teamNo) == teams.end()) {
            teams[teamNo] = new TeamDetails(teamNo);
        }

        int timeTaken = hrs*60 + mins;

        
        teams[teamNo] -> addSubmission(problemName, timeTaken, status);        
    }
    
    vector<TeamDetails*> teamArray;
    for (auto it = teams.begin(); it != teams.end(); ++it)
    {
        teamArray.push_back(it -> second);
    }
    sort(teamArray.begin(), teamArray.end(), sortoverLoad);

    int rank = 0;
    printf("RANK TEAM PRO/SOLVED TIME\n");
    for (TeamDetails* t: teamArray) {
        rank++;
        printf("%4d ", rank);
        printf("%4d ", t -> teamNo);
        printf("%3s%c%6s ", "",  (t -> totalProblemSolved != 0 ? '0' +  t -> totalProblemSolved  : ' '), "");
        if (t -> totalTimeTaken !=  0)
            printf("%4d", t -> totalTimeTaken);
        else
            printf("%4s", "");
        printf("\n");
    }

    return 0;
}