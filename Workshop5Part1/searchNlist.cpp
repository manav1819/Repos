
#include <iostream>
#include "searchNlist.h"
using namespace std;

namespace sdds {

    /*template <typename CollectionType, typename ArrayType, typename KeyType>
    bool searchNlist<CollectionType, ArrayType, KeyType>::search(const CollectionType& collection, const ArrayType* array, size_t arraySize, const KeyType& key, std::vector<ArrayType>& matches) {
        bool found = false;
        for (size_t i = 0; i < arraySize; ++i) {
            if (array[i] == key) {
                found = true;
                matches.push_back(array[i]);
            }
        }
        return found;
    }
    template <typename CollectionType, typename ArrayType, typename KeyType>
    void searchNlist<CollectionType, ArrayType, KeyType>::listArrayElements(const char* title, const ArrayType* array, int numElements)
    {
        cout << title << endl;

        for (int i = 0; i < numElements; ++i) {
            cout << i + 1 << ": " << array[i] << endl;
        }
    }
    template <typename T1, typename T2>
    bool search(Collection<T1>& collection, T1* array, int size, T2 key) {
        bool found = false;
        for (int i = 0; i < size; ++i) {
            if (array[i] == key) {
                collection.add(array[i]);
                found = true;
            }
        }
        return found;
    }

    template<typename T1>
    void listArrayElements(const char* title, const T1* array, int size)
    {
        cout << title << endl;
        for (int i = 0; i < size; ++i) {
            cout << (i + 1) << ": " << array[i] << endl;
        }
    }*/
}