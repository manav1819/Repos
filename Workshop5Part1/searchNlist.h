/*
 *****************************************************************
 * Name: Manav Patel                                             *
 * Email: patmanav@sheridancollege.ca                            *
 * Student Id: 991500582                                         *
 * Date: 12-10-2023                                              *
 *                                                               *
 *****************************************************************
*/

#include "Collection.h"
#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_
using namespace std;

namespace sdds {

    template <typename T1, typename T2>
    class searchNlist {
        
    public:
        bool search(Collection<T1>& collection, T1* array, int size, T2 key);
        void listArrayElements(const char* title, const T1* array, int size);
    };
   

    template<typename T1, typename T2>
    bool searchNlist<T1, T2>::search(Collection<T1>& collection, T1* array, int size, T2 key)
    {
        bool found = false;
        for (int i = 0; i < size; ++i) {
            if (array[i] == key) {
                collection.add(array[i]);
                found = true;
            }
        }
        return found;
    }

    template<typename T1, typename T2>
    void searchNlist<T1, T2>::listArrayElements(const char* title, const T1* array, int size)
    {
        std::cout << title << endl;
        for (int i = 0; i < size; ++i) {
            cout << (i + 1) << ": " << array[i] << endl;
        }
    }

}
#endif // !SDDS_SEARCHNLIST_H_