#include<iostream>
#include<vector>
#include<iterator>
#include<fstream>
#include<string>

using namespace std;

const string i_file="data.txt";
const string o_file="output_naive.txt";

int findInversions(vector<int> v);
int main() {
  ifstream input(i_file.c_str());
  ofstream output(o_file.c_str());
  vector<int> v;
  copy(istream_iterator<int>(input),istream_iterator<int>(),back_inserter(v));
  output<<findInversions(v)<<endl;

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
