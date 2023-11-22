
#include "Covid.h"
#include <iomanip>

namespace sdds {
    std::ostream& operator<<(std::ostream& out, const Covid& theCovid) {
        out << "| " << std::setw(23) << theCovid.country << " | "
            << std::setw(17) << theCovid.city << " | "
            << std::setw(22) << (theCovid.variant.empty() ? "[None]" : theCovid.variant) << " | "
            << std::setw(8) << theCovid.year << " | "
            << std::setw(6) << theCovid.cases << " | "
            << std::setw(5) << theCovid.deaths << " |" << std::endl;

        return out;
    }
} 
