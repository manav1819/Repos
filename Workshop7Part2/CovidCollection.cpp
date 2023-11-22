/*
 *****************************************************************
 * Name: Manav Patel                                             *
 * Email: patmanav@sheridancollege.ca                            *
 * Student Id: 991500582                                         *
 * Date: 23-09-2023                                              *
 *                                                               *
 *****************************************************************
*/

#include "CovidCollection.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

namespace sdds {
    std::string filtering(const std::string& str) {
        auto first = std::find_if_not(str.begin(), str.end(), [](unsigned char c) {
            return std::isspace(c);
            });

        auto last = std::find_if_not(str.rbegin(), str.rend(), [](unsigned char c) {
            return std::isspace(c);
            });

        return std::string(first, last.base());
    }

    CovidCollection::CovidCollection(const char* filename) {
        std::ifstream file(filename);
        if (!file) {
            throw std::invalid_argument("Invalid file name");
        }

        std::string line;
        while (std::getline(file, line)) {
            //std::istringstream ss(line);
            Covid entry;
            entry.country = filtering(line.substr(0, 25));
            entry.city = filtering(line.substr(25, 25));
            entry.variant = filtering(line.substr(50, 25));
            entry.year = std::stoi(filtering(line.substr(75, 5)));
            entry.cases = std::stoul(filtering  (line.substr(80, 5)));
            entry.deaths = std::stoul(filtering(line.substr(85, 5)));
            entry.status = "General";

            collection.push_back(entry);
        }
    }

    void CovidCollection::display(std::ostream& out, const std::string& country) const {
        std::for_each(collection.begin(), collection.end(), [&out, &country](const Covid& covid) {
            if (country == "ALL" || covid.country == country) {
                out << covid;
            }
            });

        unsigned int totalCases = 0, totalDeaths = 0;
        for (const auto& covid : collection) {
            if (country == "ALL" || covid.country == country) {
                totalCases += covid.cases;
                totalDeaths += covid.deaths;
            }
        }

        out << "| " << std::right << std::setw(76) << "Total cases around the world:" << std::right << std::setw(8) << totalCases << " |\n";
        out << "| " << std::right << std::setw(77) << "Total deaths around the world:" << std::right << std::setw(7) << totalDeaths << " |\n";
        
    }

    void CovidCollection::sort(const std::string& field) {
        std::sort(collection.begin(), collection.end(), [field](const Covid& a, const Covid& b) {
            if (field == "country") {
                return a.country < b.country || (a.country == b.country && a.deaths < b.deaths);
            }
            else if (field == "city") {
                return a.city < b.city || (a.city == b.city && a.deaths < b.deaths);
            }
            else if (field == "variant") {
                return a.variant < b.variant || (a.variant == b.variant && a.deaths < b.deaths);
            }
            else if (field == "year") {
                return a.year < b.year || (a.year == b.year && a.deaths < b.deaths);
            }
            else if (field == "cases") {
                return a.cases < b.cases || (a.cases == b.cases && a.deaths < b.deaths);
            }
            else if (field == "deaths") {
                return a.deaths < b.deaths;
            }
            else if (field == "severity") {
                return a.status < b.status|| (a.status == b.status && a.deaths < b.deaths);
            }
            return false;
            });
    }

    bool CovidCollection::inCollection(const std::string& variant, const std::string& country, unsigned int deaths) const {
        return std::any_of(collection.begin(), collection.end(), [&variant, &country, &deaths](const Covid& covid) {
            return covid.variant == variant && covid.country == country && covid.deaths > deaths;
            });
    }

    std::list<Covid> CovidCollection::getListForDeaths(unsigned int deaths) const {
        std::list<Covid> result;
        std::copy_if(collection.begin(), collection.end(), std::back_inserter(result), [deaths](const Covid& covid) {
            return covid.deaths >= deaths;
            });
        return result;
    }

    void CovidCollection::displayGlobalTotals(std::ostream& out) const {
        unsigned int totalCases = 0, totalDeaths = 0;
        for (const auto& covid : collection) {
            totalCases += covid.cases;
            totalDeaths += covid.deaths;
        }

    }

    void CovidCollection::updateStatus() {
        std::transform(collection.begin(), collection.end(), collection.begin(), [](Covid& covid) {
            if (covid.deaths > 300) {
                covid.status = "EPIDEMIC";
            }
            else if (covid.deaths < 50) {
                covid.status = "EARLY";
            }
            else {
                covid.status = "MILD";
            }
            
            return covid;
            });
    }

    std::ostream& operator<<(std::ostream& out, const Covid& theCovid) {
        out << "| " << std::left << std::setw(22) << theCovid.country
            << "| " << std::setw(16) << theCovid.city
            << "| " << std::setw(21) << theCovid.variant
            << "| " << std::setw(7) << theCovid.year
            << "| " << std::setw(5) << theCovid.cases
            << "| " << std::setw(4) << theCovid.deaths 
            << "| " << std::setw(8) << theCovid.status << "|\n";
        return out;
    }
} // namespace sdds