#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

vector<int> pre(1000001, 1);
void solve()
{
    int n;
    cin >> n;
    cout << pre[n] << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int cnt = 0, cntn = 0;
    for(int i = 2; i <= 1000000; i++){
        //bool flag = true;
        
        for(int j = i; j <= 1000000; j += i){
            cnt++;
            pre[j]++;
        }
    }
    cout << "complexity: " << cnt/1000000.0 << " * n\n";
    //cout << "number of distinct primes: " << cntn << "\n";
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case " << i <<": ";
        solve();
    }
    return 0;
}