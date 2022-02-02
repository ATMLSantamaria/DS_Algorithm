#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element2(vector<int> &a, int left, int right) {
  //right is a.size, so the max value is righ-1
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  int mid = left+(right-left)/2;
  int x = get_majority_element2(a,left,mid);
  int y = get_majority_element2(a,mid,right);
  if(x==y){
    return x;
  } else if(x!=-1 && y!=-1) {
    int count_x=0,count_y=0;
    for (int i=left;i<right;++i){
      if (a[i]==x){
        count_x++;
      } else if (a[i]==y){
        count_y++;
      }
      
      
    }
    if((count_y > (right-left)/2  || count_x > (right-left)/2 )){
        return count_y >= count_x ? y : x;
    }
  } 
  return -1;
}

int get_majority_element(vector<int> &a, int left, int right) {
  //right is a.size, so the max value is righ-1
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  std::sort(a.begin(),a.end());
  int count=1;
  int initialValue=a[0];
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
5
2 3 9 2 2

4
1 2 3 4
*/