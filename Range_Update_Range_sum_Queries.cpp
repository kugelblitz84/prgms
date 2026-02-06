#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

vector<int> tree(400000 + 7);
vector<int> lazy(400000 + 7);

void buildTree(int start, int end, int root, vector<int> &arr)
{
    if (start == end)
    {
        tree[root] = arr[start];
        return;
    }
    int mid = (start + end) >> 1;
    int leftNode = (root * 2) + 1;
    int rightNode = (root * 2) + 2;
    buildTree(start, mid, leftNode, arr);
    buildTree(mid + 1, end, rightNode, arr);

    tree[root] = tree[leftNode] + tree[rightNode];
}
int findVal(int start, int end, int root, int queryStart, int queryEnd)
{
    if (start == end)
        return tree[root];
    if (start > queryEnd or end < queryStart)
        return 0;
    if (start <= queryEnd and end >= queryStart)
    {
        return tree[root];
    }
    int mid = (start + end) >> 1;
    int leftNode = (2 * root) + 1;
    int rightNode = (2 * root) + 2;
    
    if (lazy[root] != 0)
    {
        lazy[leftNode] += lazy[root];
        tree[leftNode] += (mid - start + 1) * lazy[root];
        lazy[rightNode] += lazy[root];
        tree[rightNode] += (end - mid) * lazy[root];
        lazy[root] = 0;
    }
    return findVal(start, mid, leftNode, queryStart, queryEnd) + findVal(mid + 1, end, rightNode, queryStart, queryEnd);
}

void updateRange(int start, int end, int root, int &val, int queryStart, int queryEnd)
{
    if (start > queryEnd or end < queryStart)
        return; // no overlap
    if (start >= queryStart and end <= queryEnd)
    { // total overlap
        lazy[root] += val;
        tree[root] += (end - start + 1) * val;
        return;
    }
    // partial overlap , splitting segment
    int mid = (start + end) >> 1;
    int leftNode = (2 * root) + 1;
    int rightNode = (2 * root) + 2;
    // if there are pending updates , push them to children;
    if (lazy[root] != 0)
    {
        lazy[leftNode] += lazy[root];
        tree[leftNode] += (mid - start + 1) * lazy[root];
        lazy[rightNode] += lazy[root];
        tree[rightNode] += (end - mid) * lazy[root];
        lazy[root] = 0;
    }
    updateRange(start, mid, leftNode, val, queryStart, queryEnd);
    updateRange(mid + 1, end, rightNode, val, queryStart, queryEnd);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (auto &i : arr)
        cin >> i;
    buildTree(0, n - 1, 0, arr);
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int start, end, val;
            cin >> start >> end >> val;
            updateRange(0, n - 1, 0, val, start, end);
        }
        else
        {
            int start, end;
            cin >> start >> end;
            cout << findVal(0, n - 1, 0, start, end) << '\n';
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case " << i <<": ";
        solve();
    }
    return 0;
}