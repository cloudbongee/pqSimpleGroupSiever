# pqSimpleGroupSiever

## Theory
Given a group $\vert G\vert = p^km$, due to the consequence of Sylow's theorem, $n_p:=[G:N(p)]$ follows 
the property $n_p \mid m \land n_p \equiv 1 \pmod{p}$. One of the easiest type of groups to look into
are the ones of order $pq$.

Let $p,q\in\mathbb{Z}^{\text{prime}}$, if we look into the $p-\text{Sylow}$ subgroups of $|G|=pq$, then $n_p \mid q$ must hold.
However, $n_p = 1 \lor n_p = q$, due to $q$'s primality. Thus, we only need to look into whether:

$$ q \equiv 1 \pmod{p} $$

If the previous is true, then the count of groups could either be one or $q$. Case for which other lemmas and studies of the 
group structure must be done to determine the count of $p-\text{Sylow}$ groups.

However, if it is not true, then the count of $1$ is the only valid count for $p-\text{Sylow}$ subgroups of $G$. Consequently, the unique $p-\text{Sylow}$ subgroup is a normal subgroup of $G$.

An equivalent process can be taken to determine the uniqueness of $q-\text{Sylow}$ subgroups. And since $p < pq$ and $q < pq$. Following the aforementioned logical process over all combinations of $p\neq q$ with $pq$ lesser than a given bound will let us confirm simpleness (or the lack thereof) of groups of $pq$ order.

## Implementation
Given a $m$ max-cardinality.

  1. Erasthotenes prime sieve is applied to a max bound of $\left\lceil\dfrac{m}{2}\right\rceil$
  2. A double loop is used over $p$ and $q$ ensuring that once $pq$ is evaluated, $qp$ is later ignored.
     Negating simpleness of the group if $p \nequiv 1 \pmod{q}$ or $q \nequiv 1 \pmod{p}$. 
