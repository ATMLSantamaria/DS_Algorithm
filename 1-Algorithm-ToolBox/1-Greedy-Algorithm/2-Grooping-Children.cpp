#include <vector>
#include <iostream>

std::vector<std::pair<double,double>> PointCoveredSorted(std::vector<double> &v){
    // Conjunto de Segmentos en un vector
    std::vector<std::pair<double,double>> R;
    int n=v.size();
    //Interval
    double r=0,l=0;
    int i=0;
    //Safe move is set r of interval to the leftmost point

    while(i<n){
        //Reduce to subproblem
        l=v[i];
        r=v[i]+1;
        i++;
        //Move forward while v[i] is under the segment
        while(i<n && v[i] <= r){
            i++;
        }
        R.push_back(std::pair<double,double>{l,r});

    }
    return R;
}


int main(){
    std::vector<double> v{1.1,1.2,1.4,2,2.1,3,7,7.8,7.9,20,20.1,20.2,20.3,20.4,20.5,21,21.1};
    //std::vector<double> v{1,2,3,3.1};

    //R is the vector with the segments. Each segment represented by a pair right point - left point
    
    std::vector<std::pair<double,double>> R = PointCoveredSorted(v);
    for (auto &i: R){
        std::cout << "[" << i.first << ',' << i.second << ']'<< std::endl;
    }

    std::cout << "Number of Segments: " << R.size() << std::endl;
}