#include <bits/stdc++.h>
using namespace std;
class DSU {
public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }

private:
    vector<int> parent, size;
};
