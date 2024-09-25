#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
const int mod = 1000000007;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<pii, null_type, less_equal<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

/*=================================Debug==================================*/
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << " " << H;
    dbg_out(T...);
}

#define MY
#ifdef MY
#define debug(args...) cerr << "(" << #args << "):", dbg_out(args)
#else
#define debug(args...)
#endif
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
struct setCmp
{
    bool operator()(pair<int, int> i1, pair<int, int> i2)
    {
        if (i1.first > i2.first)
            return 1;
        if (i1.first == i2.first)
            return i1.second < i2.second;
        return 0;
    }
};
// https://codeforces.com/problemset/problem/86/D
int a[200009], c[2000009];
const int k = 320;
struct st
{
    int l, r, id;
} query[200009];
long long sum = 0;
bool cmp(st &a, st &b)
{
    int block_a = a.l / k, block_b = b.l / k;
    if (block_b == block_a)
        return a.r < b.r;
    return block_a < block_b;
}
void add(int i)
{
    sum -= 1ll * c[a[i]] * c[a[i]] * a[i];
    c[a[i]]++;
    sum += 1ll * c[a[i]] * c[a[i]] * a[i];
}
void remove(int i)
{
    sum -= 1ll * c[a[i]] * c[a[i]] * a[i];
    c[a[i]]--;
    sum += 1ll * c[a[i]] * c[a[i]] * a[i];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> query[i].l >> query[i].r;
        query[i].id = i;
    }
    sort(query + 1, query + q + 1, cmp);
    int l = 1, r = -1;
    long long ans[200009];
    for (int i = 1; i <= q; i++)
    {
        while (r < query[i].r)
            add(++r);
        while (r > query[i].r)
            remove(r--);
        while (l > query[i].l)
            add(--l);
        while (l < query[i].l)
            remove(l++);
        ans[query[i].id] = sum;
    }
    for (int i = 1; i <= q; i++)
    {
        printf("%lld\n", ans[i]);
    }
    return 0;
}
