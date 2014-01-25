#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<utility>
#include<cmath>
#include<limits>

using namespace std;

typedef pair<int,int> point;
typedef pair<point,point> p_pair;

const string i_file="data.txt";
const string o_file="output_naive.txt";

void loadFile(ifstream& input,vector<point>& p);
double computeDistance(const point& x,const point& y);
p_pair naive_algorithm(const vector<point>& p,double& closest_distance);

ofstream& operator<<(ofstream& out,const p_pair& closest);

int main() {
  ifstream input(i_file.c_str());
  ofstream output(o_file.c_str());

  vector<point> p;
  double closest_distance;

  loadFile(input,p);

  p_pair closest=naive_algorithm(p,closest_distance);

  output<<closest<<endl;
  output<<closest_distance<<endl;

  input.close();
  output.close();
  
  return 0;
}

void loadFile(ifstream& input,vector<point>& p) {
  long x,y;
  while(input>>x>>y) {
    p.push_back(make_pair(x,y));
  }
}

double computeDistance(const point& x,const point& y) {
  double distance=sqrt(pow((x.first-y.first),2) + pow((x.second-y.second),2));
  return distance;
}

ofstream& operator<<(ofstream& out,const p_pair& closest) {
  out<<"("<<closest.first.first<<", "<<closest.first.second<<")"<<endl;
  out<<"("<<closest.second.first<<", "<<closest.second.second<<")";
}

p_pair naive_algorithm(const vector<point>& p,double& closest_distance) {
  size_t n=p.size();
  double best=numeric_limits<double>::max();
  p_pair result;
  for(int i=0;i<n;++i) {
    for(int j=i+1;j<n;++j) {
      double tmp=computeDistance(p[i],p[j]);
      if(tmp<best) {
	best=tmp;
	result.first=p[i];
	result.second=p[j];
      }
    }
  }
  closest_distance=best;

  return result;
}
