#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    if((k/2) * (k/2) >= n){
        cout << -1 << "\n";
        return;
    }
    vector<int> sm, bg;
    sm.push_back(1);
    bg.push_back(n);
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            sm.push_back(i);
            if(i * i != n) bg.push_back(n / i);
        }
    }
    if(k <= sm.size()){
        cout << sm[k - 1] << "\n";
        return;
    }
    if(k <= sm.size() + bg.size()){
        cout << bg[bg.size() - (k - sm.size())] << "\n";
        return;
    }
    cout << -1 << "\n";

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case " << i <<": ";
        solve();
    }
    return 0;
}