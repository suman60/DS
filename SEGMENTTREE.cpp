#include<bits/stdc++.h>
using namespace std; 
#define ll long long 
class SegmentTree {
    vector<ll> tree;
    int size;
public:
    SegmentTree(vector<ll>& array) {
        size = array.size();
        tree.resize(4 * size);
        buildTree(array, 0, 1, size - 1);
    }
    void update(int index, int value) {
        updateTree(0, 1, size - 1, index, value);
    }
    ll  query(int l , int r ){
       return  RangeQuery(0, 1, size-1, l, r);
    }
private:
    void buildTree(vector<ll>& array, int treeIndex, int left, int right) {
        if (left == right) {
            tree[treeIndex] = array[left];
            return;
        }
        int mid = left + (right - left) / 2;
        buildTree(array, 2 * treeIndex + 1, left, mid);
        buildTree(array, 2 * treeIndex + 2, mid + 1, right);
        tree[treeIndex] = tree[2 * treeIndex + 1] + tree[2 * treeIndex + 2];
    }
    ll RangeQuery(int treeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > right || queryRight < left) {
            return 0;
        }
        if (queryLeft <= left && queryRight >= right) {
            return tree[treeIndex];
        }
        int mid = left + (right - left) / 2;
        return RangeQuery(2 * treeIndex + 1, left, mid, queryLeft, queryRight) +
               RangeQuery(2 * treeIndex + 2, mid + 1, right, queryLeft, queryRight);
    }
    void updateTree(int treeIndex, int left, int right, int index, int value) {
        if (left == right) {
            tree[treeIndex]= value;
            return;
        }
        int mid = left + (right - left) / 2;
        if (index <= mid) {
            updateTree(2 * treeIndex + 1, left, mid, index, value);
        } else {
            updateTree(2 * treeIndex + 2, mid + 1, right, index, value);
        }
        tree[treeIndex] = tree[2 * treeIndex + 1] + tree[2 * treeIndex + 2];
    }
};