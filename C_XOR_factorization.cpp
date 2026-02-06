#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

int findBits(int n){
    int cnt = 0;
    while(n) cnt++, n >>= 1;
    return cnt;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    
    if(m & 1) {
        for(int i = 0; i < m; i++) cout << n << ' ';
        cout << '\n';
    }
    else{
        for(int i = 0; i < m - 2; i++) cout << n << ' ';
        int bits = findBits(n);
        int msb = 1LL << (bits - 1);
        
        // To maximize a + b where a XOR b = n:
        // Set a = msb | (all bits below msb that are 0 in n)
        // This keeps a <= n and maximizes the sum
        int mask = msb - 1;  // all bits below msb
        int zeroBits = mask & (~n);  // bits that are 0 in n (below msb)
        int first = msb | zeroBits;
        int second = first ^ n;
        
        cout << first << ' ' << second << '\n';
    }
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