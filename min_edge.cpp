#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

vector<vector<int>> adj_list(300001);
vector<bool> visited(300001);

void dfs(int n){
    visited[n] = true;
    for(auto i: adj_list[n]){
        if(!visited[i]) dfs(i);
    }
}

void solve()
{
  int n, m;
  cin >> n >> m;
  while(m--){
    int from, to;
    cin >> from >> to;
    adj_list[from].push_back(to);
    adj_list[to].push_back(from);
  }
  int edge_need = 0;
  for(int i = 1; i <= n; i++){
    if(!visited[i]){
        dfs(i);
        edge_need++;
    }
  }
  cout << edge_need - 1 << '\n';
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