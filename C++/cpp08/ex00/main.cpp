#include <iostream>
#include <vector>
#include <iterator>
//#include <array>
#include <queue>
#include "easyfind.hpp"

int main() {
    int n = 7;

    /*std::array<int, 3> a = {1,2,3};
    
    std::cout << "Array: " << easyfind(a, 2) << std::endl;
    std::cout << "Array: " << easyfind(a, 4) << std::endl;
    std::cout << std::endl;*/

    std::vector<int> v;
    for (int i = 0; i < n; i++)
        v.push_back(i);
    std::cout << "Vector: ";
    for (std::vector<int>::const_iterator i = v.begin(); i != v.end(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;
    std::cout << "Search 1: " << easyfind(v, 5) << std::endl;
    std::cout << "Search -1: " << easyfind(v, -5) << std::endl;
    std::cout << std::endl;

    std::deque<int> q;
    for (int i = 0; i < n; i++)
        q.push_back(i);
    std::cout <<  "Search 1: " << easyfind(q, 6) << std::endl;
    std::cout <<  "Search -1: " << easyfind(q, -6) << std::endl;
    // std::cout << "Test pushback: " << q[0] << q[1] << q[2] << std::endl;
    return 0;
}