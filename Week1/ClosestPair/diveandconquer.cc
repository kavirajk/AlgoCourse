#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<iterator>
#include<limits>
#include<utility>
#include<cmath>

using namespace std;

typedef pair<int,int> point;
typedef pair<point,point> p_point;

const string i_file="data.txt";
const string o_file="output_better.txt";

void loadFile(ifstream& input,vector<point>& p);

p_point closestPair(const vector<point>& px,const vector<point>& py,double& closest_distance);
p_point closestSplitPair(const vector<point>& px,const vector<point>& py,double& closest_distance,double min_distance);

bool sortByX(const point& a,const point& b);
bool sortByY(const point& a,const point& b);

ofstream& operator<<(ofstream& out,const p_point& p);

p_point computeBase(const vector<point>& px,const vector<point>& py,double& closest_distance);
double computeDistance(const point& a,const point&b);

int main() {
  ifstream input(i_file.c_str());
  ofstream output(o_file.c_str());

  vector<point> p,px,py;
  double closest_distance;

  loadFile(input,p);
  px=py=p;

  sort(px.begin(),px.end(),sortByX);
  sort(py.begin(),py.end(),sortByY);

  p_point closest_pair = closestPair(px,py,closest_distance);

  output<<closest_pair<<endl;
  output<<closest_distance<<endl;

  return 0;
}

void loadFile(ifstream& input,vector<point>& p) {
  int x,y;
  while(input>>x>>y) {
    p.push_back(make_pair(x,y));
  }
}

bool sortByX(const point& a,const point& b) {
  return a.first<b.first;
}

bool sortByY(const point& a,const point& b) {
  return a.second<b.second;
}

ofstream& operator<<(ofstream& out,const p_point& p) {
  out<<"("<<p.first.first<<", "<<p.first.second<<")"<<endl;
  out<<"("<<p.second.first<<", "<<p.second.second<<")";
}

p_point closestPair(const vector<point>& px,const vector<point>& py,double& closest_distance) {
  size_t n=px.size()/2;
  p_point closest_pair;
  if(n<=3) {
    closest_pair=computeBase(px,py,closest_distance);
    return closest_pair;
  }
  p_point l_closest_pair,r_closest_pair,split_closest_pair,min_closest_pair;
  double l_closest_distance,r_closest_distance,min_closest_distance,split_closest_distance;
  vector<point> qx,qy,rx,ry;
  
  copy(px.begin(),px.begin()+n,back_inserter(qx));
  copy(px.begin()+n,px.end(),back_inserter(rx));

  copy(py.begin(),py.begin()+n,back_inserter(qy));
  copy(py.begin()+n,py.end(),back_inserter(ry));

  l_closest_pair=closestPair(qx,qy,l_closest_distance);
  r_closest_pair=closestPair(rx,ry,r_closest_distance);

  min_closest_distance=min(l_closest_distance,r_closest_distance);
  min_closest_pair=min(l_closest_pair,r_closest_pair);
  
  split_closest_pair=closestSplitPair(px,py,split_closest_distance,min_closest_distance);

  if(split_closest_distance<min_closest_distance) {
    closest_distance=split_closest_distance;
    return split_closest_pair;
  }

  closest_distance=min_closest_distance;
  return min_closest_pair;

}

p_point computeBase(const vector<point>& px,const vector<point>& py,double& closest_distance) {
  size_t n=px.size();
  p_point closest_pair=make_pair(px[0],px[1]);
  closest_distance=computeDistance(px[0],px[1]);
  
  for(int i=1;i<n-1;++i) {
    for(int j=i+1;j<n;++j) {
      double tmp=computeDistance(px[i],px[j]);
      if(tmp<closest_distance) {
	closest_pair.first=px[i];
	closest_pair.second=px[j];
	closest_distance=tmp;
      }
    }
  }
  return closest_pair;
}

double computeDistance(const point& a,const point& b) {
  return sqrt(pow((double)(a.first-b.first),2)+ pow((double)(a.second-b.second),2));
}

p_point closestSplitPair(const vector<point>& px,const vector<point>& py,double& closest_distance,double min_distance) {
  vector<point> sy;
  size_t n=px.size();
  p_point closest_pair;
  int lower_limit=px[n/2].first - (int)min_distance;
  int higher_limit=px[n/2].first + (int)min_distance;

  for(int i=0; i<n; i++) {
    if(py[i].first > lower_limit && py[i].first <= higher_limit ) {
      sy.push_back(py[i]);
    }
  }

  closest_distance=min_distance;
  double best_so_far=min_distance;
  size_t len=sy.size();
  len=(len>7)?(len-7):(len);
  for(int i=0; i<len; ++i) {
    for(int j=0;j<7 && (i+j)<len;++j) {
      best_so_far=computeDistance(sy[i],sy[i+j]);
      if(best_so_far<closest_distance) {
	closest_distance=best_so_far;
	closest_pair.first=sy[i];
	closest_pair.second=sy[i+j];
      }
    }
  }

}
