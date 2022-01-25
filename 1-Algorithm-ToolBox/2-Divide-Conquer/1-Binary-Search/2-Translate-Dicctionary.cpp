#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <assert.h>

bool cmp(std::pair<std::string,int> & a,std::pair<std::string,int> & b){
    return a.first < b.first;
}

int BinarySearch(std::vector<std::pair<std::string,int>> A, int low, int high,std::string key){
    //Base Case
    if (high < low){
        return low -1;
    }
    int mid = low + (high -low)/2;
    if (A[mid].first==key){
        return mid;
    } else if (A[mid].first < key ) { //Key in the
        return BinarySearch(A,mid+1,high,key);
    } else {
        return BinarySearch(A,low,mid-1,key);
    }
}

int main(){

    std::vector<std::string> es{"hola","adios","buenos dias","buenas noches","buenas tardes","encantado"};
    std::vector<std::string> en{"hello","goodbye","good morning","good evening","good afternoon","nice to meet you"};

    //We need to order es para aplicar binary seach pero entonces perderemos la correspondencia con el ingles
    std::vector<std::pair<std::string,int>> ess(es.size());
    int j=0;
    for (auto &i : es){
        ess[j].first=i;
        ess[j].second=j;
        j++;
    }
    //Now I have a array that keep track of the order of en array. I can sort it
    std::sort(ess.begin(),ess.end(),
                            [](std::pair<std::string,int> & a,std::pair<std::string,int> & b){return a.first < b.first;}); //Lambda Better


    //Word we want to search in Spanish
    std::string key="buenos dias";

    //Find the key
    int f = BinarySearch(ess,0,ess.size()-1,key);
    
    std::cout << ess[f].first << std::endl;
    //Use the key to with inderection access the correct English Word
    std::cout << en[ess[f].second] << std::endl;


    //Check that all seach are correct
    for (j=0;j<ess.size();++j){
        assert(  en[ess[BinarySearch(ess,0,ess.size()-1,es[j])].second]==en[j]);
    }







}