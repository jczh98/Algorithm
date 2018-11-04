#include <bits/stdc++.h>
using namespace std;
const int N = 5000;
int match[N], vis[N];
struct AhoCorasick {
    int ch[N][2], sz, val[N], last[N], f[N];
    inline void init() {
        sz = 1; f[0] = last[0] = val[0] = 0;
        memset(ch[0], 0, sizeof(ch[0]));
    }
    inline int idx(char c) {
        if(c == 'H') return 0; 
        if(c == 'T') return 1;
    }
    void insert(string s, int id) {
        int u = 0; 
        for(int i = 0; i < s.size(); ++i) {
            int c = idx(s[i]);
            if(!ch[u][c]) {
                memset(ch[sz], 0, sizeof(ch[sz]));
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        val[u] = id;
        match[id] = u;
    }
    void getFail() {
        queue<int> que; 
        for(int i = 0; i < 2; ++i) {
            int u = ch[0][i];
            if(u) {f[u] = 0; que.push(u); last[u] = 0;}
        }
        while(!que.empty()) {
            int r = que.front(); que.pop();
            if(val[f[r]]) val[r] = 1;
            for(int c = 0; c < 2; ++c) {
                int u = ch[r][c];
                if(!u) {ch[r][c] = ch[f[r]][c]; continue;}
                que.push(u);
                int v = f[r];
                while(v & !ch[v][c]) v = f[v];
                f[u] = ch[v][c];
                last[u] = val[f[u]] ? f[u] : last[f[u]];
            }
        }
    }
} ac;
int equ, var;
double A[5000][5000], x[5000];
int Gauss() {
    int i, j, k, col, max_r;
    for(k = 0, col = 0; k < equ && col < var; k++, col++){
        max_r = k;
        for(i = k + 1; i < equ; i++){
            if(fabs(A[i][col]) > fabs(A[max_r][col]))
                max_r = i;
        }
        if(k != max_r)
            for(j = col; j <= var; j++)
                swap(A[k][j], A[max_r][j]);
        for(i = k + 1; i < equ; i++){
            if(A[i][col]){
                double tmp = -A[i][col] / A[k][col];
                for(j = col; j <= var; j++)
                    A[i][j] += tmp * A[k][j];
            }
        }
    }
    for (i = equ - 1; i >= 0; i--) {
        double tmp = A[i][var];
        for (j = i + 1; j < var; j++)
            tmp -= x[j] * A[i][j] ;
        x[i] = tmp / A[i][i];
    }
    return 1;
}
double one = 1.0, blk = 0;
string a, b;
int main() {
    cin >> a >> b;
    if(a == b) {
        printf("0\n0\n1\n");
        return 0;
    }
    ac.init();     
    ac.insert(a, 1); vis[match[1]] = 1;
    ac.insert(b, 2); vis[match[2]] = 1;
    ac.getFail();
    double ans[3];
    for(int i = 1; i <= 2; ++i) {
        equ = var = ac.sz;
        memset(A, 0, sizeof(A));
        memset(x, 0, sizeof(x));
        for(int j = 1; j <= 2; ++j) {
            if(i == j) A[match[j]][ac.sz] = 1.0;
        }
        for(int u = 0; u < ac.sz; ++u) {
            A[u][u] = 1.0;
            if(vis[u]) continue;
            for(int c = 0; c < 2; ++c) {
                int v = ac.ch[u][c];
                A[u][v] -= 1.0 / 2;
            }
        }
        Gauss();
        ans[i] = x[0];
    }
    if(a.find(b) != string::npos) {
        if(a.find(b) == a.size() - b.size()) {
            printf("%.15f\n%.15f\n%.15f\n", blk, ans[2], 1.0 - ans[2]);            
        }else {
            printf("%.15f\n%.15f\n%.15f\n", blk, one, blk);              
        }
    } else if(b.find(a) != string::npos) {
        if(b.find(a) == b.size() - a.size()) {
            printf("%.15f\n%.15f\n%.15f\n", ans[1], blk, 1.0 - ans[1]); 
        }else {
            printf("%.15f\n%.15f\n%.15f\n", one, blk, blk);             
        }
    } else printf("%.15f\n%.15f\n%.15f\n", ans[1], ans[2], 1.0 - ans[1] - ans[2]);
    return 0;
}