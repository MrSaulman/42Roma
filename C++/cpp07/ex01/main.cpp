#include "iter.hpp"

int main( void ) {
    int arr[] = {1, 5, 9, 12, 35};
    std::string arr2[] = {"Ciao", "Bro", "Come", "Va", "?"};

    ::iter(arr, 5, func);
    ::iter(arr2, 4, func); //no stampa giustamente "?""
    return 0;
}
