#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

size_t sort_count(vector<int> &v);
size_t merge_count_split(const vector<int> &left,const vector<int> &right,vector<int> &output);

int main() {
  vector<int> v {6,5,4,3,2,1};
  cout<<"Inversions count: "<<sort_count(v)<<endl;

  return 0;
}

size_t sort_count(vector<int> &v) {
  size_t len=v.size();
  if(len<=1)
    return 0;
  vector<int> left(v.begin(),v.begin()+len/2);
  vector<int> right(v.begin()+len/2,v.end());

  size_t lc=sort_count(left);
  size_t rc=sort_count(right);
  size_t sc=merge_count_split(left,right,v);

  return lc+rc+sc;
}

size_t merge_count_split(const vector<int> &left,const vector<int> &right,vector<int> &output) {
  size_t sc=0;
  size_t iLimit=left.size();
  size_t jLimit=right.size();
  size_t kLimit=iLimit+jLimit;

  size_t i,j,k;
  i=j=0;
  for(k=0;k<kLimit && i<iLimit && j<jLimit;k++) {
    if(left[i]<right[j]) {
      output[k]=left[i];
      i++;
    } else {
      output[k]=right[j];
      j++;
      sc+=(left.size()-i);
    }
  }

  if(k==kLimit)
    return sc;

  if(i<iLimit) {
    copy(left.begin()+i,left.end(),output.begin()+k);
  } else {
    copy(right.begin()+j,right.end(),output.begin()+k);
  }

  return sc;

}
