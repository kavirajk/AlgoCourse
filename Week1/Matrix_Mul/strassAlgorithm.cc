#include<iostream>
#include<vector>
#include<fstream>
#include<iterator>

using namespace std;

const string i_file="data.txt";
const string o_file="output_better.txt";

typedef vector< vector<int> > matrix;

ostream& operator<<(ostream& input,const vector <int>& v);
void fillMatrix(matrix& v,ifstream& input,size_t n);

matrix strassMultiply(const matrix& x,const matrix& y,size_t n);
void computeBase(const matrix& x,const matrix& y,matrix& z,size_t n);
void divide(const matrix& x,matrix& a,matrix& b,matrix& c,matrix& d,size_t n);
void combine(matrix& x,matrix& a,matrix& b,matrix& c,matrix& d,size_t n);

matrix operator+(const matrix& x,const matrix& y);
matrix operator-(const matrix& x,const matrix& y);

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

  z=strassMultiply(x,y,n);
  
  for(int i=0;i<n;++i) {
    output<<z[i]<<endl;
  }

  //  copy(x.begin(),x.end(),ostream_iterator<vector<int> >(cout,"\n"));
  return 0;
}

ostream& operator<<(ostream& out,const vector<int> &v) {
  size_t len=v.size();
  for(int i=0;i<len;++i) {
    out<<v[i]<<", ";
  }
  return out;
}

void fillMatrix(matrix &v, ifstream& input,size_t n) {
  long tmp;
  for(int i=0;i<n;++i) {
    for(int j=0;j<n;++j) {
      input>>tmp;
      v[i][j]=tmp;
    }
  }
}

matrix strassMultiply( const matrix& X, const matrix& Y,size_t n) {
  matrix Z(n,vector<int>(n,0));
  if(n<=2) {
    computeBase(X,Y,Z,n);
    return Z;
  }

  matrix A(n/2,vector<int>(n/2,0));
  matrix B,C,D,E,F,G,H,P1,P2,P3,P4,P5,P6,P7,C1,C2,C3,C4,tmp1,tmp2;
  B=C=D=E=F=G=H=P1=P2=P3=P4=P5=P6=P7=C1=C2=C3=C4=tmp1=tmp2=A;

  cout<<"Debugging\n";
  size_t len=X.size();
  for(int i=0;i<len;i++) {
    cout<<X[i]<<endl;
  }

  divide(X,A,B,C,D,n);
  divide(Y,E,F,G,H,n);

  /*  tmp1=F-H;
  P1=strassMultiply(A,tmp1,n/2);

  tmp1=A+B;
  P2=strassMultiply(tmp1,H,n/2);

  tmp1=C+D;
  P3=strassMultiply(tmp1,E,n/2);

  tmp1=G-E;
  P4=strassMultiply(D,tmp1,n/2);

  tmp1=A+D;
  tmp2=E+H;
  P5=strassMultiply(tmp1,tmp2,n/2);

  tmp1=B-D;
  tmp2=G+H;
  P6=strassMultiply(tmp1,tmp2,n/2);

  tmp1=A-C;
  tmp2=E+F;
  P7=strassMultiply(tmp1,tmp2,n/2);
  */

  P1=strassMultiply(A,F-H,n/2);
  P2=strassMultiply(A+B,H,n/2);
  P3=strassMultiply(C+D,E,n/2);
  P4=strassMultiply(D,G-E,n/2);
  P5=strassMultiply(A+D,E+H,n/2);
  P6=strassMultiply(B-D,G+H,n/2);
  P7=strassMultiply(A-C,E+F,n/2);

  C1=P5+P4-P2+P6;
  C2=P1+P2;
  C3=P3+P4;
  C4=P1+P5-P3-P7;

  combine(Z,C1,C2,C3,C4,n);

  
  return Z;

}

void computeBase(const matrix& x,const matrix&y,matrix& z,size_t n) {
  for(int i=0;i<n;++i) {
    for(int j=0;j<n; ++j) {
      for(int k=0; k<n; ++k) {
	z[i][j]+=x[i][k]*y[k][j];
      }
    }
  }
  /*  cout<<"Debugging\n";
  size_t len=z.size();
  for(int i=0;i<len;i++) {
    cout<<z[i]<<endl;
    }*/

}

void divide(const matrix& X,matrix& A, matrix& B, matrix &C, matrix& D,size_t n) {
  for(int i=0;i<n/2;++i) {
    for(int j=0;j<n/2;++j) {
      A[i][j]=X[i][j];
      B[i][j]=X[i][j+(n/2)];
      C[i][j]=X[i+(n/2)][j];
      D[i][j]=X[i+(n/2)][j+(n/2)];
    }
  }

}

void combine(matrix& Z,matrix& C1,matrix& C2,matrix& C3,matrix& C4,size_t n) {
  for(int i=0;i<n;++i) {
    for(int j=0;j<n;++j) {
      //      cout<<"i: "<<i<<" j: "<<j<<endl;
      if(i<n/2 && j<n/2) {
	Z[i][j]=C1[i][j];
      } else if(i<n/2 && j>=n/2) {
	Z[i][j]=C2[i][j-(n/2)];
      }else if(i>=n/2 && j<n/2) {
	Z[i][j]=C3[i-(n/2)][j];
      } else {
	Z[i][j]=C4[i-(n/2)][j-(n/2)];
      }
    }
  }
}

matrix operator+(const matrix& x,const matrix& y) {
  size_t n=x.size();
  matrix z(n,vector<int>(n,0));
  for(int i=0;i<n;++i) {
    for(int j=0;j<n;++j) {
      z[i][j]=x[i][j]+y[i][j];
    }
  }
  return z;
}


matrix operator-(const matrix& x,const matrix& y) {
  size_t n=x.size();
  matrix z(n,vector<int>(n,0));
  for(int i=0;i<n;++i) {
    for(int j=0;j<n;++j) {
      z[i][j]=x[i][j]-y[i][j];
    }
  }
  return z;
}
