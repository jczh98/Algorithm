#include <cstdio>
#include <iostream>
using namespace std;

int n,m=0;

int main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        m+=n/i;
    }
    cout<<m;
}
