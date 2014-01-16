#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

long karat(long x,long y);

long getInteger();

long length(long x);

int main() {
  cout<<"Int x: ";
  long x=getInteger();
  cout<<"Int y: ";
  long y=getInteger();
  cout<<karat(x,y)<<endl;

  return 0;
}

long getInteger() {
  while(1) {
    stringstream converter;
    string line;
    long result;
    getline(cin,line);
    converter<<line;
    converter>>result;
    if(converter.fail()) {
      cout<<"Invalid integer type, Try again\n";
    }
    string dummy;
    converter>>dummy;
    if(converter.fail()) {
      return result;
    }
    cout<<"Invalid token '"<<dummy<<"', Try again\n";
  }
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
