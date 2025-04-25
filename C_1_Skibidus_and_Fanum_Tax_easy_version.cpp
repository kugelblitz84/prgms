#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

void solve()
{
  int n, m;
  cin >> n >> m;
  int arr[n], b;
  bool has[n] = {false};
  for(auto &i: arr) cin >> i;
  cin >> b;
  if(b - arr[0] < arr[0]) arr[0] = b - arr[0], has[0] = true;
  for(int i = 1; i < n; i++){
    if(arr[i] < arr[i - 1]){
        if(b - arr[i] >= arr[i - 1] and !has[i]){
            arr[i] = b - arr[i];
            has[i] = true;
        }else if(b - arr[i - 1] <= arr[i] and !has[i - 1]) arr[i - 1] = b - arr[i - 1], has[i - 1] = true;
        else {cout << "NO\n"; return;}
    }else if(b - arr[i] < arr[i] and b - arr[i] >= arr[i - 1] and !has[i]) arr[i] = b - arr[i], has[i] = true;
  }
  if(is_sorted(arr, arr + n)) cout << "YES\n";
  else cout << "NO\n";
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