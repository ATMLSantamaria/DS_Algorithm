#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

double get_optimal_value(int capacity, vector<std::pair<int,int>> &elements) {
  double value = 0.0;

  // write your code here
  for (int i=0;i<elements.size();++i){
    if(capacity==0){
      return value;
    }
    //min(w[i],capacity)
    double a = elements[i].second < capacity ? elements[i].second : capacity;

    value += a* static_cast<double>(elements[i].first)/elements[i].second;
    elements[i].second-=a;
    capacity -= a;
  }


  return value;
}

bool cpm(std::pair<int,int> &a, std::pair<int,int> &b){
  return static_cast<double>(a.first)/a.second > static_cast<double>(b.first)/b.second;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);

  std::vector<std::pair<int,int>> elements(n);
  for (int i = 0; i < n; i++) {
    //std::cin >> values[i] >> weights[i];
    std::cin >> elements[i].first >> elements[i].second;
  }

  std::sort(elements.begin(),elements.end(),cpm);
  double optimal_value = get_optimal_value(capacity,elements);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
