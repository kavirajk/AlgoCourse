#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

double rec(double,double);
int le(long long);
int main() {
  long long x,y;
  cin>>x>>y;
  cout<<fixed<<"Ans: "<<setprecision(0)<<rec(x,y)<<endl;
  return 0;
}
double rec(double m,double n) {
  if(m<10 || n<10) //base case
    return m*n;
  int len=0;
  if(m<n) { // make the smaller number digits as m
    len=le(m);
  } else {
    len=le(n);
  }
  if(len%2) // making len even
    len--;
  // Actual karatsuba logic
  double exp=pow(10,len/2);
  double b=fmod(m,exp);
  double a=(m-b)/exp;
  double d=fmod(n,exp);
  double c=(n-d)/exp;
  double bd=rec(b,d);
  double prod=rec((a+b),(c+d));
  double ac=rec(a,c);
  double ad_bc=prod-bd-ac;
  return (pow(10,len)*ac)+(pow(10,len/2)*ad_bc)+bd;
}
int le(long long x) {
  int i=0;
  while(x!=0) {
    x/=10;
    i++;
  }
  return i;
}
