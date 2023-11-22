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
#ifndef SOCCERTEAM_H
#define SOCCERTEAM_H
#include<iostream>

const int MAX_FOUL = 4;

class SoccerTeam {

    char m_teamName[41];
    int m_noFouls;
    double m_fines;
    int m_goals;

public:
    SoccerTeam();
    SoccerTeam(const char* tname, double fines, int foul);
    void setTeam(const SoccerTeam& team);
    void setName(const char* tname);
    void setFine(double fines, int foul);
    void setGoals(int goals);
    void setEmpty();
    bool isEmpty() const;
    void calFines();
    int fouls() ;
    int goals() ;
    double fines() ;
    std::ostream& display() const;
    

};

#endif
