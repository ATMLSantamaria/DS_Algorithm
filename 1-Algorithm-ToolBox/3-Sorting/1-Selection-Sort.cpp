#include <vector>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <assert.h>
#include "aux.h"

void SelectionSort(std::vector<int> &A){
    //int minIndex=0;
    int n=A.size();
    int tmp=0;
    int minIndex=0;
    for (int i=0;i<n;++i){
        minIndex=i;
        for (int j=i+1;j<n;++j){
            if (A[j]<A[minIndex]){
                minIndex=j;
            }
        }
        //Swap
        tmp = A[i];
        A[i]=A[minIndex];
        A[minIndex]=tmp;
    }
}

int main(){
    std::vector<int> v;
    ramdomize_vector(v,10);
    printVector(v);


    std::vector<int> v1={2,1,3,4,4,1,0,10,100};

    SelectionSort(v1);
   // printVector(v1);
    std::sort(v1.begin(),v1.end());
    //printVector(v1);


    std::vector<int> v_copy{v};

    SelectionSort(v);
    std::sort(v_copy.begin(),v_copy.end());
    for (int k=0;k!=v_copy.size();++k){
        assert(v[k]==v_copy[k]);
    }
}