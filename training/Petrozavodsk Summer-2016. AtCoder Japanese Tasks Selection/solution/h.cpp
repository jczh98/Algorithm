#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

const int MX = 100000;

int N, C[MX], A[MX];

struct Calc {
  struct seg {
    vector<int> d; int x2;
    seg(){}
    seg(int mx){ x2 = 1; while(x2 < mx) x2 <<= 1; d.resize(x2<<1,-1);}
    void add(int i, int x){
      for(i+=x2,d[i]=x,i>>=1;i;i>>=1) {
        d[i] = min(d[i<<1],d[i<<1|1]);
      }
    }
    int get(int x) {
      int i = 1;
      while (i < x2) {
        i <<= 1;
        if (d[i] >= x) i |= 1;
      }
      return i-x2;
    }
  };
  vector<int> d;
  Calc():d(N){}
  void calc() {
    seg t(N);
    for (int i = 0; i < N; ++i) {
      d[i] = t.get(i-C[i]);
      t.add(d[i],i);
    }
  }
};

int main() {
  scanf("%d",&N);
  for (int i = 1; i < N; ++i) scanf("%d%d",&C[i],&A[i]);
  Calc x; x.calc();
  int sum = 0;
  for (int i = 1; i < N; ++i) if (A[i]&1) sum ^= x.d[i];
  cout << (sum?"First":"Second") << endl;
  return 0;
}
