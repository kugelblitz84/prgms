#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

void solve()
{
    int a,b;
    cin >> a >> b;
    if(a == b){
        cout << 0 << "\n";
    }else if(a == 1 or b == 1){
        cout << 1 << "\n";
    }else if(max(a,b) % min(a,b) == 0){
        cout << 1 << "\n";
    }else cout << 2 << "\n";
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