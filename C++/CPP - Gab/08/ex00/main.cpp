#include <iostream>
#include <vector>
//#include <array>
#include <queue>
#include "easyfind.hpp"

int main() {
    int n = 3;

    /*std::array<int, 3> a = {1,2,3};
    
    std::cout << "Array: " << easyfind(a, 2) << std::endl;
    std::cout << "Array: " << easyfind(a, 4) << std::endl;
    std::cout << std::endl;*/

    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
        v.push_back(i);
    std::cout << "Vector: " << easyfind(v, 1) << std::endl;
    std::cout << "Vector: " << easyfind(v, -1) << std::endl;
    std::cout << std::endl;

    std::deque<int> q;
    for (int i = 0; i < n; i++)
        q.push_back(i);
    std::cout <<  "Deque: " << easyfind(q, 1) << std::endl;
    std::cout <<  "Deque: " << easyfind(q, -1) << std::endl;
    std::cout << "Test pushback: " << q[0] << q[1] << q[2] << std::endl;
    return 0;
}