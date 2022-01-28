#include <vector>
#include <iostream>

/*
  This Function takes a vector with the coefficients of 2 Polynomials of grade n - 1
  n is the size of the vector representing the polynomials: n=2 -> A(x) = ax+b -> A{a,b}
*/
std::vector<int> MultiplyPolynomial(std::vector<int> &A,std::vector<int> & B,int n){
    // Vector with coeffs of the resulting polynomial
    std::vector<int> product(2*n-1);
    //Initialize to 0
    for (auto &i : product){
        i=0;
    }
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){

            product[i+j]=product[i+j]+A[i]*B[j];

        }
    }
    return product;
}
void printPolynomial(std::vector<int> &res);
int main(){

    std::vector<int> A{1,1,1}; //x+1
    std::vector<int> B{1,2,1}; //x+2

    //res= x^2 +3x+2  
    int n = A.size();

    std::vector<int> res = MultiplyPolynomial(A,B,n);

    std::cout << "{ ";
    for(auto &i : res){
        std::cout << i << ' ';
    }
    std::cout << "}\n"; 
    printPolynomial(res);
}

void printPolynomial(std::vector<int> &res){
    int n = res.size();
    int grado_max = n-1;

    for (int i=0;i<=grado_max;++i){
        if (i==grado_max){
            std::cout << res[i]<<std::endl;
            break;
        }
        if(res[i]==1){
            std::cout << "x^"<< grado_max-i << " + ";
            continue;
        }
        std::cout << res[i] << "*x^" << grado_max-i << " + ";

    }
}


