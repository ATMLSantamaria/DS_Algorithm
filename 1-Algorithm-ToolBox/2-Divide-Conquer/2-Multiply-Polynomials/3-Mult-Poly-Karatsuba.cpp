/*
    Karatsuba Divide And Conquer Algorithm for Multiply Polynomials

    3 Calls Recursive Algorithm Solution

    Running Time O(n^1.58). 
*/

#include <vector>
#include <iostream>
#include <algorithm>


/*
    Function that uses a D&C approach to polynomial multiplication
    Input:
    A vector(n-1) with coefficient of first polinomial
    B vector(n-1) with coefficient of second polinomial

*/
std::vector<int> MultPolynomialDivideConquerKaratsuba(std::vector<int> &A,std::vector<int>&B){
    // Res is always an array of size 2*n-1 containing the resulting coefficient
    int n=A.size();
    std::vector<int> R(2*n-1);
    //Base Case
    if(n==1){
        R[0]=A[0]*B[0];
        return R;
    }

    //MULTIPLICATIONS
    std::vector<int> A1{A.begin(),A.begin()+n/2};
    std::vector<int> A0{A.begin()+n/2,A.end()};
    std::vector<int> B1{B.begin(),B.begin()+n/2};
    std::vector<int> B0{B.begin()+n/2,B.end()};

    std::vector<int> R_left = MultPolynomialDivideConquerKaratsuba(A1,B1); 
    std::vector<int> R_right = MultPolynomialDivideConquerKaratsuba(A0,B0); 
    //Karatsuba Idea
    std::vector<int> A1plusA0(n/2);
    std::vector<int> B1plusB0(n/2);
    //Reemplaza la suma de terminos adicionales por (A1+A0)*(B1+B0) - R_left - R_right

    for (int i=0;i<n/2;++i){
        A1plusA0[i]=A1[i]+A0[i];
        B1plusB0[i]=B1[i]+B0[i];
    }
    std::vector<int> mul = MultPolynomialDivideConquerKaratsuba(A1plusA0,B1plusB0);

    for (int i=0;i<=n/2;++i){
        mul[i] = mul[i] - (R_left[i]+R_right[i]);
    }

    //ENSAMBLAR EN EL ARRAY RESULT
    for (int i=2*n-2;i>=n;--i){ 
        R[2*n-2-i]=R_left[2*n-2-i];
    }
    for (int i=n-2;i>=0;--i){ 
        R[2*n-2-i]=R_right[n-2-i];
    }
    for (int i=n+n/2-2;i>=n/2;--i){ 
        R[2*n-2-i]+=mul[n+n/2-2-i];
    }
    return R;
}


void printPolynomial(std::vector<int> &res);
int main(){

    std::vector<int> A{1,1,1,1}; 
    std::vector<int> B{2,3,1,-2};
    // std::vector<int> A{4,3,2,1}; 
    // std::vector<int> B{1,2,3,4};

    std::vector<int> res = MultPolynomialDivideConquerKaratsuba(A,B);


    printPolynomial(res);
}

void printPolynomial(std::vector<int> &res){
    std::cout << "{ ";
    for(auto &i : res){
        std::cout << i << ' ';
    }
    std::cout << "}\n"; 
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


//x6+3x5+4x4+5x3+4x2+2x+1