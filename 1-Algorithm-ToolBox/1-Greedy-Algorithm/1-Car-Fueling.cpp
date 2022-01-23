#include <vector>
#include <iostream>
/*
    Find the minimum amount of refills in a path with several gas station
    Autonomy of the car is L
    Ejemplo path:            | Car   gasStation      _       gasStation      _       gasStation        gasStation      _    _       destination |
    
    Position of gas stations are given by numbers from x1 to xn. En este caso   x={3,5,8}
    x0 corresponde a la posicion incial del coche
    xn+1 al destino
    
    El input al algoritmo va a ser un array x, un L representando la autonomia y n el numero de estaciones

*/

// CREO QUE EL PROBLEMA ES QUE NO ELEGIMOS COMPROBAMOS QUE NUESTRO PRIMER MOVIMIENTO SEA SAFE

int minRefills(std::vector<int> x,int n,int L){
    int currentRefill=0; //Nuestra posicion
    int numRefills=0;

    while(currentRefill <= n){ //en este momento habriamos pasado por todas las estaciones

        //Reducir a subproblema
        int lastRefill = currentRefill;

        //Make the next movement. Demostrate that is Safe
        while(currentRefill <=n && (x[currentRefill+1]-x[lastRefill]) <= L){
            currentRefill++;
        }
        if (currentRefill==lastRefill) return -1;
        if (currentRefill <=n){numRefills++;}
    }
    return numRefills;
}
int main(){
    std::vector<int> v{1,3,5,6};
    int n=8;
    int L=3;

    std::cout << "Numero Refills=" << minRefills(v,n,L) << std::endl;

}
