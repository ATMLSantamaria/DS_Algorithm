#include <assert.h>
#include <vector>
#include <iostream>
#include "aux.h"
#include <array>
/*
    Simple Implementation of QuickSort
    -Use a Function Template allows us to use std::array instead of vector. This is unecessary but I will do it just for variety. In all previous
    examples I used vector so uses array now is more fun. Of course there is also a small increase of performance, although 
    in a real application this would probably be an unnecesary microoptimization
*/
template<std::size_t S>
int Partition(std::array<int,S> &A,int l,int r){
    //Pivot
    int x = A[l];
    int j =l;
    //Tmp for swap
    int tmp;
    //Create the 2 groups, smaller and bigger than pivot
    for (int i=l+1;i<=r;++i){
        if (A[i]<=x){
            j++; //increase size of smaller than pivot group
            //Move A[i] to the new created position
            tmp = A[j]; //Keep the value that was in that position originally
            A[j]=A[i];//swap
            A[i]=tmp;
        }
    }
    //Move the pivot to its final position, between the 2 gropus
    tmp=A[j];
    A[j]=A[l];
    A[l]=tmp;

    return j;
}


template<std::size_t SIZE>
void QuickSort(std::array<int,SIZE> &A,int l,int r){
    if (l >= r){
        return;
    }
    int m = Partition(A,l,r);
    QuickSort(A,l,m-1);
    QuickSort(A,m+1,r);
}



int main(){

    //Manual Vector
    std::vector<int> v_man{2,3,1,5,7,6,3,5,7};
    std::vector<int> v_compare{v_man};

    std::array<int,10> arr={3,4,1,2,9,5,7,8,9,2};
    std::array<int,10> arr_cpy{arr};

    QuickSort(arr,0,9);
    printArray(arr);

    //STD Library sort to compare
    std::sort(arr_cpy.begin(),arr_cpy.end());

   
   //Assertion
    for (int h=0;h<arr_cpy.size();++h){
        assert(arr[h]==arr_cpy[h]);
    }

}