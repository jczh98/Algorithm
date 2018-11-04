$$
\begin{align*}
&ans=S(n,m)=\sum_{i=1}^{m}\mu(in)=\sum_{i=1}^{m}\mu(i)\mu(n)[(i,n)=1]\\
&=\sum_{i=1}^{m}\mu(i)\mu(n)\sum_{d|i,d|n}\mu(d)\\
&=\mu(n)\sum_{d|n}\mu(d)\sum_{i=1}^{{m\over d}}\mu(id)=\mu(n)\sum_{d|n}\mu(d)S(d,{m\over d})
\end{align*}
$$
这种尝试有TLE得风险(实际上预处理质因数可以做)

当$\mu(n)=0$可以发现答案为0，只需讨论$n$为sqaure free，即$|\mu(n)|=1$的情况
$$
\begin{align*}
&S(n,m)=\sum_{i=1}^{m}\mu(in)\\
&=\sum_{p|i}\mu(in)+\sum_{p\nmid i}\mu(i{n\over p}p)\\
&=-\sum_{p\nmid i}\mu(i{n\over p})\\
&=-(\sum_{i=1}^{m}\mu(i{n\over p})-\sum_{p|i}\mu(i{n\over p}))\\
&=-\sum_{i=1}^{m}\mu(i{n\over p})+\sum_{k=1}^{m\over p}\mu(kn) (\text{let k = pi}) \\
&=-S({n\over p}, m)+S(n, {m\over p})
\end{align*}
$$

$S(n,0)=0​$只需要计算$S(1,m)​$，利用杜教筛可以求出，递归计算即可

复杂度$O(\text{n的素因子个数}\sqrt{n}+n^{\frac{2}{3}})$