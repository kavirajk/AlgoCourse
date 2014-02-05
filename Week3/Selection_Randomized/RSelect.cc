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

  int iValue=Rselect(v,0,v.size(),i); // 0th smallest is 1st smallest, according to client
  
  cout<<i<<"th Smallest number: "<<iValue<<endl;

  return 0;
}

size_t getRandom_i(size_t size) {
  return rand()%size; // "size+1", becoz we nee random "i" from 1 to n inclusive
}

size_t choosePivot(int l_limit,int h_limit) {
  return l_limit+ getRandom_i(h_limit-l_limit);
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
  /*  if(l_limit==0 && h_limit==0) { // To handle empty vector as len=1 in that case
    cout<<"Empty vector. Fatal Error. Terminating...\n";
    exit(1);
    }*/
  // copy(v.begin(),v.end(),ostream_iterator<int>(cout,", "));
  if(len==1)
    return v[l_limit];

  size_t pivot=choosePivot(l_limit,h_limit);
  swap(v[pivot],v[l_limit]);
  
  size_t pos= Partition(v,l_limit,h_limit);
 
  //  cout<<"here\n";
  if(pos == i) {
    return v[pos];
  }
  if(pos > i) {
    return Rselect(v,l_limit,pos,i);
  } else {
    return Rselect(v,pos+1,h_limit,i-pos+1);
  }
}
