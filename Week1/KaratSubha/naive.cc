#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iterator>
#include<vector>

using namespace std;

struct integers {
  string first;
  string second;
};

long num(string s) {
  long n=0;
  for(int i=0;i<s.size();++i) {
    n=n*10+(s[i]-'0');
  }
  return n;
}

long integer_multiplication(string s1,string s2) {
  long f_prod=0;
  string c_prod="";
  for(int i=s1.size()-1;i>=0;--i) { // b'coz mul takes place from 1's bit, 10's bit and so on
    c_prod="";int s=0,c=0;
    for(int j=s2.size()-1;j>=0;--j) {
      s=(s1[i]-'0')*(s2[j]-'0')+c; // single digit multiplication
      c=s/10;			   // carry
      c_prod+=(s%10+'0');	   // current row product
    }
    c_prod+=(c+'0'); // need to add final carry
    reverse(c_prod.begin(),c_prod.end()); // need to reverse the current row product
    f_prod+=num(c_prod)*pow(10,s1.size()-1-i);
  }
  return f_prod;
}

int main() {
  freopen("data.txt","r",stdin);
  freopen("output_naive.txt","w",stdout);

  vector<integers> input;
  string a,b;
  while(cin>>a>>b) {
    integers t;
    t.first=a;
    t.second=b;
    input.push_back(t);
  }
  for(int i=0;i<input.size();++i) {
    cout<<integer_multiplication(input[i].first,input[i].second)<<endl;
  }
  return 0;
}
