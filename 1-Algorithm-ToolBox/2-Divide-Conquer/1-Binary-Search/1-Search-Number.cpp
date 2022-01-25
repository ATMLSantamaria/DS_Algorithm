#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <assert.h>

int BinarySearch(std::vector<int> A, int low,int high,int key){
    //Base Case
    if(high < low){
        return low-1; //Arrive to the end of search and element not found
    }
    //Middle Point, or round to the lower if is odd
    int mid = low+(high-low)/2;

    //Base Case
    if (key==A[mid]){
    
        return mid; //Mid is the index we searched for

    } else if(key>A[mid]){ //Key is bigger than mid point -> search in the right

        return BinarySearch(A,mid+1,high,key);

    } else {
        return BinarySearch(A,low,mid-1,key);

    }

}

int main(){

    std::vector<int> a{1,3,2,0,4,5,2,8,5,33,1,100,4};

    std::sort(a.begin(),a.end());

    for (auto &i: a){
        std::cout << i<< ' ';
    }
    std::cout << std::endl;
    int j = BinarySearch(a,0,a.size()-1,8);
    std::cout << "En el Ordered Vector 8 esta en Index=" << BinarySearch(a,0,a.size()-1,8) << std::endl;

    //Test result against Linear Search
    int i;
    for (i=0;i<a.size();++i){
        if (a[i]==8){
            //std::cout << "Correct Index = " << i <<std::endl;
            break;
        }
    }

    assert(j==i);
}