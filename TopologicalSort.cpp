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
int n, m;
vector<vector<int>> g;
vector<bool> visited;
vector<int> ans;
void dfs(int v)
{
    visited[v] = true;
    for (int u : g[v])
    {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topSort()
{
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    reverse(ans.begin(), ans.end());
    return;
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
    cin >> n >> m;
    g.resize(n + 2);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    topSort();
    for (int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}
