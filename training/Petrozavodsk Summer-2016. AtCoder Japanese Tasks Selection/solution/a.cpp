#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<cmath>
using namespace std;

typedef long long Int;
typedef pair<double, double> DP;
typedef pair<Int, Int> P;

#define EPS (1e-8)
#define SQ(x) ((x) * (x))
#define ONLINE 0
#define CCW 1
#define CW -1
#define INF (1e20)
#define abs(x) ((x) < 0?(-(x)):(x))
	Int pp= 0;

vector<P> ps;
vector<DP> points[648000];

int ccw(DP a, DP b, DP c){
  b.first -= a.first;b.second -= a.second;
  c.first -= a.first;c.second -= a.second;
  double p = b.first * c.second - c.first * b.second;
  if(abs(p) < EPS)return ONLINE;
  if(p > 0)return CCW;
  if(p < 0)return CW;
}

vector<P> convex(vector<P> x){
  vector<P> res;
  res.push_back(x[0]);
  for(int i = 1;i < x.size();i++){
    while(res.size() > 1){
      int p = ccw(res[res.size() - 2], res[res.size() - 1], x[i]);
      if(p == CW || p == ONLINE)res.pop_back();
      else break;
    }
    res.push_back(x[i]);
  }
  int k = res.size();
  for(int i = x.size() - 2;i >= 0;i--){
    while(res.size() > k){
      int p = ccw(res[res.size() - 2], res[res.size() - 1], x[i]);
      if(p == CW || p == ONLINE)res.pop_back();
      else break;
    }
    res.push_back(x[i]);
  }
  res.pop_back();
  return res;
}


DP cross(P a, P b){
	if(a.first == b.first)return DP(a.first * 2, 0);
	if(a.second == b.second)return DP(0, a.second * 2);
	double p = 2.0 * (a.first * b.second - a.second * b.first) / (SQ(a.first - b.first) + SQ(a.second - b.second));
	return DP(-p * (a.second - b.second), p * (a.first - b.first));
}

vector<DP> crosspoint(P c, Int y){
	vector<DP> res;
	Int p = y * y - 2 * c.second * y;
	Int d = 4 * c.first * c.first - 4 * p;
	if(d < 0)return res;
	if(d == 0){
		res.push_back(DP(c.first, y));
	}
	if(d > 0){
		res.push_back(DP((double)c.first - sqrt(d) / 2, y));
		res.push_back(DP((double)c.first + sqrt(d) / 2, y));
	}
	return res;
}

void check_edges(P c, DP from, DP to){
	Int bottom = min(from.second, to.second) - 2;
	Int top = max(from.second, to.second) + 2;
	if(from == to || ccw(from, DP(c.first, c.second + hypot(c.first, c.second)), to) == CCW){
		  top = c.second + hypot(c.first, c.second) + 2;
	}
	if(from == to || ccw(from, DP(c.first, c.second - hypot(c.first, c.second)), to) == CCW){
		  bottom = c.second - hypot(c.first, c.second) - 2;
	}
	pp += top - bottom + 1;
	vector<DP> cp;
	for(Int i = bottom;i <= top;i++){
		cp = crosspoint(c, i);
		if(cp.empty())continue;
		if(cp.size() == 1){
		  if(ccw(from, cp[0], to) != CW){
				points[i + 324000].push_back(DP(cp[0].first, 0));
			}
			continue;
		}
		if(cp.size() == 2){
			if(ccw(from, cp[0], to) != CW){
				points[i + 324000].push_back(DP(cp[0].first, 1));
			}
			if(ccw(from, cp[1], to) != CW){
				points[i + 324000].push_back(DP(cp[1].first, -1));
			}
		}
	}
}


int main(){
	int n, x, y;
	Int res = 0;
  cin >> n;
  for(int i = 0;i < n;i++){
    cin >> x >> y;
    ps.push_back(P(x, y));
  }
  ps.push_back(P(0, 0));
  sort(ps.begin(), ps.end());
  vector<P> conv = convex(ps);
  DP from = cross(conv.front(), conv.back());
  for(int i = 0;i < conv.size();i++){
    DP to = cross(conv[i], conv[(i + 1) % conv.size()]);
		if(abs(conv[i].first) > EPS || abs(conv[i].second) > EPS){
	    check_edges(conv[i], from, to);
		}
    from = to;
  }
	vector<DP> tmp;
  for(int i = 0;i < 648000;i++){
		if(points[i].empty())continue;
		tmp.clear();
    sort(points[i].begin(), points[i].end());
		pp += points[i].size();
    for(int j = 0;j < points[i].size();j++){
			if(!tmp.empty() && abs(points[i][j].first - tmp.back().first) < EPS){
				if(tmp.back().second == -1 && points[i][j].second == 1){
					tmp.pop_back();
					continue;
				}					 
				if(tmp.back().second == 0 && points[i][j].second == 0){
					continue;
				}					 
				if(tmp.back().second == -1)continue;
				if(points[i][j].second == 1){
					tmp.pop_back();
				}
			}
			tmp.push_back(points[i][j]);
		}
		for(int j = 0;j < tmp.size();j++){
			if(tmp[j].second == 0)res++;
			else{
				res += floor(tmp[j + 1].first + 1 + EPS) - floor(tmp[j].first + 1 - EPS);
				j++;
			}
		}
  }
	cout << res << endl;
	return 0;
}
