#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

int max_cost;
void dfs(int n, vector<vector<pair<int,int>>> &adj_list, vector<bool> &visited, int cost){
    visited[n] = true;
    for(auto i: adj_list[n]){
        if(!visited[i.first]){
            max_cost = max(max_cost, cost + i.second);
            dfs(i.first, adj_list, visited, cost + i.second);
        }
    }
}

void solve()
{
    max_cost = 0;
    vector<vector<pair<int,int>>> adj_list(101);
    vector<bool> visited(101);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }
    dfs(0, adj_list, visited, 0);
    cout << max_cost << '\n';
    
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