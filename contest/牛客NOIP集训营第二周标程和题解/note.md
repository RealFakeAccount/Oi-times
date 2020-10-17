$$
f_i = \sum_j f_j \times \min(a[j+1... i]) \times (-1)^{i-j-1}\\

f_i = (-1)^{i} \sum_j\min(a[j+1...i]) \times  f_j \times (-1)^{j-1}\\
$$

考虑 i 转移到 i+1 时候：
$$
\min(a[j+1...i]) \to \min(a[j+1...i+1])
$$
lowbit(x) = i，相当于确定了集合最小元素是 i，那么 $i+1\sim n$ 这些元素是否在集合里可以任选，方案数 $2^{n-i-1}$ 

证明：

* 假设 $\{1,2,\dots, n\}\in S$  

那么一定存在一个 $i$ ，使得 $\forall  U$ 使得 $i\in U$, 必有  $U\in S​$ .

（如果不存在，那么 $\forall i, \exists i\in V_i, V_i\in T$ ，那么 $\{1,2,\dots, n\}=\bigcup_i V_i \in T$，矛盾）  

* 假设 $\{1,2,\dots, n\}\in T$  

那么一定存在一个 $i$ ，使得 $\forall  U$ 使得 $i\in U$, 必有  $U\in T$ .

（如果不存在，那么 $\forall i, \exists i\in V_i, V_i\in S$ ，那么 $\{1,2,\dots, n\}=\bigcup_i V_i \in S$，矛盾）  



$2^0 , 2^1, \dots, 2^{n-1}$ , 

假设 $K=2^{a_0}+2^{a_1}+\dots +2^{a_s}$ 