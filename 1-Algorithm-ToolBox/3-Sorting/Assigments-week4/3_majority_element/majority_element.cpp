#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  //right is a.size, so the max value is righ-1
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  int mid = left+(right-left)/2;
  int x = get_majority_element(a,left,mid);
  int y = get_majority_element(a,mid,right);
  //Si combinacion es igual. Hay mayoritario
  if(x==y){
    return x;
  } else {
    int count_x=0,count_y=0;
    for (int i=left;i<right;++i){
      if (a[i]==y){
        count_y++;
      }
      if (a[i]==x){
        count_x++;
      }
    }
    if (count_y > (right - left)/2){
      return y;
    } else if (count_x > (right - left)/2){
      return x;
    } else {
      return -1;
    }
  }
  return -1;
}


int get_majority_element_for_test(vector<int> &a, int left, int right) {
  //right is a.size, so the max value is righ-1
  //if (left == right) return -1;
  //if (left + 1 == right) return a[left];
  //write your code here
  std::sort(a.begin(),a.end());
  int count=1;
  int initialValue=a[0];
  if (a.size()==1){return initialValue;}
  for (int i=1;i<a.size();++i){
    if(a[i]==initialValue){
      count++;
    }
    if (count > a.size()/2){
      return a[i];
    }
    if (a[i]!=initialValue){
      count=0;
      initialValue=a[i];
    }
  }
  return -1;
}



int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
/*
6
2 3 9 2 2 1

4
1 2 3 4
*/