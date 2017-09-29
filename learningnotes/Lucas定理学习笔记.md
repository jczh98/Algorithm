# Lucas定理

## 公式

$\binom{n}{m} \equiv \prod_{i = 0}^{n} \binom{n_i}{m_I} \pmod{p}$

$m=m_kp^k+m_{k-1}p^{k-1}+...+m_1p+m_0$

$n=n_kp^k+n_{k-1}p^{k-1}+...+n_1p+n_0$

可以看出是$p$进制展开式

## 证明

窝太弱了qwq

~~自行wiki~~

## 代码

zoj 3557

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL QuickPow(LL a, LL b, LL MOD) {
    LL res = 1;
    while(b) {
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
LL Inv(LL x, LL MOD) {
    return QuickPow(x, MOD -2 , MOD);
}
LL C(LL n, LL m, LL MOD) {
    if(m > n) return 0LL;
    LL up = 1LL, down = 1LL;
    for(LL i = n - m + 1; i <= n; i++) up = (up * i) % MOD;
    for(LL i = 1; i <= m; i++) down = (down * i) % MOD;
    return (up * Inv(down, MOD)) % MOD;
}
LL Lucas(LL n, LL m, LL MOD) {
    if(m > n) return 0LL;
    LL ans = 1;
    for(; m; m /= MOD, n /= MOD) {
        ans = (ans * C(n % MOD, m % MOD, MOD)) % MOD;
    }
    return ans;
}
LL n, m, p;
int main() {
    while(cin >> n >> m >> p) {
        cout << Lucas(n - m + 1, m, p) << endl;
    }
    return 0;
}
```

# 扩展Lucas定理

## $\binom{n}{m} \pmod{p^k}$

先来考虑这样一个问题，此时很显然$p^k$不是素数

根据$\binom{n}{m}=\frac{n!}{m!(n-m)!}​$,只需要求出三个部分分别求模$p^k​$然后逆元相乘就可以了

对于$n!\mod p^k$

我们以$n=19,p=3,k=2$为例 

$n! =1\times 2 \times 3 \times 4 \times 5 \times 6 \times 7 \times 8 \times 9 \times 10 \times 11 \times 12\times 13 \times 14 \times 15 \times 16 \times 17 \times 18 \times 19 \\\ =(1\times 2\times 4\times 5\times 7\times 8\times 10\times 11\times 13\times 14\times 16\times 17\times 19)\times 3^6\times (1\times 2\times 3\times 4\times 5\times 6)$

可以观察到可以分为$3$个部分，$p^{\lfloor \frac{n}{p} \rfloor}$,$\lfloor \frac{n}{p} \rfloor !$,以及除这两部分以外剩下的数

可以观察到最后一个部分在模$p^k$意义下是以$p^k$为周期的，即$(1\times 2\times 4\times 5\times 7\times 8)\equiv(10\times 11\times 13\times 14\times 16\times 17)\pmod {p^k}$，所以只需要求出$p^k$的长度即可

对于剩下孤立的数，因为数量不会超过$p^k$，所以暴力求解

因为$m!\mod p^k$和$(n-m)!\mod p^k$可能与$p^k$不胡素，无法求逆元，所以要将他们的中的质因子$p$先除掉，求完逆元后再乘回来

## $\binom{n}{m} \pmod{p}$ $p$为一般正整数

将$p$分解质因数，$p=p_1^{k_{1}}\times p_2^{k_2}\times ... \times p_n^{k_n}$

记答案为$ans$

可以列出同余方程组
$$
\begin{cases}
ans \equiv a_1 \pmod{p_1^{k_1}} \\
ans \equiv a_2 \pmod{p_2^{k_2}} \\
... \\
ans \equiv a_n \pmod{p_n^{k_n}}
\end{cases}
$$
其中$a_1,a_2...a_n$是$\binom{n}{m} \pmod{p_i^{k_i}}$的解

利用扩展中国剩余定理，合并同余方程

实际上因为$p_i^{k_i}$两两互质，可以直接使用CRT求和计算

## 代码

来自[zyf2000](http://blog.csdn.net/clove_unique)，神奇的写法,如此简洁，orz跪烂

```cpp
typedef long long LL;
inline LL QuickPow(LL a, LL b, LL MOD) {
    LL res = 1LL;
    while(b) {
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
void Exgcd(LL a, LL b, LL &x, LL &y) {
    if(!b) x = 1LL, y = 0LL;
    else Exgcd(b, a % b, y, x), y -= a / b * x;
}
inline LL Inv(LL A, LL MOD) {
    if(!A) return 0LL;
    LL a = A, b = MOD, x = 0LL, y = 0LL;
    Exgcd(a, b, x, y);
    x = ((x % b) + b) % b;
    if(!x) x += b;
    return x;
}
LL Mul(LL n, LL p, LL pk) {
    if (!n) return 1LL;
    LL ans = 1LL;
    for (LL i = 2; i <= pk; ++i) if (i % p) ans = ans * i % pk;
    ans = QuickPow(ans, n / pk, pk);
    for (LL i = 2; i <= n % pk; ++i) if (i % p) ans = ans * i % pk;
    return ans * Mul(n / p, p, pk) % pk;
}

inline LL C(LL n, LL m, LL MOD, LL p, LL pk) {
    if (m > n) return 0LL;
    LL a = Mul(n, p, pk), b = Mul(m, p, pk), c = Mul(n - m, p, pk);
    LL k = 0LL, ans;
    for (LL i = n; i; i /= p) k += i / p;
    for (LL i = m; i; i /= p) k -= i / p;
    for (LL i = n - m; i; i /= p) k -= i / p;
    ans = a * Inv(b, pk) % pk * Inv(c, pk) % pk * QuickPow(p, k, pk) % pk;
    return ans * (MOD / pk) % MOD * Inv(MOD / pk, pk) % MOD;
}
inline LL ExLucas(LL n, LL m, LL p) {
    LL res = 0LL, x = p;
    for (LL i = 2; i * i <= p; ++i) {
        if (x % i == 0) {
            LL pk = 1LL;
            while (x % i == 0) pk *= i, x /= i;
            res = (res + C(n, m, p, i, pk)) % p;
        }
    }
    if(x > 1) res = (res + C(n, m, p, x, x)) % p;
    return res;
}
```



# 参考

[wiki](https://en.wikipedia.org/wiki/Lucas%27s_theorem)

[中国剩余定理与扩展 Lucas定理与扩展 学习笔记 ](http://blog.csdn.net/clove_unique/article/details/54571216)