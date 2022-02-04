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
std::pair<int,int> partition_in_3(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  int m1=j;
  for (int i=j;i==x;--i){
    m1=i;
  }

  return std::pair<int,int>(m1,j);
}
void randomized_quick_sort_version3(vector<int> &A, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(A[l], A[k]);
  std::pair<int,int> m = partition_in_3(A, l, r);

  randomized_quick_sort_version3(A, l, m.first - 1);
  randomized_quick_sort_version3(A, m.second + 1, r);
}


int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  vector<int> aa{a};
  std::cout << "Version Normal" << std::endl;

  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }

  std::cout << std::endl;
  std::cout << "Version 3" << std::endl;

  randomized_quick_sort_version3(aa,0,aa.size()-1);
    for (size_t i = 0; i < aa.size(); ++i) {
    std::cout << aa[i] << ' ';
  }
  std::cout << std::endl;

}
/*

5
2 3 9 2 2

*/
