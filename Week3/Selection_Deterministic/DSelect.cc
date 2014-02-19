#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <fstream>

using namespace std;

const string i_file="data.txt";
const string o_file="output_better.txt";

int DSelect(vector<int> v,int i);
int ChoosePivot(vector<int> &v);
size_t Partition(vector<int>& v);
size_t GetRandomI(size_t limit);

int main() {
  srand(time(NULL));
  
  ifstream input(i_file.c_str());
  ofstream output(o_file.c_str());
  
  vector<int> numbers;
  copy(istream_iterator<int>(input),istream_iterator<int>(),back_inserter(numbers));
  
  int i_r=GetRandomI(numbers.size());
  int result=DSelect(numbers,i_r-1);
  output<<i_r<<" "<<result<<endl;

  return 0;
}

int DSelect(vector<int> v,int i) {
  int len=v.size();

  if(len<=10) {
    sort(v.begin(),v.end());
    return v[i];
  }
  int median = ChoosePivot(v);
  size_t p_pos=distance(v.begin(),find(v.begin(),v.end(),median));
  swap(v[p_pos],v[0]);
  
  size_t pos = Partition(v);

  if(pos==i)
    return v[pos];
  else if(pos>i) {
    return DSelect(vector<int>(v.begin(),v.begin()+pos),i);
  } else {
    return DSelect(vector<int>(v.begin()+pos+1,v.end()),i-pos-1);
  }
  
}

int ChoosePivot(vector<int>& v) {
  int len=v.size();
  int g_size=len/5;

  int g_mod=len%5;

  int start=0,end=5;

  vector<int> vt;

  for(int i=0;i<g_size; ++i) {
    sort(v.begin()+start,v.begin()+end);
    vt.push_back(*(v.begin()+start+2));
    start+=5;
    end+=5;
  }

  if(g_mod) {
    sort(v.begin()+start,v.begin()+start+g_mod);
    int offset=(g_mod-1)/2;
    vt.push_back(*(v.begin()+start+offset));
  }

  return DSelect(vt,(vt.size()-1)/2);
}

size_t Partition(vector<int>& v) {
  int i=0,j=1;
  for(int j=1; j<v.size(); ++j) {
    if(v[j]<v[0]) {
      swap(v[i+1],v[j]);
      i++;
    }
  }
  swap(v[i],v[0]);

  return i;
}

size_t GetRandomI(size_t limit) {
  return (rand()%limit)+1;
}
