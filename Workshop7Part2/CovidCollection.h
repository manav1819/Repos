/*
 *****************************************************************
 * Name: Manav Patel                                             *
 * Email: patmanav@sheridancollege.ca                            *
 * Student Id: 991500582                                         *
 * Date: 23-09-2023                                              *
 *                                                               *
 *****************************************************************
*/


#ifndef SDDS_COVIDCOLLECTION_H
#define SDDS_COVIDCOLLECTION_H

#include <iostream>
#include <vector>
#include <list>
#include <iomanip>

namespace sdds {
    struct Covid {
        std::string country;
        std::string city;
        std::string variant;
        int year=0;
        unsigned int cases=0;
        unsigned int deaths=0;
        std::string status;
    };

    class CovidCollection {
    private:
        std::vector<Covid> collection;

    public:
        CovidCollection(const char* filename);
        void display(std::ostream& out, const std::string& country = "ALL") const;
        void sort(const std::string& field = "country");
        bool inCollection(const std::string& variant, const std::string& country, unsigned int deaths) const;
        std::list<Covid> getListForDeaths(unsigned int deaths) const;
        void updateStatus();
        void displayGlobalTotals(std::ostream& out) const;
    };

    std::ostream& operator<<(std::ostream& out, const Covid& theCovid);
} // namespace sdds

#endif // SDDS_COVIDCOLLECTION_H