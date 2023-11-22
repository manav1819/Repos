
#include "Covid.h"
#include <iomanip>

namespace sdds {

    std::ostream& operator<<(std::ostream& out, const Status& status) {
        switch (status) {
        case Status::GENERAL:
            out << "GENERAL";
            break;
        case Status::EARLY:
            out << "EARLY";
            break;
        case Status::MILD:
            out << "MILD";
            break;
        case Status::EPIDEMIC:
            out << "EPIDEMIC";
            break;
        }
        return out;
    }
    std::ostream& operator<<(std::ostream& out, const Covid& theCovid) {
        out << "| " << std::setw(21) << theCovid.country << " | "
            << std::setw(17) << std::left << theCovid.city << " | "
            << std::setw(19) << std::left << (theCovid.variant.empty() ? "[None]" : theCovid.variant) << " | "
            << std::setw(6) << theCovid.year << " | "
            << std::setw(4) << theCovid.cases << " | "
            << std::setw(3) << theCovid.deaths << " |"
            << " | " << std::setw(8) << theCovid.status << " |" << std::endl;

        return out;
    }

}
