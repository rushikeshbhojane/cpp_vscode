#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <map>
using namespace std;
struct  TeamDetails
{
    char name[100];
    int games, points;
    int won, tie, loss;
    int scored, against;
    TeamDetails(const char _name[])
    {
        strcpy(name, _name);
        games = 0;
        points = 0;
        won = 0;
        tie = 0;
        loss = 0;
        scored = 0;
        against = 0;
    }

    void calcPoints() {
        points  = won * 3 + tie * 1;
    }
};

bool sortFunction(TeamDetails* t1, TeamDetails* t2)
{
    if (t1 -> points > t2 -> points) {
        return true;
    } else if (t2 -> points > t1 -> points) {
        return false;
    }

    
    if (t1 -> won > t2 -> won) {
        return true;
    } else if (t2 -> won > t1 -> won) {
        return false;
    }

    if ((t1 -> scored - t1 -> against) > (t2 -> scored - t2 -> against)) {
        return true;
    } else if ((t2 -> scored - t2 -> against) > (t1 -> scored - t1 -> against)) {
        return false;
    }

    if (t1 -> scored > t2 -> scored) {
        return true;
    } else if (t2 -> scored > t1 -> scored) {
        return false;
    }

    if (t1 -> games < t2 -> games) {
        return true;
    } else if (t2 -> games < t1 -> games) {
        return false;
    }

    if (strcasecmp(t1 -> name , t2 -> name) < 0) {
        return true;
    } else {
        return false;
    }
}


int main()
{
    string line;
    int tournaments;
    getline(cin, line);
    sscanf(line.c_str(), "%d", &tournaments);

    while (tournaments--)
    {
        /* code */
        map<string, TeamDetails*> m;
        vector<TeamDetails*> tArr;
        string tournamentName;
        getline(cin, tournamentName);

        getline(cin, line);
        int teamCount;
        sscanf(line.c_str(), "%d", &teamCount);

        for (int i = 0; i < teamCount; i++)
        {
            string teamName;
            getline(cin, teamName);
            m[teamName] = new TeamDetails(teamName.c_str());
        }
        

        getline(cin, line);
        int matchesCount;
        sscanf(line.c_str(), "%d", &matchesCount);


        for (int i = 0; i < matchesCount; i++)
        {
            getline(cin, line);
            char team1Temp[100], team2Temp[100];
            int team1goals, team2goals;
            sscanf(line.c_str(), "%[^#]#%d@%d#%[^\n]\n", team1Temp, &team1goals, &team2goals, team2Temp);

            string team1(team1Temp);
            string team2(team2Temp);

            m[team1] -> games++;
            m[team2] -> games++;

            m[team1] -> scored += team1goals;
            m[team2] -> scored += team2goals;

            m[team1] -> against += team2goals;
            m[team2] -> against += team1goals;

            if (team1goals > team2goals) {
                m[team1] -> won++;
                m[team2] -> loss++;
            } else if (team2goals > team1goals)  {
                m[team2] -> won++;
                m[team1] -> loss++;
            } else {
                m[team2] -> tie++;
                m[team1] -> tie++;
            }

            m[team1] -> calcPoints();
            m[team2] -> calcPoints();
        }

        for (auto it = m.begin(); it != m.end(); it++)
        {
            tArr.push_back(it -> second);
        }
        
        sort(tArr.begin(), tArr.end(), sortFunction);

        int rank = 0;

        printf("%s\n", tournamentName.c_str());
        for (TeamDetails* t: tArr)
        {
            rank++;
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
                    rank, t -> name,  t -> points, t-> games,
                    t -> won, t -> tie, t -> loss,
                    t -> scored - t-> against, t -> scored , t-> against);
        }

        if (tournaments) {
            printf("\n");
        }
        
    }
    
    return 0;
}