#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> all_valid_pos;

void n_queens(int col, vector<int> &rows, vector<bool> &used, vector<bool> &d1, vector<bool> &d2)
{
    if (col == 8)
    {
        all_valid_pos.push_back(rows);
        return;
    }
    for (int r = 1; r <= 8; r++)
    {
        if (!used[r] && !d1[col - r + 7] && !d2[col + r])
        {
            rows[col] = r;
            used[r] = d1[col - r + 7] = d2[col + r] = true;
            n_queens(col + 1, rows, used, d1, d2);
            used[r] = d1[col - r + 7] = d2[col + r] = false;
        }
    }
}

void solve()
{
    
    vector<int> board(8);
    for (int i = 0; i < 8; i++)
        cin >> board[i];

    int max_pos = 0;
    for (auto &sol : all_valid_pos)
    {
        int matched_pos = 0;
        for (int i = 0; i < 8; i++)
        {
            if (board[i] == sol[i])
                matched_pos++;
        }
        max_pos = max(max_pos, matched_pos);
    }
    cout << (8 - max_pos);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    vector<int> rows(8);
    vector<bool> used(9, false), d1(15, false), d2(15, false);
    n_queens(0, rows, used, d1, d2);
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
