//Improved version of the previous algorithm.
/*
    Sorting the input before applying the solution to the problem I can create an algorithm that run in O(n) since only have to make one loop.
    The sorting should take O(nlogn).
    So this resolution is asymtotically an improvement of the previous one. Sorting does not take any extra time thanks to the STD LIBRARY.
*/
#include <vector>
#include <iostream>
#include <algorithm>

/*
I need to create a comparation function to order "conjunto". "Conjunto" will be ordered
following the value/weight ratio in descendant order/.
If a should come before b, then the function should return true, and if not then it should return false. That function is the third argument for std::sort
*/
bool cmp(std::pair<double,double> &a,std::pair<double,double>&b){
    return a.first/a.second > b.first/b.second;
}

/*
    Simple struct to contain the result
*/
struct Resultado
{
    std::vector<double> A; //Vector with quantities
    double V; //Total value
};

/*
    Algorithm to solve the problem
*/
Resultado Knapsack(int W,std::vector<std::pair<double,double>> &elements){
    Resultado res;
    int n=elements.size();
    std::vector<double> A(n);
    double V=0;
    for (int i=0;i<n;++i){
        if (W==0){
            res.A=A;
            res.V=V;
            return res;
        }
        //Here selection is not needed. Since elements is sorte I just need to take the next element.
        double a = 0;
        //min (w[i],W)
        a = elements[i].second < W ? elements[i].second : W;

        V += a* elements[i].first/elements[i].second;
        elements[i].second -= a;
        A[i] = a;
        W -= a;
    }
    res.A=A;
    res.V=V;

    return res;
}

int main(){
    //Small example
    int Capacity=7;
    std::vector<double> values{20,18,14};
    std::vector<double> weights{4,3,2};

    std::vector<std::pair<double,double>> conjunto;
    for (int i=0;i<values.size();++i){
        conjunto.push_back(std::make_pair(values[i],weights[i]));
    }


    //
    std::sort(conjunto.begin(),conjunto.end(),cmp);

    //Check the sort
    for (auto &i : conjunto){
        std::cout << '{' << i.first <<", "<<i.second<<'}'<<std::endl;
    }


     Resultado res = Knapsack(Capacity,conjunto);

    std::cout << "MAX VALUE= " << res.V << std::endl;
    std::cout << "CANTIDADES = {";

    for (auto &i: res.A){

        std::cout << i <<',';
    }
    std::cout << '}' << std::endl;

}