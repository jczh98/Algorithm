#include<cstdio>
#include<cstring>

const int len = 32;
const int MAXN = 1024 + 10;
char s[MAXN];
int mat[len][len],ans;

void Build(const char* s,int& p,int r,int c,int w) {
    char ch=s[p++];
    if(ch=='p')
    {
        Build(s,p,r,c+w/2,w/2);
        Build(s,p,r,c,w/2);
        Build(s,p,r+w/2,c,w/2);
        Build(s,p,r+w/2,c+w/2,w/2);
    } else if(ch=='f')
    {
        for(int i=r;i<r+w;i++)
          for(int j=c;j<c+w;j++)
           if(mat[i][j]==0) {mat[i][j]=1;ans++;}
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--)
    {
        memset(mat,0,sizeof(mat));
        ans=0;
        for(int i=0;i<2;i++) {
            scanf("%s",s);
            int p=0;
            Build(s,p,0,0,len);
        }
        printf("There are %d black pixels.\n", ans);
    }
    return 0;
}
