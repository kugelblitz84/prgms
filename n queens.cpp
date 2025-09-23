#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

vector<vector<int>> all_valid_pos;
int n;
void n_queens(int col, vector<int> &rows, vector<bool> &used,
              vector<bool> &d1, vector<bool> &d2)
{
    if (col == n)
    {
        all_valid_pos.push_back(rows);
        return;
    }
    for (int r = 1; r <= n; r++)
    {
        if (!used[r] && !d1[col - r + (n - 1)] && !d2[col + r])
        {
            rows[col] = r;
            used[r] = d1[col - r + (n - 1)] = d2[col + r] = true;
            n_queens(col + 1, rows, used, d1, d2);
            used[r] = d1[col - r + (n - 1)] = d2[col + r] = false;
        }
    }
}
void solve()
{
    cin >> n;
    vector<int> rows(n);
    vector<bool> used(n + 1, false), d1(2 * n - 1, false), d2(2 * n - 1, false);
    n_queens(0, rows, used, d1, d2);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case " << i <<": ";
        solve();
    }
    return 0;
}