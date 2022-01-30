#include <assert.h>
#include "aux.h"
#include <vector>
#include <iostream>

/*
    Simple Implementation of Merge Sort
*/


std::vector<int> Merge(std::vector<int> &B, std::vector<int> &C){
    std::vector<int> D(B.size()+C.size());
    int current_b=0,current_c=0,current_d=0;
    while((current_b<B.size()) && (current_c<C.size())){
        int b = B[current_b];
        int c = C[current_c];
        if(b<=c){
            D[current_d]=B[current_b];
            current_b++;
        } else {
            D[current_d]=C[current_c];
            current_c++;
        }
        current_d++;
    }
    if(current_b==B.size()){
        while(current_c<C.size()){
            D[current_d]=C[current_c];
            current_c++;
            current_d++;
        }
    } else if (current_c==C.size()){
        while(current_b<B.size()){
            D[current_d]=B[current_b];
            current_b++;
            current_d++;
        }
    }
    return D;

}

std::vector<int> MergeSort(std::vector<int> &A){
    // Base Class
    int n=A.size();
    if (n==1){
        return A;
    }
    //Split Array
    int m=n/2;
    std::vector<int> A1{A.begin(),A.begin()+m};
    std::vector<int> A2{A.begin()+m,A.end()};

    //std::vector<int> B = MergeSort({A.begin(),A.begin()+m});
    std::vector<int> B = MergeSort(A1);
    std::vector<int> C = MergeSort(A2);

    //std::vector<int> AA=Merge(B,C);
    A=Merge(B,C);
    // return AA;
    return A;
}

int main(){
    std::vector<int> v;
    ramdomize_vector(v,100000);
    std::vector<int> v_copy{v};
    // printVector(v);
    std::vector<int> v1{2,3,1,5,7,6,3,5,7};
    std::vector<int> res=MergeSort(v1);
    printVector(res);
    printVector(v1);

    MergeSort(v);
    std::sort(v_copy.begin(),v_copy.end());
    
    for (int h=0;h<v_copy.size();++h){
        assert(v_copy[h]==v[h]);
        //if(v_copy[h]!=v[h]){std::cout <<"ERROR\n";}
    }

}