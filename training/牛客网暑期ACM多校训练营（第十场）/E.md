中国剩余定理可证$f(A,m)=m^{|A|-1}gcd(A,m)$

令$w(d)$表示$gcd$为$d$的倍数的$m^{|A|-1}$之和，$A_d$表示$d$的倍数的个数

那么$w(d)=\sum_{i=1}^{A_d}\binom{A_d}{i}m^{i-1}=\frac{(m+1)^{A_d}-1}{m}$

令$g(d)$表示$gcd$为$d$的$m^{|A|-1}$之和，则答案为$\sum_{d|m}dg(d)​$ 

$w(n)=\sum_{n|d}g(d)$，由莫比乌斯反演$g(n)=\sum_{n|d}\mu({d\over n})w(d)$

化简答案得

$\sum_{d|m}d\sum_{d|k}\mu({k\over d})w(k)=\sum_{k|m}w(k)\sum_{d|k}d\mu({k\over d})=\sum_{k|m}w(k)\sum_{d'|k}{k\over d'}\mu(d')=\sum_{k|m}\phi(k)w(k)=\sum_{d|m}\phi(d)w(d)$



