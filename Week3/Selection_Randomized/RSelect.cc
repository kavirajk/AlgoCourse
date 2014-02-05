#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
#include<iterator>
#include<algorithm>

using namespace std;

const string i_file="data.txt";
const string o_file="output_better.txt";

int Rselect(vector<int>& v,int l_limt,int h_limit,int i);
size_t choosePivot(int l_limit,int h_limit);
size_t Partition(vector<int>& v,int l_limit,int h_limit);
size_t getRandom_i(size_t size);

int main() {
  srand(time(NULL));
  ifstream input(i_file.c_str());
  ofstream output(o_file.c_str());

  vector<int> v;

  copy(istream_iterator<int>(input),istream_iterator<int>(),back_inserter(v));

  size_t i=getRandom_i(v.size()); // choosing "i" as random for ith order statistic

  int iValue=Rselect(v,0,v.size(),i-1); //passing (i-1) instead of i because, 0th smallest is 1st smallest, according to client
  
  //  cout<<i<<"th Smallest number: "<<iValue<<endl;

  output<<i<<" "<<iValue<<endl;

  return 0;
}

size_t getRandom_i(size_t size) {
  return (rand()%size)+1; // Choosing random from 1 to size inclusive( no zeros allowed)
}

size_t choosePivot(int l_limit,int h_limit) {
  return l_limit+ getRandom_i(h_limit-l_limit)-1; // Choose pivot from l_limit to h_limit(exclusive) as pivot ranges from 0 to size-1
}

size_t Partition(vector<int>& v,int l_limit,int h_limit) {
  size_t len=h_limit;
  int i,j;
  i=l_limit;
  for(j=i+1;j<h_limit;++j) {
    if(v[l_limit]>v[j]) {
      swap(v[i+1],v[j]);
      ++i;
    }
  }
  swap(v[l_limit],v[i]);
  return i;
}

int Rselect(vector<int>& v,int l_limit,int h_limit,int i) {
  size_t len=h_limit-l_limit+1;
  if(len==1)
    return v[l_limit];

  size_t pivot=choosePivot(l_limit,h_limit);
  swap(v[pivot],v[l_limit]);
  
  size_t pos= Partition(v,l_limit,h_limit);

    if(pos == i) {
    return v[pos];
  }
  if(pos > i) {
    return Rselect(v,l_limit,pos,i);
  } else {
    return Rselect(v,pos+1,h_limit,i);
  }
}
