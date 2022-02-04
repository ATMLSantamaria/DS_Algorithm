#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}
std::pair<int,int> partition3(std::vector<int> &A,int l ,int r){
  //Pivot
  int x = A[l];
  int m1=l;
  int m2=l;
  for (int i=l+1;i<=r;++i){
    if(A[i]<=x){
      m2++;
      std::swap(A[i],A[m2]);
    }
  }
  std::swap(A[l],A[m2]);
  for (int i=0;i<A.size();++i){
    if(A[i]==x){
      m1=i;
      break;
    }
  }
  return std::pair<int,int>(m1,m2);
}
void randomized_quick_sort3(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  std::pair<int,int> m = partition3(a, l, r);

  randomized_quick_sort3(a, l, m.first - 1);
  randomized_quick_sort3(a, m.second + 1, r);
}
void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);

  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  //vector<int> aa{a};

  randomized_quick_sort3(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }


  //std::cout << std::endl;

  // randomized_quick_sort3(aa,0,aa.size()-1);
  //   for (size_t i = 0; i < aa.size(); ++i) {
  //   std::cout << aa[i] << ' ';
  // }
  // std::cout << std::endl;

}
/*

5
2 3 9 2 2

*/
