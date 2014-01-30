#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<iterator>

using namespace std;

const string i_file="data.txt";
const string o_file="output_better.txt";

int partition(vector<int>& v,int lower_limit,int higher_limit);
void qsort(vector<int>& v,int lower_limit,int higher_limit);

int main() {

  ifstream input(i_file.c_str());
  ofstream output(o_file.c_str());

  vector<int> v;

  copy(istream_iterator<int>(input),istream_iterator<int>(),back_inserter(v));

  qsort(v,0,v.size());

  copy(v.begin(),v.end(),ostream_iterator<int>(output,"\n"));

  return 0;
}

void qsort(vector<int>& v,int lower_limit,int higher_limit) {
  if(lower_limit>=higher_limit-1)
    return;
  int l= partition(v,lower_limit,higher_limit);
  qsort(v,lower_limit,l);
  qsort(v,l+1,higher_limit);
}

int partition(vector<int>& v,int lower_limit,int higher_limit) {

  int i=lower_limit+1;
  size_t n=higher_limit;
  for(int j=lower_limit+1;j<n; ++j) {
    if(v[j]<v[lower_limit]) {
      swap(v[i],v[j]);
      i++;
    }
  }
  swap(v[lower_limit],v[i-1]);
  return i-1;
}
