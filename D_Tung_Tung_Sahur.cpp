#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

void solve()
{

    string hit, heard;
    cin >> hit >> heard;
    int previ = 0, prevj = 0;
    int i = 0,j = 0;
    while ( i < hit.size() and j < heard.size())
    {
        char ht = hit[i],hr = heard[j];
        int hits = 0,heards = 0;
        while (i < hit.size() and ht == hit[i]){
            hits++;
            i++;
        }
        while(j < heard.size() and hr == heard[j]){
            heards++;
            j++;
        }
        if(hits > heards or hits * 2 < heards or ht != hr){
            cout << "NO\n";
            return;
        }
        previ = i;
        prevj = j;
        
    }
    if(i < hit.size() or j < heard.size()) cout << "NO\n";
    else cout << "YES\n";
    
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
