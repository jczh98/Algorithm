#include <bits/stdc++.h>
using namespace std;
const int N=2*10005;
int n,m;
int head[N],nxt[N],to[N],type[N],cnt=0,counter=1;
int vis[N],vis2[N];
map<string,int> id;
string s1,s2,s3;
void add_edge(int u,int v,int ty) {
    //cout << u << " " << v << " " << ty << endl;
    to[cnt]=v;
    type[cnt]=ty;
    nxt[cnt]=head[u];
    head[u]=cnt++;
}
bool dfs_is(int u,int dest) {
    if(vis[u])return false;
    if(u==dest)return true;
    vis[u]=true;
    for(int i=head[u];~i;i=nxt[i]) {
        if(type[i]==1)if(dfs_is(to[i],dest))return true;
    }
    return false;
}
bool judge_is(string s,string t) {
    if(s==t)return true;
    //cout << id[s] << " " << id[t] << endl;
    memset(vis,false,sizeof(vis));
    for(int i=head[id[s]];~i;i=nxt[i]) {
        //cout << id[s] << " " << to[i] << endl;
        if(type[i]==1)if(dfs_is(to[i],id[t])) return true;
    }
    return false;
}
bool firstvis;
bool dfs_has(int u,int dest,int tp,bool exist_flag) {
    if(tp==2)exist_flag=true;
    if(u==dest&&exist_flag)return true;
    else if(vis[u]&&tp==1)return false;
    else if(vis2[u]&&tp==2)return false;
    if(tp==1) vis[u]=true;
    else {
        if(firstvis) {
            memset(vis,0,sizeof(vis));firstvis=false;
        }
        vis2[u]=true;
    }
    for(int i=head[u];~i;i=nxt[i]) {
        if(dfs_has(to[i],dest,type[i],exist_flag))return true;
    }
    return false;
}
bool judge_has(string s,string t) {
    memset(vis,false,sizeof(vis));
    memset(vis2,false,sizeof(vis2));
    for(int i=head[id[s]];~i;i=nxt[i]) {
        //cout << endl;
        //cout << id[s] << " " << to[i] << " " << type[i] << endl;
        if(dfs_has(to[i],id[t],type[i],type[i]==2?true:false)) return true;
        // if(type[i]==2){if(dfs_has(to[i],id[t],true)) return true;}
        // else if(dfs_has(to[i],id[t],false))return true;
    }
    return false;
}
int main() {
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i) {
        cin>>s1>>s2>>s3;
        if(id.find(s1)==id.end())id[s1]=counter++;
        if(id.find(s3)==id.end())id[s3]=counter++;
        //cout << s1 << " : " << id[s1] << endl;
        //cout << s3 << " : " << id[s3] << endl;
        if(s2=="is-a")add_edge(id[s1],id[s3],1);
        else add_edge(id[s1],id[s3],2);
    }
    for(int i=1;i<=m;++i) {
        cin>>s1>>s2>>s3;
        printf("Query %d: ",i);
        if(s2=="is-a"){
            if(judge_is(s1,s3)) printf("true\n");else printf("false\n");
        }else {
            firstvis=true;
            if(judge_has(s1,s3)) printf("true\n");else printf("false\n");
        }
    }
}