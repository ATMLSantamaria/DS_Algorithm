#include <vector>
#include <iostream>


struct Resultado
{
    std::vector<double> A; //Vector with quantities
    double V; //Total value
};

Resultado Knapsack(int W,std::vector<double> &v,std::vector<double>& w){
    Resultado res;
    int n = w.size();
    std::vector<double> A(v.size());
    double V =0;

    for (int i=0;i<n;++i){
        if (W==0){
            res.A=A;
            res.V=V;
            return res;
        }
        //Select item with best v/w
        int item=0;
        for (int k=item;k<n;++k){
            if(v[k]/w[k] > v[item]/w[item]
            && w[k]!=0){
                item=k;
                }
        }
        //End selection
        int a=0;
        //a = min(w[item],W)
        a = w[item] < W ? w[item] : W;

        V = V + a * v[item]/w[item];
        w[item]-=a;
        A[item]+=a;
        W -= a;
    }
    res.A = A;
    res.V = V;  
    return res; 
}


int main(){
    int Capacity=7;
    std::vector<double> values{20,18,14};
    std::vector<double> weights{4,3,2};
    Resultado res = Knapsack(Capacity,values,weights);

    std::cout << "MAX VALUE= " << res.V << std::endl;
    std::cout << "CANTIDADES = {";

    for (auto &i: res.A){

        std::cout << i <<',';
    }
    std::cout << '}' << std::endl;

    

}