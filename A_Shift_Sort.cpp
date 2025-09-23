#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

void solve()
{
    string s;
    int n;
    cin >> n;
    cin >> s;
    string temp = s;
    sort(s.begin(), s.end());
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(temp[i] != s[i]){
            ans++;
            
        }
    }
    //cout <<"\n"<< o << " " << z << "\n";

    cout << (ans >> 1) << "\n";
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