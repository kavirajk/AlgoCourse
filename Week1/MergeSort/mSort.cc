#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

void mSort(vector<int> &v);
void merge(const vector<int> &left,const vector<int> &right,vector<int> &output);

int main() {
  vector<int> v {3,8,1,9,4,7,2};
  mSort(v);
  copy(v.begin(),v.end(),ostream_iterator<int>(cout,"\n"));

  return 0;
}

void mSort(vector<int> &v) {
  size_t len=v.size();
  if(len<=1)
    return;
  vector<int> left(v.begin(),v.begin()+len/2);
  vector<int> right(v.begin()+len/2,v.end());

  mSort(left);
  mSort(right);
  merge(left,right,v);
  
}

void merge(const vector<int> &left,const vector<int> &right,vector<int> &output) {
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
    }
  }

  if(k==kLimit)
    return;

  if(i<iLimit) {
    copy(left.begin()+i,left.end(),output.begin()+k);
  } else {
    copy(right.begin()+j,right.end(),output.begin()+k);
  }

}
