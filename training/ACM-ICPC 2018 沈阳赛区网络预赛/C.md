$$
\begin{align*}
&ans=\sum_{num=1}^{n}\sum_{i=1}^{num}\mu^2(i)i^2 \\
&=\sum_{i=1}^{n}\mu^2(i)i^2(n-i+1) \\
&=(n+1)\sum_{i=1}^{n}\mu^2(i)i^2-\sum_{i=1}^{n}\mu^2(i)i^3 \\
\end{align*}
$$

$$
\begin{align*}
&\sum_{i=1}^{n}\mu^2(i)i^2 \\
&=\sum_{i=1}^{\sqrt{n}}\mu(i)\sum_{k=1}^{{n \over i^2}}(ki^2)^2\\
&=\sum_{i=1}^{\sqrt{n}}\mu(i)i^4\sum_{k=1}^{{n \over i^2}}k^2
\end{align*}
$$

$$
\begin{align*}
&\sum_{i=1}^{n}\mu^2(i)i^3 \\
&=\sum_{i=1}^{\sqrt{n}}\mu(i)\sum_{k=1}^{{n \over i^2}}(ki^2)^3\\
&=\sum_{i=1}^{\sqrt{n}}\mu(i)i^6\sum_{k=1}^{{n \over i^2}}k^3
\end{align*}
$$

$$
\begin{align*}
&ans=(n+1)\sum_{i=1}^{\sqrt{n}}\mu(i)i^4\sum_{k=1}^{{n \over i^2}}k^2-\sum_{i=1}^{\sqrt{n}}\mu(i)i^6\sum_{k=1}^{{n \over i^2}}k^3
\end{align*}
$$

