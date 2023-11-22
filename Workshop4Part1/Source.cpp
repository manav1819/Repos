/*
 *****************************************************************
 * Name: Manav Patel                                             *
 * Email: patmanav@sheridancollege.ca                            *
 * Student Id: 991500582                                         *
 * Date: 12-10-2023                                              *
 *                                                               *
 *****************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "soccerTeam.h"
#include "Tournament.h"
using namespace std;

int main() {
    /*string team1name, team2name;
    double team1fines=0.0, team2fines=0.0;
    int team1fouls = 0, team2fouls = 0;

    cout<<"Enter team1 Name:";
    cin >> team1name;
    cout<<"Enter team3 Name:"
    cin >> team2name;
    */

    SoccerTeam team1("Scarborough Soccer Team", 120.00, 3);
    SoccerTeam team2("North York Soccer Team", 20.00, 1);

    SoccerTeam teams[] = { team1, team2 };

    Tournament tournament;
    tournament.setTournament("Soccer Tournament", 2, teams);

    cout << "Tournament Information:\n";
    Tournament ls; 
    tournament.match(teams); 

    cout << "Updated Tournament Information:\n";
    tournament.display();

    return 0;
}
