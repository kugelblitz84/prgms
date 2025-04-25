#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> has(n * m + 1);
    for(auto i = 0; i < n; i++){
        int t;
        for(int j = 0; j < m; j++){
            cin >> t;
            has[t] = i;
        }
    }
    set <int> ans;
    for(int i = 0; i < m; i++){
        if(ans.find(has[i]) == ans.end()) ans.insert(has[i]);
        else {
            cout << -1 << '\n';
            return;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 1; j < m; j++){
            if(has[i] != has[i + (m*j)]){
                cout << -1 << '\n';
                return;
            }
        }
    }
    for(auto i:ans) cout << i << ' ';
    cout << '\n';
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