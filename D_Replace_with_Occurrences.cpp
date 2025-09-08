#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

void solve()
{
  int n;
  cin >> n;
  int arr[n];
  map<int,int> freq;
  for(auto &i: arr) cin >> i, freq[i]++;
  for(int i = 0; i < n; i++){
    if(arr[i] != freq[arr[i]]){
      cout << -1 << "\n";
      return;
    }
  }
  int ans[n];
  stack<int> id;
  for(int i = 1; i <= n; i++){
    if(freq[i] == 0){
        id.push(i);
    }

  }
  for(int i = 0; i < n; i++){
    if(freq[arr[i]] - 1 == 0) {
        ans[i] = id.top();
        if(id.size()>1)id.pop();
    } else {
        ans[i] = freq[arr[i]] - 1;
    }
  }
  for(auto i: ans) cout << i << " ";
  cout << "\n";
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