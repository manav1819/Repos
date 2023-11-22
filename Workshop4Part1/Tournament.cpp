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
#include <cstring>
#include <iomanip>
#include "Tournament.h"

Tournament::Tournament() {
    setEmpty();
}

Tournament::Tournament(const char* name, int noOfteam, const SoccerTeam* soccer) {
    setTournament(name, noOfteam, soccer);
}

Tournament::~Tournament() {
    delete[] m_name;
    delete[] m_soccer;
}

void Tournament::setTournament(const char* name, int noOfteam, const SoccerTeam* soccer) {
    if (name != nullptr && noOfteam > 0) {
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
        m_num = noOfteam;
        m_soccer = new SoccerTeam[noOfteam];
        for (int i = 0; i < noOfteam; i++) {
            m_soccer[i].setTeam(soccer[i]);
        }
    }
    else {
        setEmpty();
    }
}

void Tournament::setEmpty() {
    m_name = nullptr;
    m_num = 0;
    m_soccer = nullptr;
}

bool Tournament::isEmpty() const {
    return m_name != nullptr && m_num > 0;
}

Tournament& Tournament::match(SoccerTeam* ls) {
    //if (!isEmpty() && ls != nullptr) {
        for (int i = 0; i < m_num; i++) {
            if (isEmpty()) {
            for (int j = i + 1; j < m_num; j++) {
                if (m_soccer[i].fouls() < ls[j].fouls()) {
                    m_soccer[j].setFine(m_soccer[j].fines()*1.2, m_soccer[j].fouls() * 2);
                    m_soccer[i].setGoals(m_soccer[i].goals()+1);
                }
                else {
                    m_soccer[i].setFine((m_soccer[i].fines()*1.2), (m_soccer[i].fouls() * 2));
                    m_soccer[j].setGoals(m_soccer[j].goals()+1);
                }

                if (ls[i].fouls() > MAX_FOUL) {
                    ls[i].setEmpty();
                }
                if (ls[j].fouls() > MAX_FOUL) {
                    ls[j].setEmpty();
                }
            }
        }
    }
    return *this;
}

std::ostream& Tournament::display() const {
    std::ostream& os = std::cout;
    if (isEmpty()) {
        os << "Tournament name: " << m_name << std::endl;
        os << "list of the teams" << std::endl;
        os << std::right << std::setw(46) << "Fines";
        os << std::setw(10) << "Fouls";
        os << std::setw(10) << "Goals" << std::endl;

        for (int i = 0; i < m_num; i++) {
            os << "Team[" << i + 1 << "] : " ;
            m_soccer[i].display();
            os << std::endl;
        }
        
    }
    else {
        os << "Invalid Tournament";
    }
    return os;
}
