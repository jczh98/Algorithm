#include <bits/stdc++.h>
using namespace std;
struct node {
    int x,y,dir;
    node(int x=0,int y=0,int dir=0):x(x),y(y),dir(dir){}
}cur,tmp;
int t,r,c,q,sr,sc,sdir,step,R[1000],ans;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
char readin[10],G[1000][1000];
vector<node> path;
node walk(int x,int y,int dir) {
    while(true) {
        int nx=x+dx[dir],ny=y+dy[dir];
        if(G[nx][ny]=='#') dir=(dir+1)%4;
        else return node(nx,ny,dir);
    }
}
int main() {
    freopen("reduce.in","r",stdin);
    R['U']=0;R['R']=1;R['D']=2;R['L']=3;
    scanf("%d",&t);
    while(t--) {
        path.clear();
        scanf("%d%d%d",&r,&c,&q); ans=0;
        scanf("%d%d%s",&sr,&sc,readin); sdir=R[readin[0]];
        cur.x=sr;cur.y=sc;cur.dir=sdir;
        for(int i=1;i<=r;++i) scanf("%s",G[i]+1);
        for(int i=1;i<=q;++i) {
            scanf("%s",readin);
            if(readin[0]=='R') {
                cur.dir=(cur.dir+1)%4;
            }else if(readin[0]=='F') {
                scanf("%d",&step);
                while(step--) {
                    cur=walk(cur.x,cur.y,cur.dir);
                    path.push_back(cur);
                }
            }
        }
        cur.x=sr;cur.y=sc;cur.dir=sdir;step=0;
        while(step<path.size()) {
            tmp=walk(cur.x,cur.y,cur.dir);
            if(tmp.x==path[step].x&&tmp.y==path[step].y) {
                while(step<path.size()&&tmp.x==path[step].x&&tmp.y==path[step].y) {
                    cur=tmp; tmp=walk(cur.x,cur.y,cur.dir);
                    step++;
                }
            }else {
                cur.dir=(cur.dir+1)%4;
            }
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}