// CovidCollection.h
#ifndef COVID_COLLECTION_H
#define COVID_COLLECTION_H

#include <vector>
#include <iostream>
#include "Covid.h"

namespace sdds {
    class CovidCollection {
        std::vector<Covid> collection;

    public:
        CovidCollection(const char* filename);
        void display(std::ostream& out) const;
    };
} // namespace sdds

#endif // COVID_COLLECTION_H
