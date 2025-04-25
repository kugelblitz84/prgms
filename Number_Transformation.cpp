#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    string a, b;
    bool flag = true;
    while(n){
        if(n >= 5) a += '5';
        else a += '0' + n;
        n -= min(n, (int)5);
    }
    for(auto i: a){
        if(i == '5') b += i;
        else b += '0' + (10 - (i - '0'));
    }
    cout << a << '\n' << b;
    

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++)
    {
        //cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}
