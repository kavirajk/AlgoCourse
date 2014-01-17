#include<iostream>
#include<vector>

using namespace std;

int findInversions(vector<int> v);

int main() {
  vector<int> v {1,3,5,2,4,6};
  cout<<findInversions(v)<<endl;

  return 0;
}

int findInversions(vector<int> v) {
  int len=v.size();
  int result=0;
  int i,j;
  for(i=0;i<len-1;++i) {
    for(j=i+1;j<len;++j) {
      if(v[i]>v[j])
	++result;
    }
  }
  
  return result;
}
