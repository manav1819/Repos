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
#ifndef TOURNAMENT_H
#define TOURNAMENT_H
#include<iostream>
#include "SoccerTeam.h"

class Tournament {

    char* m_name;
    int m_num;
    SoccerTeam* m_soccer;

public:
    Tournament(); //default constructor
    Tournament(const char* name, int noOfteam, const SoccerTeam* soccer); //overloaded constructor
    void setTournament(const char* name, int noOfteam, const SoccerTeam* soccer);
    void setEmpty();
    bool isEmpty() const;
    Tournament& match(SoccerTeam* ls);
    std::ostream& display() const;
    ~Tournament(); // destructor
};

#endif
