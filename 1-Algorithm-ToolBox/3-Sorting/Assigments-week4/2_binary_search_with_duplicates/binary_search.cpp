#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
using std::vector;

int binary_search(const vector<int> &a, int x,int low, int high) {
  int left = 0, right = (int)a.size(); 
  //write your code here. x is the key
  if (high < low)
  {
    return -1;
  }
  int mid = low + (high-low)/2;
  if (x == a[mid] && a[mid-1]!=x){
    return mid;
  }
  else if(x <= a[mid]){
    //std::vector<int> left{a.begin(),a.begin()+mid};
    return binary_search(a,x,low,mid-1);
  }
  else {
    //std::vector<int> right{a.begin()+mid,a.end()};
    return binary_search(a,x,mid+1,high);
  }
  
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }


  // std::vector<int> a{0,1,2,2,4,5,6,7};
  // int m = a.size();
  // std::vector<int> b{7,6,5,4,3,2,1,0};
  
  std::sort(a.begin(),a.end());
  //for (auto &i : b){std::cout << i << " ";} std::cout << "end sort\n";
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a,b[i],0,a.size()-1) << ' ';
  }

}

/*
7
2 4 4 4 7 7 9
4
9 4 5 2

Your output:
6 3 -1 0 
Correct output:
6 1 -1 0
*/
