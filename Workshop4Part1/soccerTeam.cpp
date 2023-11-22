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
#include <iomanip>  //used for string concat, precision etc!!
#include "SoccerTeam.h"

SoccerTeam::SoccerTeam() {
    setEmpty();
}

SoccerTeam::SoccerTeam(const char* tname, double fines, int foul) {
    if (tname != nullptr && fines >= 0 && foul >= 0) {
        setName(tname);
        setFine(fines, foul);
        m_goals = 0;
    }
    else {
        setEmpty();
    }
}

void SoccerTeam::setTeam(const SoccerTeam& team) {
    setName(team.m_teamName);
    setFine(team.m_fines, team.m_noFouls);
    m_goals = team.m_goals;
}

void SoccerTeam::setName(const char* tname) {
    if (tname != nullptr) {
        strncpy(m_teamName, tname, 40);
        m_teamName[40] = '\0'; // null-termination
    }
}

void SoccerTeam::setFine(double fines, int foul) {
    if (fines >= 0 && foul >= 0) {
        m_fines = fines;
        m_noFouls = foul;
    }
    else {
        setEmpty();
    }
}

void SoccerTeam::setEmpty() {
    m_teamName[0] = '\0';
    m_fines = 0;
    m_noFouls = 0;
    m_goals = 0;
}

bool SoccerTeam::isEmpty() const {
    return m_teamName[0] != '\0' && m_fines >= 0 && m_noFouls >= 0 && m_noFouls < MAX_FOUL;
}

void SoccerTeam::calFines() {
    m_fines *= 1.2;
}

int SoccerTeam::fouls()  {
    return m_noFouls;
}


void SoccerTeam::setGoals(int goals) {
    m_goals = goals;
}

std::ostream& SoccerTeam::display() const {
        std::ostream& os = std::cout;
        if (isEmpty()) {
            os << std::flush << std::left << std::setw(31) << m_teamName << std::flush;
            os << std::fixed << std::setprecision(2) << std::setw(10) << m_fines << std::flush;
            os << std::setw(10) << m_noFouls << std::flush;
            os << std::setw(10) << m_goals << std::flush;
            if (m_goals > 0)
                os << "w";
        }
        else {
            os << "Invalid Team";
        }
    
    return os;
}



int SoccerTeam::goals() 
{
    return m_goals;
}

double SoccerTeam::fines() 
{
    return m_fines;
}



