#include <bits/stdc++.h>
using namespace std;
int m;char logo[200][200];
int main() {
    scanf("%d",&m);
    for(int i=1;i<=m;++i)for(int j=1;j<=2*m+1;++j)logo[i][j]=' ';
    for(int i=1;i<=m;++i)logo[i][1]=logo[i][m]=logo[i][m+2]=logo[i][m*2+1]='*';
    for(int j=m+2;j<=2*m+1;++j)logo[1][j]='*';
    for(int j=1;j<=m;++j)logo[m][j]='*';
    for(int i=1;i<=m;++i) {
        for(int j=1;j<=2*m+1;++j) {
            printf("%c",logo[i][j]);
        }
        printf("\n");
    }
    return 0;
}