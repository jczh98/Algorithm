## 前置知识 DFA
这是wiki上的定义

A deterministic finite automaton M is a $5$-tuple, (Q, Σ, δ, q0, F), consisting of

- a finite set of states (Q)

- a finite set of input symbols called the alphabet (Σ)

- a transition function (δ : Q × Σ → Q)

- an initial or start state (q0 ∈ Q)

- a set of accept states (F ⊆ Q)

## Suffix Automaton

**Suffix Automaton**  就是可以识别后缀的最简有限状态自动机

### Concepts

$ST(str) = \delta(init, str)$表示自动机读入$str$后转移到的状态，$\delta(init,str) \subset end$表示自动机能识别字符串$str$

$Reg(s)$表示从状态$s$开始能够识别的字符串

对于一个字符串$a$,如果在$S$中出现的位置集合为$\{[l_1,r_1),[l_2,r_2)...[l_n,r_n)\}$

那么$Reg(ST(a))=\{Suffix(r_1),Suffix(r_2)...Suffix(r_n)\}​$

令$Right(a)=\{r_1,r_2...r_n\}$,一个$Right$集合和长度定义了一个子串

后缀自动机中的一个状态$s$代表了一个$Right$集合的等价类，也就是满足$Right(a)$等于$Right(s)$的所有的字符串$a$的集合，对于$Right(s)$，适合它的子串的长度在一个范围内，记做$[Min(s),Max(s)]$,对于任意两个状态$s_1,s_2$，$Right(s_1),Right(s_2)$要么不相交，要么$Max(s_1)<Min(s_2)$推出$Right(s_1)$是$Right(s_2)$的真子集，即$s_1$是$s_2$的后缀

$Right$集合的包含关系形成的树形结构叫**Parent Tree** (也叫suffix link)

$Parent(s)$表示使得$Right(s)\subset Right(x)$且$Right(x)$最小的状态$x$

$Max(Parent(s))=Min(s) - 1$

### 理解

- 从当前状态节点沿$Parent$往上一直走到根节点代表当前状态节点对应的子串的所有后缀
- 每个状态的$Right$大小就是该状态下的子串出现的次数
- $Right_{fa}=\sum_{u \in son} Right_u$，可以用dp或者拓扑排序预处理出来

## 参考资料
CLJ论文
[\[后缀自动机\]【学习笔记】](http://www.cnblogs.com/candy99/p/6374177.html)

[SUFFIX AUTOMATON by- saisumit](https://saisumit.wordpress.com/2016/01/26/suffix-automaton/) 

[后缀自动机学习总结](http://blog.sina.com.cn/s/blog_70811e1a01014dkz.html)