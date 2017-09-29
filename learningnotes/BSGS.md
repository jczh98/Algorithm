# 简介

BSGS算法全称Baby Step Giant Step算法，也叫大步小步算法(莫名喜感？)，用于求解最小的非负整数$x$满足$a^x \equiv b \pmod{p}$

# BSGS

## 解法一

令$m = \lceil \sqrt{p} \rceil$，$x=i \times m +j$，那么$a^x\equiv a^{i\times m}\times a^j \pmod{p}$，枚举$i$，对于每一个$i$，令$d=a^{m^i}$，可以得到$d\times a ^j \equiv b \pmod{p}$，因为$p$为质数，所以当$d$是$p$的倍数时可以特判出结果，当$(d,p)=1$时，可以利用扩展欧几里得算法求出$a^j$的最小整数解，对于求出的$a^j$，通过预处理的hash表可以在$O(1)$时间内查询到对应的$j$

预处理复杂度$O(\sqrt{n})$ ，枚举复杂度$O(\sqrt{n})$

时间复杂度$O(\sqrt n)$

## 解法二

(震惊...居然有不用求逆元的做法

令$m = \lceil \sqrt{p} \rceil$，$x=i \times m - j$，那么$a^{m^i} \equiv b\times a^j \pmod{p}$，枚举$i\in[0,m]$ ，$a^{m^i} = a^m\times a^{m^{i-1}}$ ，可以递推求出$a^{mi}\pmod{p}$的值，预处理hash出$b\times a^j$ ，在表中查找相应的$j$即可得出答案

## 代码

```cpp
typedef long long LL;
struct Hash{
    static const LL HASH_MOD = 76543;
    LL Hash[HASH_MOD], head[HASH_MOD], nxt[HASH_MOD], id[HASH_MOD], top;
    inline void Init() {
        memset(head, -1, sizeof(head));
        top = 1;
    }
    inline void Insert(LL x, LL y) {
        LL k = x % HASH_MOD;
        Hash[top] = x;
        id[top] = y;
        nxt[top] = head[k];
        head[k] = top++;
    }
    inline LL Find(LL x) {
        LL k = x % HASH_MOD;
        for(LL i = head[k]; ~i; i = nxt[i]) {
            if(Hash[i] == x) return id[i];
        }
        return -1;
    }
}has;
LL BSGS(LL a, LL b, LL p) {
    has.Init();
    if(b == 1) return 0LL;
    LL m = ceil(sqrt(p * 1.0)), x = 1, t = 1, j;
    for(LL i = 0; i < m; i++) has.Insert(t * b % p, i), t = t * a % p;
    for(LL i = m; i <= p; i += m) {
        j = has.Find(x * t % p); if(j != -1) return i - j; x = x * t % p;
    }
    return -1;
}
```

# 扩展BSGS

此时$p$为一般正整数

令$d=(a,p)$ 

如果$d \not \mid b$ ，唯一的解为$x=0$ ，当$b = 1$时有解

如果$d \mid b$ ，当$d = 1$ ， $a$与$p$互质，可用一般BSGS求解

当$d \neq 1$ ，$a^{x-1}\times \frac{a^k}{d} \equiv \frac{b}{d} \pmod{\frac{p}{d}}$

继续分解直到$a$与$\frac{p}{\prod_{i=1}^{k}d_i}$互质，记$D = \prod_{i=1}^{k}d_i$

 此时$a^{x-k}\times\frac{a^k}{D} \equiv \frac{b}{D} \pmod {\frac{p}{D}}$	

如果$D \not \mid b$ 唯一的解释$x = 0$

如果$D\mid b$，先暴力枚举枚举$x\in[0,k),k\le \log_2 p$

对于$x>=k$的情况

原式迭代后发现是$C\times a^{x-k} \equiv b' \pmod{p'}$ ，$C,b',p'$为可以迭代计算得到的常数，令$x'=x-k$， $C'$为$C$在模$p'$下的逆元，$B'=C'b'$，那么原式就转换成$a^{x'}\equiv B' \pmod{p'},(a,p')=1$，可以用一般BSGS算法求出，答案$x=x'+k$

## 代码

```cpp
typedef long long LL;
struct Hash{
    static const LL HASH_MOD = 99991;
    LL Hash[HASH_MOD], head[HASH_MOD], nxt[HASH_MOD], id[HASH_MOD], top;
    inline void Init() {
        memset(head, -1, sizeof(head));
        top = 1;
    }
    inline void Insert(LL x, LL y) {
        LL k = x % HASH_MOD;
        Hash[top] = x;
        id[top] = y;
        nxt[top] = head[k];
        head[k] = top++;
    }
    inline LL Find(LL x) {
        LL k = x % HASH_MOD;
        for(LL i = head[k]; ~i; i = nxt[i]) {
            if(Hash[i] == x) return id[i];
        }
        return -1;
    }
}has;
LL ExBSGS(LL a, LL b, LL p) {
    has.Init();
    a %= p; b %= p;
    if(b == 1LL) return 0LL;
    LL C = 1LL, k = 0, d, j;
    while((d = __gcd(a, p)) != 1) {
        if(b % d) return -1;
        k++; b /= d; p /= d; C = (C * a / d) % p;
        if(b == C) return k;
    }
    LL m = ceil(sqrt(p * 1.0)), t = 1LL;
    for(LL i = 0; i <= m; i++) {
        if(i == 0) has.Insert(b, i);
        else t = t * a % p, has.Insert(t * b % p, i);
    }
    for(LL i = 1; i <= m; i++) {
        C = C * t % p; if((j = has.Find(C)) != -1) return i * m - j + k;
    }
    return -1;
}
```



# 参考
[Baby Step Giant Step 及其扩展算法](https://oi.abcdabcd987.com/bsgs/)

[BSGS模板(模数为质数)](http://blog.csdn.net/never_see/article/details/60961106)              

[\[BZOJ1467\]Pku3243 clever Y(扩展BSGS)](http://blog.csdn.net/clove_unique/article/details/51227328)