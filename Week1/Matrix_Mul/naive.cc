#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>
#include<fstream>

using namespace std;

typedef vector<vector<int> > matrix;

void fillMatrix(matrix& x,ifstream& input,size_t n);
void naive(matrix& x, matrix& y, matrix& z,size_t n);

ostream& operator<<(ostream& out,vector<int>& v);

const string i_file="data.txt";
const string o_file="output_naive.txt";

int main() {

  ifstream input(i_file.c_str());
  ofstream output(o_file.c_str());

  long n;
  input>>n;

  matrix x(n,vector<int>(n,0));
  matrix y,z;
  y=z=x;

  fillMatrix(x,input,n);
  fillMatrix(y,input,n);



  naive(x,y,z,n);

  for(int i=0;i<n;++i) {
    output<<z[i]<<endl;
  }

  //  copy(z.begin(),z.end(),ostream_iterator<vector<int>>(cout,"\n"));

  return 0;

}

ostream& operator<<(ostream& out,vector<int>& v) {
  size_t  n=v.size();
  for(int i=0;i<n;++i) {
    out<<v[i]<<", ";
  }
  return out;
}

void naive(matrix& x,matrix& y, matrix& z,size_t n) {
  z.resize(n,vector<int>(n,0));
  for(int i=0;i<n;++i) {
    for(int j=0;j<n;++j) {
      for(int k=0;k<n;++k) {
	z[i][j]+=x[i][k]*y[k][j];
      }
    }
  }
}

void fillMatrix(matrix& x,ifstream& input,size_t n) {
  long tmp;
  for(int i=0;i<n;++i) {
    for(int j=0;j<n;++j) {
      input>>tmp;
      x[i][j]=tmp;
    }
  }
}
