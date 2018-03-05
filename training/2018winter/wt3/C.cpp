#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct Point {
    LL x,y,z;
    Point(LL x=0,LL y=0,LL z=0):x(x),y(y),z(z){}
    Point operator-(const Point& rhs) const{return Point(x-rhs.x,y-rhs.y,z-rhs.z);}
}p[5005];
int n,ans=0,vis[5005];
bool judge(Point a,Point b,Point c) {
    Point aa=a-b;Point bb=a-c;
    if(aa.x*bb.y==aa.y*bb.x&&aa.x*bb.z==aa.z*bb.x&&aa.y*bb.z==aa.z*bb.y)return true;
    return false;
}
int main() {
    memset(vis,0,sizeof(vis));
    scanf("%d",&n);
    for(int i=1;i<=n;++i) {
        cin>>p[i].x>>p[i].y>>p[i].z;
    }
    for(int i=2;i<=n;++i) {
        if(vis[i])continue;
        ans++;vis[i]=1;
        for(int j=i+1;j<=n;++j) {
            if(judge(p[1],p[i],p[j])) vis[j]=1;
        }
    }
    printf("%d\n",ans);
    return 0;
}