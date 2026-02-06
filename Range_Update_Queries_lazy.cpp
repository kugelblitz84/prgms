#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
#define endl '\n'
using namespace std;

vector<int> lazy(800000 + 7);

void updateRange(int queryStart, int queryEnd, int val, int start, int end, int root)
{
    if (queryStart > end or queryEnd < start)
        return;
    if (queryStart <= start and end <= queryEnd)
    {
        lazy[root] += val;
        return;
    }

    int mid = (start + end) >> 1;
    int leftNode = (2 * root) + 1;
    int rightNode = (2 * root) + 2;
    //we do not push lazy values to children during update because it disrupts the state of the tree.
    //and it is unnecessary for range update point query.
    // if (lazy[root] != 0)
    // {
    //     lazy[leftNode] += lazy[root];
    //     lazy[rightNode] += lazy[root];
    //     lazy[root] = 0;
    // }
    updateRange(queryStart, queryEnd, val, start, mid, leftNode);
    updateRange(queryStart, queryEnd, val, mid + 1, end, rightNode);
}

int findVal(vector<int> &arr, int pos, int start, int end, int root)
{
    if (start == end)
    {
        return arr[pos] + lazy[root];
    }
    int mid = (start + end) >> 1;
    int leftNode = (2 * root) + 1;
    int rightNode = (2 * root) + 2;
    //again we DO NOT PUSH LAZY VALUES. 
    // if (lazy[root] != 0)
    // {
    //     lazy[leftNode] += lazy[root];
    //     lazy[rightNode] += lazy[root];
    //     lazy[root] = 0;
    // }
    if (pos >= start and pos <= mid)
    {
        //we accumulate the lazy values when we are on the way returning to root.
        return lazy[root] + findVal(arr, pos, start, mid, leftNode);
    }
    else
    {
        return lazy[root] + findVal(arr, pos, mid + 1, end, rightNode);
    }
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (auto &i : arr)
        cin >> i;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int start, end, val;
            cin >> start >> end >> val;
            updateRange(start - 1, end - 1, val, 0, n - 1, 0);
        }
        else
        {
            int pos;
            cin >> pos;
            cout << findVal(arr, pos - 1, 0, n - 1, 0) << '\n';
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