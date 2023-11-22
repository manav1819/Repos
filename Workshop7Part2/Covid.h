#ifndef SDDS_COVID_H
#define SDDS_COVID_H

#include <string>
#include <optional>

namespace sdds {

    enum class Status {
        EPIDEMIC,
        EARLY,
        MILD,
        GENERAL
    };

    struct Covid {
        std::string country;
        std::string city;
        std::string variant;
        int year;
        unsigned int cases;
        unsigned int deaths;
        Status status;
    };

    std::ostream& operator<<(std::ostream& out, const Covid& theCovid);

}

#endif 