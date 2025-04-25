#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

void solve()
{
  int n;
  cin >> n;
  int t;
  int arr[2*n] = {-1};
  bool flg[2 * n + 1] = {false};
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
        cin >> t;
        arr[i+1+j] = t;
        flg[t] = true;
    }
  }
  int missing;
  for(int i = 1; i <= 2*n; i++){
    if(!flg[i]){
        missing = i;
        break;
    }
  }
  for(int i = 0; i < 2 * n; i++){
    if(arr[i] == -1) {
        cout << missing << ' ';
    }else cout << arr[i] << ' ';
  }
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