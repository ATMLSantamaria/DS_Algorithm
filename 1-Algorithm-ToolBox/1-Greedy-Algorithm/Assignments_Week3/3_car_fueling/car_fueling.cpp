#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int num_of_refills=0;
    int i=0; //current_refill
    int n = stops.size();
    stops[n-1]=dist;
    // write your code here
    int nn=n-2;
    while(i <= nn /*n-2*/){

        //Extraigo mi posicion de repostaje
        int last_refill = i;
        //GREEDY CHOICE THAT I HAVE PROVE IS A SAFE MOVE
        //Avanzo todo lo posible sin repostar mientras la siguiente parada este disponible. 
        while((stops[i+1] - stops[last_refill]) <= tank && i<=nn /*n-2*/ ){
            //int tmp_next =stops[i+1];
            //int tmp_last =stops[last_refill];
            i++;
        }
        if(i==last_refill) return -1;
        //Aqui repostas, asi que aumentas el numero de repostajes
        if (i <= nn){
            num_of_refills++;
            //std::cout << " He parado en " << i << ' '<< stops[i] <<std::endl;
        }
    }

    return num_of_refills;
   
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n+2);
    
    stops[n+1]=d;
    for (size_t i = 1; i <= n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
