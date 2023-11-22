// Covid.h
#ifndef COVID_H
#define COVID_H

#include <string>

namespace sdds {
    struct Covid {
        std::string country;
        std::string city;
        std::string variant;
        int year;
        unsigned int cases;
        unsigned int deaths;
    };

    std::ostream& operator<<(std::ostream& out, const Covid& theCovid);
} // namespace sdds

#endif // COVID_H
