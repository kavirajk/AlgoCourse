#include <iostream>
#include <cmath>
#include <sstream>
#include <fstream>
#include <iterator>

using namespace std;

const string i_file="data.txt";
const string o_file="output_better.txt";

long karat(long x,long y);

long length(long x);

int main() {

  ifstream input(i_file.c_str());
  ofstream output(o_file.c_str());
  long x,y;
  
  while(input>>x>>y) {
    output<<karat(x,y)<<endl;
  }

  input.close();
  output.close();

  return 0;
}

long karat(long x,long y) {
  if(x<10 || y<10)
    return x*y;
  long len;
  if(x<y) {
    len=length(x);
  }else {
    len=length(y);
  }
  if(len%2)
    len--;
  long exp=pow(10,len/2);
  long exp2=pow(exp,2);

  long a=x/exp;
  long b=x-(a*exp);

  long c=y/exp;
  long d=y-(c*exp);

  long ac=karat(a,c);
  long bd=karat(b,d);

  long a_bc_d=karat(a+b,c+d);

  return exp2*ac + bd + exp*(a_bc_d-ac-bd);
}

long length(long x) {
  long count=0;
  while(x!=0) {
    x/=10;
    count++;
  }
  return count;
}
