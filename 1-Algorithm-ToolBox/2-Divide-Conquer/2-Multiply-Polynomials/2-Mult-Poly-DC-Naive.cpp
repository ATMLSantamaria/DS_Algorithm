/*
    Naive Divide And Conquer Algorithm for Multiply Polynomials

    4 Calls Recursive Algorithm Solution

    Running Time O(n2). Same than in pure naive algorithm
*/

#include <vector>
#include <iostream>


/*
    Function that uses a D&C approach to polynomial multiplication
    Input:
    A vector(n-1) with coefficient of first polinomial
    B vector(n-1) with coefficient of second polinomial
    int n: size of array of coefficient
    a_l: Index of the first coefficient of Array A. Term of highest grade   
    b_l: Index of the first coefficient of Array B  Term of highest grade  

    A=D1*x^n/2+D0
    B=E1*x^n//2+E1

*/
std::vector<int> MultPolynomialDivideConquerNaive(std::vector<int> &A,std::vector<int>&B,int n, int a_l,int b_l){
    // Res is always an array of size 2*n-1 containing the resulting coefficient
    std::vector<int> R(2*n-1);
    //Base Case
    if(n==1){
        R[0]=A[a_l]*B[b_l];
        return R;
    }

    //MULTIPLICATIONS
    std::vector<int> R_left = MultPolynomialDivideConquerNaive(A,B,n/2,a_l,b_l); //correspond to 0 ... n-2 coeffs of resulting array -> D1 * E1
    std::vector<int> R_right = MultPolynomialDivideConquerNaive(A,B,n/2,a_l+n/2,b_l+n/2); //correspond to n to 2*n -2 of resulting array -> D0 * E0

    std::vector<int> D0E1 = MultPolynomialDivideConquerNaive(A,B,n/2,a_l,b_l+n/2); // CREO QUE ESTO ES D1E0
    std::vector<int> D1E0 = MultPolynomialDivideConquerNaive(A,B,n/2,a_l+n/2,b_l); //CREO QUE ESTO ES D0E1

    //ENSAMBLAR EN EL ARRAY RESULT
    for (int i=0;i<n-1;++i){ //rellena el array de 0 a n-2 incluido
        R[i]=R_left[i];
    }
    for (int i=n;i<2*n-1;++i){ //rellena el array de n a 2*n-2 incluido
        R[i]=R_right[i-n];
    }
    for (int i=n/2;i<n+n/2-1;++i){ //suma terminos adicionales entre n/2 y n + n/2-2 incluido
        R[i]+=D0E1[i-n/2]+D1E0[i-n/2];
    }
    return R;
}


void printPolynomial(std::vector<int> &res);
int main(){

    std::vector<int> A{1,1,1,1}; 
    std::vector<int> B{1,2,1,1}; 

    //res= x^2 +3x+2  
    int n = A.size();

    std::vector<int> res = MultPolynomialDivideConquerNaive(A,B,n,0,0);


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