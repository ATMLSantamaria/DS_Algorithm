#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <array>

void printVector(std::vector<int> &v){
    std::cout << "{";
    for (auto &i : v){
        std::cout << i << " ";
    }
    std::cout << "}\n";
}
template<std::size_t S>
void printArray(std::array<int,S> &v){
    std::cout << "{";
    for (auto &i : v){
        std::cout << i << " ";
    }
    std::cout << "}\n";
}

void ramdomize_vector(std::vector<int> &V,int new_size){
    std::srand(unsigned(std::time(nullptr)));
    V.resize(new_size);
    std::generate(V.begin(), V.end(), std::rand);
}