#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> has(n * m);
    vector<vector<int>> arr(n);
    for(auto i = 0; i < n; i++){
        int t;
        for(int j = 0; j < m; j++){
            cin >> t;
            arr[i].push_back(t);
            has[t] = i + 1;
        }
        sort(arr[i].begin(),arr[i].end());
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m - 1; j++){
            if(arr[i][j + 1] - arr[i][j] != n){
                cout << -1 << '\n';
                return;
            }
        }
    }
    for(int i = 0; i < n; i++) cout << has[i] << ' ';
    cout << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case " << i <<": ";
        solve();
    }
    return 0;
}