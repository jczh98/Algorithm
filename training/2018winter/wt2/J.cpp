#include <bits/stdc++.h>
using namespace std;
struct data{
    int use,rec,s,tot;
}cur[10],pep[10];
int main() {
    for(int i=1;i<=10;++i) {
        scanf("%d%d",&cur[i].use,&cur[i].rec);
        cur[i].tot=cur[i].use+cur[i].rec;
    }
    for(int i=1;i<=10;++i) {
        scanf("%d%d%d",&pep[i].use,&pep[i].rec,&pep[i].s);
        pep[i].tot=pep[i].use+pep[i].rec;
    }
    int times=0;
    for(int i=1;i<=3;++i) {
        for(int j=1;j<=10;++j) {
            if(times>=pep[j].s&&(times-pep[j].s)%pep[j].tot<=pep[j].use) {
                times+=pep[j].use-(times-pep[j].s)%pep[j].tot;
            }
            if(times>=pep[j].s) {
                pep[j].s=times-(times-pep[j].s)%pep[j].tot;
            }   
            if(pep[j].s+pep[j].tot<times+cur[j].use) {
                pep[j].s=times+cur[j].use;
            }
            if(times<pep[j].s&&times+cur[j].use>pep[j].s) {
                pep[j].s=times+cur[j].use;
            }
            times += cur[j].tot;
        }
    }
    printf("%d\n", times-cur[10].rec);
}