#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>

using namespace std;

const string i_file="data.txt";
const string o_file="output_naive.txt";

void insertion(vector<int> &a);
void selection(vector<int> &a);
void bubble(vector<int> &a);

int main() {
  ifstream input(i_file.c_str());
  ofstream output(o_file.c_str());

  vector<int> v;
  copy(istream_iterator<int>(input),istream_iterator<int>(),back_inserter(v));

  //  insertion(v);
  //  selection(v);
  bubble(v);

  copy(v.begin(),v.end(),ostream_iterator<int>(output,"\n"));
  
  return 0;

}

void insertion(vector<int> &a) {
  size_t len=a.size();
  int i,j;
  for(i=0;i<len;++i) {
    int key=a[i];
    for(j=i; j>0 && a[j-1]>key;--j) {
      a[j]=a[j-1];
    }
    a[j]=key;
  }
}

void selection(vector<int> &a) {
  size_t len=a.size();
  for(int i=0 ; i<len ; ++i) {
    for(int j=i+1 ; j<len; ++j) {
      if(a[j]<a[i])
	swap(a[i],a[j]);
    }
  }
}

void bubble(vector<int> &a) {
  size_t len=a.size();
  for(int i=0 ; i<len ; ++i) {
    for(int j=0 ; j< len-(i+1); j++) {
      if(a[j]>a[j+1])
	swap(a[j],a[j+1]);
    }
  }
}
