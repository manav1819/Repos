// CovidCollection.cpp
#include "CovidCollection.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>

namespace sdds {
    CovidCollection::CovidCollection(const char* filename) {
        // Read data from the file and populate the collection using STL algorithms
        // ...

        // Example: Using std::for_each and a lambda to read data from the file
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::invalid_argument("Invalid file name");
        }

        std::for_each(std::istream_iterator<std::string>(file), std::istream_iterator<std::string>(), [&](const std::string& token) {
            try {
                std::istringstream ss(token);

                // Example processing:
                std::string country, city, variant;
                int year;
                unsigned int cases, deaths;

                std::string line;
                while (std::getline(file, line)) {
                    // Use std::istringstream to process the line
                    std::istringstream ss(line);

                    // Example processing:
                    /*ss >> std::setw(27) >> std::skipws >> country
                        >> std::setw(27) >> std::skipws >> city
                        >> std::setw(22) >> std::skipws >> variant
                        >> year >> cases >> deaths;*/

                        // Example processing:
                    ss >> std::setw(27) >> std::skipws >> country;
                    ss >> std::setw(27) >> std::skipws >> city;
                    ss >> std::setw(22) >> std::skipws >> variant;
                    ss >> year >> cases >> deaths;

                    // Add the processed data to the collection
                    collection.push_back({ country, city, variant, year, cases, deaths });
                    std::cerr << "Parsed values: " << country << ", " << city << ", " << variant << ", " << year << ", " << cases << ", " << deaths << std::endl;

                }


                

            }
            catch (const std::exception& e) {
                // Handle the exception (print an error message, log it, etc.)
                std::cerr << "Error processing token: " << e.what() << std::endl;
                std::cerr << "Faulty token: " << token << std::endl;  // Add this line for debugging

            }
            });


        file.close();
    }

    void CovidCollection::display(std::ostream& out) const {
        // Display the collection using std::for_each and a lambda
        std::for_each(collection.begin(), collection.end(),
            [&](const Covid& c) {
                out << c; // Assuming you've implemented the operator<< for Covid
            });
    }
} // namespace sdds
