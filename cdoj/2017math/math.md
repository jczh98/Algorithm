# A - 七夜雪寂，一世人心 SG函数

## 题意

多堆石子，双方轮流任取集合$s$中$s_i$ ，取走等量石子，求先手的胜负

---

预处理单堆sg函数，最后求游戏异或和，和不为0先手必胜

复杂度$O(n^2)-O(n)$

## 代码

```cpp
#include <bits/stdc++.h>
#define MN 10010
using namespace std;
//int sg[7]={0,0,1,1,0,2,1};
int s[MN],k,m,t,h[MN],vis[MN],sg[MN];
int main()
{
    scanf("%d",&k);
    for(int i=1;i<=k;i++)scanf("%d",&s[i]);
    for(int i=1;i<=MN;i++)
    {
        memset(vis,0,sizeof(vis));
        for(int j=1;j<=k;j++)if(i-s[j]>=0)vis[sg[i-s[j]]]=1;
        for(int j=0;j<=MN;j++)if(!vis[j]){sg[i]=j;break;}
    }
    //for(int i=0;i<=100;i++)printf("%d ",sg[i]);
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d",&t);
        for(int i=1;i<=t;i++)
        {
            scanf("%d",&h[i]);
        }
        int ans=sg[h[1]];
        for(int i=2;i<=t;i++)
        {
            ans^=sg[h[i]];
        }
        printf("%s\n",ans==0?"lose!":"win!");
    }
    return 0;
}
```

# B - 无关青云路，无关诗书，无你处，无江湖 两圆面积交

## 题意

求两圆面积交

---

用余弦定理求出两夹角，求出面积再减去重合

## 代码

```cpp
#include <bits/stdc++.h>
#define pi acos(-1.0)
using namespace std;
int t,x_1,y_1,r_1,x_2,y_2,r_2;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d%d%d",&x_1,&y_1,&r_1,&x_2,&y_2,&r_2);
        double dis=sqrt((x_1-x_2)*(x_1-x_2)+(y_1-y_2)*(y_1-y_2));
        if(dis>=r_1+r_2)printf("0.000000\n");
        else
        {
            if(r_1<r_2)swap(r_1,r_2);
            if(r_1-r_2>=dis)printf("%.6f\n",pi*r_2*r_2);
            else
            {
                double theta2=acos((r_2*r_2+dis*dis-r_1*r_1)/2.0/r_2/dis);
                double theta1=acos((r_1*r_1+dis*dis-r_2*r_2)/2.0/r_1/dis);
                printf("%.6f\n",theta2*r_2*r_2+theta1*r_1*r_1-sin(theta1)*r_1*dis);
            }
        }
    }
    return 0;
}

```

# C - 借你算无遗策,吟啸徐听,打叶穿林 凸包周长

## 题意

给定平面n个点，求覆盖所有点的多边形边界外长度l的多边形周长

---

凸包求出平面点集的最小覆盖，在此基础上求出凸包的周长，再加上以$l$为半径的圆的周长（证明是对多边形的每个角划分，可以发现划分之后的角度和为360）

复杂度$O(nH)$

## 代码

```cpp
#include <bits/stdc++.h>
#define MN 1010
#define pi acos(-1.0)
using namespace std;
struct Point
{
    int x,y;
    Point(int x=0,int y=0):x(x),y(y){}
    bool operator < (const Point &rhs) const {return x<rhs.x||(x==rhs.x&&y<rhs.y);}
    Point operator - (const Point &rhs) const {return Point(x-rhs.x,y-rhs.y);}
    int operator ^ (const Point &rhs) const {return x*rhs.y-y*rhs.x;}
}a[MN],p[MN];
double Length(Point a,Point b){return sqrt((double)(a.x-b.x)*(a.x-b.x)+(double)(a.y-b.y)*(a.y-b.y));}
int n,l;
double ans=0.0;
int ConvexHull()
{
    sort(a+1,a+1+n);
    int top=0;
    for(int i=1;i<=n;i++)
    {
        while(top>1&&((p[top]-p[top-1])^(a[i]-p[top-1]))<=0)top--;
        p[++top]=a[i];
    }
    int k=top;
    for(int i=n-1;i>=1;i--)
    {
        while(top>k&&((p[top]-p[top-1])^(a[i]-p[top-1]))<=0)top--;
        p[++top]=a[i];
    }
    return top-1;
}
int main()
{
    scanf("%d%d",&n,&l);
    for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y);
    int m=ConvexHull();
    for(int i=1;i<m;i++)ans+=Length(p[i],p[i+1]);
    ans+=Length(p[1],p[m]);
    ans+=2.0*pi*l;
    printf("%d\n",(int)(ans+0.5));
    return 0;
}


```



# D - 京电的碧绿航线 中国剩余定理

## 题意

有6个船，每个船有一个周期，求过多少时间他们周期刚好第一次重叠

---

设$x$天重叠，可以列出方程$x \equiv b_i \pmod {a_i},i=1,2,3,4,5,6$，然后题目给定$a_i$互质，用中国剩余定理解出最小解就行

。。。不过这题到这还没完。。。

> 我们记录了一艘船每个属性某次顶峰的时间为第bi天，我们想知道**之后(如果今天就可以也算)**第一个可能达到去6-4要求的时间为多少

也就是说,答案一定要大于$max(b_i)$

复杂度$O(nlog(n))$

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL r[100],primes[100],ans,mx=-1;
LL Exgcd(LL a,LL b,LL &x,LL &y)
{
    LL d;
    if(b==0)
    {
        x=1;y=0;
        return a;
    }
    d=Exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
LL ChineseRemainder(int len)
{
    LL d,x,y,m,n=1,tans;
    LL sum=0;
    for(int i=1;i<=len;i++)n*=primes[i];
    for(int i=1;i<=len;i++)
    {
        m=n/primes[i];
        d=Exgcd(primes[i],m,x,y);
        sum=(sum+(LL)y*(LL)m*r[i])%n;
    }
    tans=(n+sum%n)%n;
    if(tans<mx)tans+=n*(int)ceil((double)(mx-tans)/n);
    return tans;
}
int main()
{
    for(int i=1;i<=6;i++)cin>>primes[i];
    for(int i=1;i<=6;i++)cin>>r[i],mx=max(r[i],mx);
    LL ans=ChineseRemainder(6);
    cout<<ans<<endl;
    return 0;
}


```

# E - 京电的会议室 排列组合 

## 题意

n个男生和n个女生，一男一女安排在圆桌

---

$n*(n-1)!$

先将一男一女捆绑，然后问题转换为安排$n$个人在圆桌有多少不同的排列

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
LL ans=1;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)ans*=i;
    ans*=ans*n;
    printf("%lld",ans);
    return 0;
}

```

# F - 京电的神秘矩阵 双hash

## 题意

求矩阵中有多少不重复元素

该矩阵的第一列是$a^b,(a+1)^b,......,(a+n−1)^b$
第二列是$a^{b+1},(a+1)^{b+1},......,(a+n−1)^{b+1}$
.......
第$m$列是$a^{b+m−1},(a+1)^{b+m−1},.....(a+n−1)^{b+m−1}$

---

（潘爷做法）用快速幂求出每个数在1e9+7和1e9+9下的值，组成一个pair，然后利用set去重统计集合元素

复杂度$O(nm)$

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int m,n,a,b,tot;
set<pair<LL,LL>> st;
LL QuickPow(LL a,LL b,LL mod)
{
    LL res=1;
    while(b)
    {
        if(b&1)res*=a,res=res%mod;
        a*=a;a%=mod;
        b>>=1;
    }
    return res;
}
int main()
{
    scanf("%d%d%d%d",&m,&n,&a,&b);
    for(int i=a;i<a+n;i++)
        for(int j=b;j<b+m;j++)
            st.insert(make_pair(QuickPow(i,j,1e9+7LL),QuickPow(i,j,1e9+9LL)));
    printf("%d\n",st.size());
    return 0;
}

```

# G - 京电的期末考试 组合

## 题意

给定01串，求出所有满足长度为偶数，前一半为0后一半为1的子串个数

---

最开始没去重，看了ppt总算是才做出来orz

假设他及左边有$l$个0，右边有$r$个1，则答案为$∑_{i=0}^{min⁡(l,r)} C (l,i)∗C(r,i) - ∑_{i=0}^{min⁡(l-1,r)}C(l-1,i)∗C(r,i)$

根据范德蒙恒等式我们有$∑_{i=0}^{min⁡(l,r)} C(l,i)∗C(r,i)=C(l+r,l)$

所以就可以通过预处理阶乘和其的逆元的结果来快速计算答案，

逆元可以由线性递推得到

复杂度$O(n)$

## 代码

```cpp
#include <bits/stdc++.h>
#define MOD (long long)(1e9+7)
using namespace std;
typedef long long LL;
char str[200200];
int cnt[200200][2]={0};
LL fac[400500],inv[400500],ans=0;
LL QuickPow(LL a,LL b)
{
    LL res=1;
    while(b)
    {
        if(b&1)res=(res*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}
void Pre()
{
    fac[0]=1;int N=400400;
    for(int i=1;i<=N;i++)fac[i]=(fac[i-1]*i)%MOD;
    inv[N]=QuickPow(fac[N],MOD-2);
    for(int i=N-1;i>=0;i--)inv[i]=inv[i+1]*(i+1)%MOD;
}
int main()
{
    Pre();
    scanf("%s",str);
    int cnt0=0,cnt1=0,len=strlen(str),mx;
    for(int i=0;i<len;i++)
    {
        if(str[i]=='0')cnt0++;cnt[i][0]=cnt0;
        if(str[i]=='1')cnt1++;cnt[i][1]=cnt1;
    }
    for(int i=0;i<len;i++)
    {
        if(str[i]=='1')continue;
        int l=cnt[i][0],r=cnt[len-1][1]-cnt[i][1];
        ans+=(((fac[l+r])%MOD*(inv[l])%MOD*(inv[r])%MOD)%MOD-((fac[l+r-1])%MOD*(inv[l-1])%MOD*(inv[r])%MOD)%MOD+MOD)%MOD;
    }
    printf("%lld",(ans+MOD)%MOD);
    return 0;
}

```

# H - 计算树数

## 题意

两人轮流在树上操作，树上每个节点有若干石子，每次可以拿任意（大于0）的石子放到父节点，父节点的石子可以直接拿走，谁不能操作便输，求有多少子树满足先手必胜

---

树形阶梯博弈，对于其中一个子树，nim和等于所有偶数深度的节点的sg函数值的异或，回溯处理每个节点以他为根节点的sg异或值

```cpp
#include <bits/stdc++.h>
#define MN 300300
using namespace std;
int n,stone[MN],fa[MN],sum;
vector<int> v[MN],vv[MN];
void Dfs(int u,int &xor0,int &xor1)
{
    xor0=stone[u];xor1=0;int t1=0,t0=0;
    for(int i=0;i<v[u].size();i++)
    {
        t1=t0=0;
        Dfs(v[u][i],t1,t0);
        xor1^=t1,xor0^=t0;
    }
    if(xor0)sum++;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        for(int i=0;i<n;i++)v[i].clear();
        for(int i=1;i<n;i++)scanf("%d",&fa[i]),v[fa[i]].push_back(i);
        for(int i=0;i<n;i++)scanf("%d",&stone[i]);
        int x1=0,x0=0;
        Dfs(0,x0,x1);
        printf("%d\n",sum);
    }
    return 0;
}

```



# I - 几何几何 线段交

## 题意

给定两个线段，求围城的图形是否形成一个向上的凹槽

---

特殊情况判定+精度

```cpp


#include <bits/stdc++.h>
#define eps 1e-7
using namespace std;
int dcmp(double x)
{
    if(fabs(x)<eps)return 0;
    else return x<0?-1:1;
}
struct Point
{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
    bool operator < (const Point &rhs) const {return x<rhs.x||(x==rhs.x&&y<rhs.y);}
    Point operator - (const Point &rhs) const {return Point(x-rhs.x,y-rhs.y);}
    Point operator + (const Point &rhs) const {return Point(x+rhs.x,y+rhs.y);}
    Point operator * (const double p) { return Point(x*p,y*p) ;}
    Point operator / (const double p) {return Point(x/p,y/p);}
    bool operator == (const Point &rhs) const {return dcmp(x-rhs.x)==0&&dcmp(y-rhs.y)==0;}
};
typedef Point Vector;
double Cross(Point a,Point b){return a.x*b.y-a.y*b.x;}
double Dot(Point a,Point b){return a.x*b.x+a.y*b.y;}
double Length(Point a,Point b){return sqrt((double)(a.x-b.x)*(a.x-b.x)+(double)(a.y-b.y)*(a.y-b.y));}
double Length(Vector a) {return sqrt(Dot(a,a));}
bool Onsegment(Point p,Point a,Point b)
{
    return dcmp(Cross(b-a,p-a)) == 0 && dcmp(Dot(b-p,a-p)) < 0 || (p == a) || (p == b);
}
bool OnLine(Point p,Point a,Point b)
{
    return fabs(Cross(p-a,a-b))/Length(b-a);
}
bool SegmentIntersection(Point a,Point b,Point c,Point d)
{
    double d1 = Cross(b-a,c-a),d2 = Cross(b-a,d-a),d3 = Cross(d-c,a-c),d4 = Cross(d-c,b-c);
    if(dcmp(d1)*dcmp(d2) < 0 || dcmp(d3)*dcmp(d4) < 0) return true;
    else if(dcmp(d1) == 0 && !OnLine(c,a,b) ) return true;
    else if(dcmp(d2) == 0 && !OnLine(d,a,b) ) return true;
    else if(dcmp(d3) == 0 && !OnLine(a,c,d) ) return true;
    else if(dcmp(d4) == 0 && !OnLine(b,c,d) ) return true;
    else return false;
}
bool Segmentsection(Point a,Point b,Point c,Point d)
{
    double d1 = Cross(b-a,c-a),d2 = Cross(b-a,d-a),d3 = Cross(d-c,a-c),d4 = Cross(d-c,b-c);
    if(dcmp(d1)*dcmp(d2) < 0 && dcmp(d3)*dcmp(d4) < 0) return true;
    else if(dcmp(d1) == 0 && Onsegment(c,a,b) ) return true;
    else if(dcmp(d2) == 0 && Onsegment(d,a,b) ) return true;
    else if(dcmp(d3) == 0 && Onsegment(a,c,d) ) return true;
    else if(dcmp(d4) == 0 && Onsegment(b,c,d) ) return true;
    else return false;
}
bool pointInpoly(Point p,Point a,Point b,Point c,Point d)
{
    double d1 = Cross(b-a,p-a);
    double d2 = Cross(d-c,p-c);
    double d3 = Cross(c-b,p-b);
    double d4 = Cross(a-d,p-d);
    return dcmp(d1)*dcmp(d2) > 0 && dcmp(d3)*dcmp(d4) > 0;
}
Point Segment(Point p,Vector v,Point q,Vector w)
{
    Vector u = p-q;
    double t = Cross(w,u) / Cross(v,w);
    return p + v*t;
}
struct Line
{
    Point s,e;
    Line(Point s = 0,Point e = 0) :s(s),e(e){}
};
Point Max(Point a,Point b)
{
    return a.y > b.y ? a : b;
}
Point a,b,c,d;
int main()
{
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&d.x,&d.y)!=EOF)
    {
        Point P1=Max(a,b),P2=Max(c,d);
        if(!Segmentsection(a,b,c,d)) printf("0.00\n");
        else if(a.y == b.y || c.y == d.y) printf("0.00\n");
        else if(!Cross(b-a,c-d)) printf("0.00\n");
        else
        {
            Point k=Segment(a,b-a,c,d-c),P3=Point(P1.x,P1.y+1),P4=Point(P2.x,P2.y+1);
            if(SegmentIntersection(P1,P3,c,d))
            {
                Point k1=Segment(P1,P3-P1,c,d-c);
                if(Onsegment(k1,P2,k))
                {
                    if(dcmp(P1.y-k1.y)<=0)
                    {
                        printf("0.00\n");continue;
                    }
                }
            }
            if(SegmentIntersection(P2,P4,a,b))
            {
                Point k1=Segment(P2,P4-P2,a,b-a);
                if(Onsegment(k1,P1,k))
                {
                    if(dcmp(P2.y-k1.y)<=0)
                    {
                         printf("0.00\n");continue;
                    }
                }
            }
            P3=Point(P1.x+1,P1.y);
            P4=Point(P2.x+1,P2.y);
            if(SegmentIntersection(P1,P3,c,d))
            {
                Point k1=Segment(P1,P3-P1,c,d-c);
                if(Onsegment(k1,P2,k))printf("%.2lf\n",fabs(Cross(P1-k,k1-k))/2);continue;
            }
            if(SegmentIntersection(P2,P4,a,b))
            {
                Point k1 = Segment(P2,P4-P2,a,b-a);
                if(Onsegment(k1,P1,k))printf("%.2lf\n",fabs(Cross(P2-k,k1-k))/2);continue;
            }
        }
    }
    return 0;
}

```

# J - DP不可做？数学

## 题意

给定n,m矩阵，求1*2的骨牌覆盖方案使得每一横线每一竖线都被至少一块骨牌覆盖

---

从cx大爷发的链接看来是个奥妙重重的数学题，对着spj生成数据系列

http://www.matrix67.com/blog/archives/5550

正统题解，顺便码一个orz mx67大爷

```cpp
#include <bits/stdc++.h>
using namespace std;
int n,m;
int A[5][6]=
{
 1 , 2 , 2 , 3 , 4 , 4,
 1  ,5,  5 , 3 , 6 , 7,
 8  ,9 ,10 ,10 , 6  ,7,
 8  ,9 ,11, 12, 12 ,13,
14 ,14 ,11 ,15 ,15 ,13
};
int B[6][8]=
{
1,2,2,4,5,5,7,7,
1,3,3,4,6,6,8,9,
10,10,11,12,12,13,8,9,
14,15,11,16,16,13,17,17,
14,15,18,18,19,20,20,21,
22,22,23,23,19,24,24,21
};
int f[1000][1000],b[1000][1000];
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(f,0,sizeof(f));
        if(n==1&&m==2)
        {
            printf("1 1\n");
        }else if(((n*m)&1)||(n<=4||m<=4)||(m==6&&n==6))
        {
            printf("No\n");
        }else
        {
            if((n&1)&&!(m&1))
            {
                int k=16;
                for(int i=1;i<=5;i++)
                {
                    for(int j=1;j<=6;j++)
                    {
                        f[i][j]=A[i-1][j-1];
                    }
                }
                for(int i=1;i<=n;i++)
                {
                    if(f[i][5]==f[i][6])
                    {
                        swap(f[i][5],f[i][m-1]);swap(f[i][6],f[i][m]);
                    }else
                    {
                        swap(f[i][6],f[i][m]);
                    }
                }
                for(int i=1;i<=5;i++)
                {
                    for(int j=1;j<=m;j++)
                    {
                        if(f[i][j]==f[i][j+1]&&f[i][j]==0)
                        {
                            f[i][j]=f[i][j+1]=k;k++;
                        }
                    }
                }
                for(int j=1;j<=m;j++)
                {
                    if(f[4][j]==f[5][j])
                    {
                        swap(f[4][j],f[n-1][j]);swap(f[5][j],f[n][j]);
                    }else
                    {
                        swap(f[5][j],f[n][j]);
                    }
                }
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=m;j++)
                    {
                        if(f[i][j]==f[i+1][j]&&f[i][j]==0)
                        {
                            f[i][j]=f[i+1][j]=k;k++;
                        }

                    }
                }
            }else if(!(n&1)&&!(m&1))
            {
                int k=25;
                for(int i=1;i<=6;i++)
                {
                    for(int j=1;j<=8;j++)
                    {
                        f[i][j]=B[i-1][j-1];
                    }
                }
                for(int i=1;i<=n;i++)
                {
                    if(f[i][7]==f[i][8])
                    {
                        swap(f[i][7],f[i][m-1]);swap(f[i][8],f[i][m]);
                    }else
                    {
                        swap(f[i][8],f[i][m]);
                    }
                }
                for(int i=1;i<=6;i++)
                {
                    for(int j=1;j<=m;j++)
                    {
                        if(f[i][j]==f[i][j+1]&&f[i][j]==0)
                        {
                            f[i][j]=f[i][j+1]=k;k++;
                        }
                    }
                }
                for(int j=1;j<=m;j++)
                {
                    if(f[5][j]==f[6][j])
                    {
                        swap(f[5][j],f[n-1][j]);swap(f[6][j],f[n][j]);
                    }else
                    {
                        swap(f[6][j],f[n][j]);
                    }
                }
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=m;j++)
                    {
                        if(f[i][j]==f[i+1][j]&&f[i][j]==0)
                        {
                            f[i][j]=f[i+1][j]=k;k++;
                        }
                    }
                }
            }else if(!(n&1)&&(m&1))
            {
                swap(n,m);
                int k=16;
                for(int i=1;i<=5;i++)
                {
                    for(int j=1;j<=6;j++)
                    {
                        f[i][j]=A[i-1][j-1];
                    }
                }
                for(int i=1;i<=n;i++)
                {
                    if(f[i][5]==f[i][6])
                    {
                        swap(f[i][5],f[i][m-1]);swap(f[i][6],f[i][m]);
                    }else
                    {
                        swap(f[i][6],f[i][m]);
                    }
                }
                for(int i=1;i<=5;i++)
                {
                    for(int j=1;j<=m;j++)
                    {
                        if(f[i][j]==f[i][j+1]&&f[i][j]==0)
                        {
                            f[i][j]=f[i][j+1]=k;k++;
                        }
                    }
                }
                for(int j=1;j<=m;j++)
                {
                    if(f[4][j]==f[5][j])
                    {
                        swap(f[4][j],f[n-1][j]);swap(f[5][j],f[n][j]);
                    }else
                    {
                        swap(f[5][j],f[n][j]);
                    }
                }
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=m;j++)
                    {
                        if(f[i][j]==f[i+1][j]&&f[i][j]==0)
                        {
                            f[i][j]=f[i+1][j]=k;k++;
                        }

                    }
                }
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=m;j++)
                    {
                        b[j][i]=f[i][j];
                    }
                }
                swap(n,m);
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=m;j++)
                    {
                        f[i][j]=b[i][j];
                    }
                }
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    printf("%d ",f[i][j]);
                }printf("\n");
            }
            printf("\n");
            /*int a[101],b[101];
            for (int i=1;i<=n;++i) a[i]=0;
            for (int j=1;j<=m;++j) b[j]=0;
            for (int i=1;i<=n;++i)
                for (int j=1;j<=m;++j) {
                    if (j!=m&&f[i][j]==f[i][j+1]) b[j]=1;
                    if (i!=n&&f[i][j]==f[i+1][j]) a[i]=1;
                }
            int flag=0;
            for (int i=1;i<n;++i) if(!a[i])flag=1;
            for (int j=1;j<m;++j) if(!b[j])flag=1;
            if(flag)printf("wa\n");*/
        }
    }
    return 0;
}

```



# K - 越快越好！数学

## 题意

$n$个同学速度$v1$ ，车速度$v2$，可以载$k$个人去，每个人只能上一次车，求所有人到达的最小时间

---

所有人到达的最小时间就等于所有人同时到达的时间，所以车不能开满，并且车走的每段距离必须一样且载过所有人，设车每次走$l_1$，对于第一队上车的人，在0时刻上车，$t_1=\frac{l_1}{v_2}$时刻下车，第二队人从第一队人上车的地方往前走，走到$d_1=l_1-v_1t_1$,然后车往回跑，在$t_2=\frac{d_1}{v_1+v_2}$时刻相遇，这时候第三队人走到$d_2=(t_1+t_2)v_1=\frac{2v_1l_1}{v1+v2}$ ,然后会重复之前的过程，设一共有$cnt=\lceil \frac{n}{k} \rceil$次车，所以当最后一队到达时$d=\frac{2(cnt-1)v_1l_1}{v1+v2}=l-l_1$ ,解出$l_1=\frac{l(v_1+v_2)}{(2cnt-1)v_1+v_2}$,$T=\frac{l}{v_2}+\frac{l-l_2}{v_2}$

```cpp
#include <bits/stdc++.h>
using namespace std;
int n,l,v1,v2,k;
int main()
{
    while(scanf("%d%d%d%d%d",&n,&l,&v1,&v2,&k)!=EOF)
    {
        int cnt=ceil((double)n/k);
        double l1=(double)l*(double)(v1+v2)/(double)((2*cnt-1)*v1+v2);
        double t=l1/(double)v2+((double)l-l1)/(double)v1;
        printf("%.10f\n",t);
    }
    return 0;
}

```

# L - 篝火晚会 第二类斯特林数

## 题意

n个数划分成k个集合

---

$S(p,k)=k*S(p-1,k)+S(p-1,k-1)$

边界：
$$
S(p,p) =1  p >= 0 \\\

  S(p,0) = 0    p >= 1
$$

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD=1e9+7LL;
int t,n,k;
LL s[1010][1010];
int main()
{
    for(int i=0;i<=1000;i++)s[i][i]=1;
    for(int i=1;i<=1000;i++)s[i][0]=0;
    for(int i=1;i<=1000;i++)for(int j=1;j<=1000;j++)s[i][j]=(j*s[i-1][j]+s[i-1][j-1])%MOD;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        printf("%d\n",s[n][k]);
    }
    return 0;
}

```

# M - 为了我们心爱的京电 欧拉函数

## 题意

$\sum_{i=1}^{n}\sum_{j=1}^{a_i-1}gcd(a_i,j)$

---

可以发现$gcd(a_i,j)$是$a_i$的真因子，于是后面的和式转换成求$a_i$的因子个数乘以该因子，设$k$为$a_i$ 的一个因子，那么$gcd(a_i,j)=k$，即满足$gcd(a_i/k,j/k)=1$的$j$的个数，就是$\phi(a_i/k)$，所以原式等于$\sum_{i=1}^{n}\sum_{d|a_i}d*\phi(a_i/k)$ ，那么对每个数枚举因子就行了，线性筛预处理所有欧拉函数即可

不过貌似正向枚举总是写挂，预处理所有因子的倍数的欧拉函数和就过了，真是奥妙重重orz

复杂度$O(n\sqrt n)-O(n)$

## 代码

```cpp
#include <bits/stdc++.h>
#define MN 1000100
using namespace std;
typedef long long LL;
bool check[MN];
LL phi[MN],prime[MN],f[MN],ans=0;
void Shaker()
{
    memset(check,0,sizeof(check));
    phi[1]=1;int tot=0;
    for(int i=2;i<MN-1;i++)
    {
        if(!check[i])
        {
            prime[tot++]=i;
            phi[i]=i-1;
        }
        for(int j=0;j<tot;j++)
        {
            if(i*prime[j]>MN-1)break;
            check[i*prime[j]]=1;
            if(i%prime[j]==0)
            {
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }else
            {
                phi[i*prime[j]]=phi[i]*(prime[j]-1);
            }
        }
    }
}
LL n,a[MN];
int main()
{
    Shaker();
    memset(f,0,sizeof(f));
    for(int i=1;i<MN-1;i++)
    {
        for(int k=i*2;k<MN-1;k+=i)f[k]+=(i*phi[k/i]);
    }
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        ans+=f[a[i]];
    }
    cout<<ans<<endl;
    return 0;
}

```

