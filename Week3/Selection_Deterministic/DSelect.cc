#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <fstream>

using namespace std;

const string i_file="data.txt";
const string o_file="output_better.txt";

pair<int,int> DSelect(vector<pair<int,int> > v,int i);
pair<int,int> ChoosePivot(vector<pair<int,int> > v);
int Partition(vector<pair<int,int> >& v);
bool operator<(const pair<int,int>& a,const pair<int,int>& b);
size_t GetRandomI(size_t limit);

int main() {
  srand(time(NULL));
  
  ifstream input(i_file.c_str());
  ofstream output(o_file.c_str());
  
  vector<int> numbers;
  vector<pair<int,int> >v;
  //  copy(istream_iterator<pair<int,int> >(input),istream_iterator<pair<int,int> >(),back_inserter(v));
  copy(istream_iterator<int>(input),istream_iterator<int>(),back_inserter(numbers));
  for(int i=0;i<numbers.size(); ++i) {
    v.push_back(make_pair(numbers[i],i));
  }

  int i_r=GetRandomI(v.size());
  /*  for(int i=0;i<v.size(); ++i) {
    cout<<v[i].first<<", "<<v[i].second<<endl;
    }*/
  //  cout<<"i: "<<i_random<<endl;
  pair<int,int> result=DSelect(v,2);
  cout<<i_r<<" "<<result.first<<endl;

  return 0;
}

pair<int,int> DSelect(vector<pair<int,int> > v,int i) {
  int len=v.size();

  /*  cout<<"DSelect: \n";
  for(int k=0;k<len; ++k) {
    cout<<v[k].first<<", "<<v[k].second<<endl;
    }*/

  if(len<=2) {
    sort(v.begin(),v.end());
    return v[i];
  }
  for(int k=0; k<v.size(); ++k) {
    v[k].second=k;
  }
  pair<int,int> median = ChoosePivot(v);

  swap(v[median.second],v[0]);
  cout<<"median: "<<median.first<<endl;
  int pos = Partition(v);
  cout<<"pos: "<<pos<<endl;
  if(pos==i)
    return v[pos];
  else if(pos>i) {
    cout<<"left side\n";
    return DSelect(vector<pair<int,int> >(v.begin(),v.begin()+pos),i);
  } else {
    cout<<"right side\n";
    vector<pair<int,int> > tmp(v.begin()+pos,v.end());
    for(int k=0;k<tmp.size();++k) {
      tmp[k].second=k;
    }
    return DSelect(tmp,i-pos);
  }
}

pair<int,int> ChoosePivot(vector<pair<int,int> > v) {
  //  cout<<"Choose v.size(): "<<v.size()<<endl;;
  int len=v.size();
  int g_size=len/5;

  int g_mod=len%5;

  int start=0,end=5;

  vector<pair<int,int> > vt;

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

  return DSelect(vt,vt.size()/2);
}

int Partition(vector<pair<int,int> >& v) {
  //  cout<<"partition\n";
  int i=0,j=1;
  for(int j=1; j<v.size(); ++j) {
    if(v[j]<v[0]) {
      swap(v[i+1],v[j]);
      i++;
    }
  }
  swap(v[i],v[0]);
  for(int k=0;k<v.size();++k) {
    v[k].second=k;
  }
  return v[i].second;
}

bool operator<(const pair<int,int>& a,const pair<int,int>& b) {
  return a.first < b.first;
}

size_t GetRandomI(size_t limit) {
  return rand()%limit;
}
