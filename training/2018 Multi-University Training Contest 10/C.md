
$$
\sum_{i=1}^{A}\sum_{j=1}^{B}\sum_{k=1}^{C}\phi(gcd(i,j^2,k^3)) \\
=\sum_{d=1}^{min(A,B^2,C^3)}\phi(d)\sum_{i=1}^{A}\sum_{j=1}^{B}\sum_{k=1}^{C}[gcd(i,j^2,k^3)=d]
$$
令$f(d)$表示$\sum_{i=1}^{A}\sum_{j=1}^{B}\sum_{k=1}^{C}[gcd(i,j^2,k^3)=d]$ , $g(d)$表示$f(d)$的倍数和

即$f(d)$表示在给定$i,j,k$范围内满足$gcd(i,j^2,k^3)$等于$d$的$(i,j,k)$组数，$g(d)$表示给定范围满足$d|gcd(i,j^2,k^3)$的组数，可知$g(n)=\sum_{n|d}f(d)$ , 莫比乌斯反演得到$f(n)=\sum_{n|d}\mu({d\over n})g(d)$

$g(d)$表示满足$d|i,d|j^2,d|k^3$的组数

因为有如下结论，当$x|i^k,x=\prod p_i^{t_i}$，则令$f_k(x)=\prod p_i^{\lceil {t_i \over k} \rceil},f_k(x)|i$,所以$g(d)$表示满足$f_1(d)|i,f_2(d)|j,f_3(d)|k$的组数，即$g(d)=\lfloor {A\over f_1(d)} \rfloor \lfloor {B\over f_2(d)} \rfloor \lfloor {C\over f_3(d)} \rfloor$
$$
=\sum_{d=1}^{A}\phi(d)\sum_{d|t}\mu({t\over d})g(t)\\
=\sum_{t=1}^{A}g(t)\sum_{d|t} \phi(d)\mu({t\over d})
$$

可知$f_k(x),\mu,\phi,\mu * \phi$是积性函数

记$F(x)=（\mu * \phi） (x)$ , 当$x$为素数的时候，$F(p)=p-2$，当$F(p^k)=p^k+p^{k-2}-2p^{k-1},k>=2$

而$f_k(p)=p$, 当$k+1 \equiv 1 \pmod p$$f_k(p^{k+1})=f_k(p)p$,否则$f_k(p^{k+1})=f_k(p^k)$

利用积性函数的线性筛可以筛出来