#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>


void printVector(std::vector<int> &v){
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