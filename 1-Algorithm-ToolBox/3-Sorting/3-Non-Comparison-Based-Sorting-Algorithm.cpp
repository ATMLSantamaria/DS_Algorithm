#include <assert.h>
#include "aux.h"
#include <vector>
#include <iostream>
#include <array>
#include <algorithm>
/*
    Simple Implentation of a Count Sort Algorithm For Integers.
    
    Future optimization for large numbers. Currently too big arrays are generated
*/

std::vector<int> CountSort(std::vector<int> &A,int M){
    int n = A.size();

    int min=1;

    // 0 Step, if we dont know the upper constrain we need to scan for the biggest element M.
    if (M==0){
        auto it_max = std::max_element(A.begin(),A.end());
        M = *it_max;
        auto it_min = std::min_element(A.begin(),A.end());
        min =*it_min;
    }

    // 1st - Create and Initialize a Count Array
    std::vector<int> Count(M,0); //Initialize to 0. C++11 feature

    // 2nd - Go across A and count elements
    for (int i=0;i<n;++i){
        Count[A[i]]++;
    }

    // 3rd - Create and Initializa a Pos Array where we will store start position of each value
    std::vector<int> Pos(M,0);
    // In the first position of the array will be stored 1, as it will be the minimum value
    Pos[0]=min;
    
    //Simple to understand. When j=2 for know the Pos where to place 2 we have to add the number (Count) of 1 to the Pos where 1 starts
    for (int j=++min;j<=M;++j){

    //for (int j=2;j<=M;++j){
        Pos[j]=Pos[j-1]+Count[j-1]; 
    }

    // 4th - Copy Elements from Array A to the destination Array. It is important to copy because normally the ints are just keys of more complex objects.
    std::vector<int> res(A.size());
    for (int i=0;i<n;++i){
        res[Pos[A[i]]]=A[i];
        Pos[A[i]]=Pos[A[i]]+1;
    }

    return res;

}


int main(){
    std::vector<int> v;
    ramdomize_vector(v,10);
    // printVector(v);
    std::vector<int> v1{2,3,1,5,7,6,3,5,7};
    std::vector<int> v_copy{v1};

    std::vector<int> res=CountSort(v1,7);
    printVector(res);
    std::sort(v_copy.begin(),v_copy.end());
    printVector(v_copy);

    printVector(v);
    std::vector<int> res2=CountSort(v,0);
    std::sort(v.begin(),v.end());
    for (int h=0;h<v_copy.size();++h){
        assert(res2[h]==v[h]);
        //if(v_copy[h]!=v[h]){std::cout <<"ERROR\n";}
    }

}