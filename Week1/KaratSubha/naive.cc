#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cmath>

using namespace std;

const string i_file="data.txt";
const string o_file="output_naive.txt";

long naive(long a,long b);

int main() {
  ifstream input(i_file.c_str());
  ofstream output(o_file.c_str());
  long x,y;
  while(input>>x>>y) {
    output<<naive(x,y)<<endl;
  }

  input.close();
  output.close();

  return 0;

}

long naive(long a,long b ) {
  //  cout<<"X: "<<a<<", Y: "<<b<<endl;
  vector<long> x;
  vector<long> y;
  while(a) {
    x.push_back(a%10);
    a/=10;
  }
  while(b) {
    y.push_back(b%10);
    b/=10;
  }

  reverse(x.begin(),x.end());
  reverse(y.begin(),y.end());

  /*  cout<<"X: ";
  copy(x.begin(),x.end(),ostream_iterator<int>(cout,", "));
  cout<<endl;

  cout<<"Y: ";
  copy(y.begin(),y.end(),ostream_iterator<int>(cout,", "));
  cout<<endl;*/


  long final_product,row_product,single_product,carry,last_digit;
  final_product=0;
  single_product=0;
  carry=0;
  last_digit=0;

  int i=y.size()-1;
  int j=x.size()-1;


  int c=0;

  for(;i>=0;--i) {
    row_product=0;
    int c1=0;
    for(j=x.size()-1;j>=0;--j) {
      single_product=y[i]*x[j]+carry;
      //      cout<<"single prod: "<<single_product<<endl;
      //      row_product+=carry;
      //cout<<"row_product: "<<row_product<<endl;
      last_digit=single_product%10;
      //      cout<<"last_digit: "<<last_digit<<endl;
      carry=(single_product - last_digit)/10;
      //      cout<<"carry: "<<carry<<endl;
      row_product=row_product+(last_digit*pow(10,c1++));
      //      cout<<"row prod: "<<row_product<<endl;
    }
    row_product=(carry*pow(10,c1))+row_product;
    final_product=row_product*(pow(10,c++))+final_product;
    //    cout<<"final prod: "<<final_product<<endl;
    carry=0;
  }
  //  cout<<endl<<endl;

  return final_product;

}
