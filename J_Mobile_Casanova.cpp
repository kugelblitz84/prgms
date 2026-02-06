#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

string processed (long long first, long long last){
    string a = string("0") + to_string(first);
    string b = string("0") + to_string(last);
    int m = min((int)a.size(), (int)b.size());
    int k = 0;
    while(k < m && a[k] == b[k]) ++k;    
    return a + "-" + b.substr(k);
}

void solve()
{
    int tt = 0;
    while(++tt){
        int t;
        cin >> t;
        if(t == 0) return;
        cout << "Case " << tt <<":\n";
        int prev = -1, last = -1, first = -1;
        vector<string> ans;
        for(int i = 0; i < t; i++){
            int temp;
            cin >> temp;
            if(i == t - 1) last = temp; 
            if(temp == prev + 1){
                //cur = temp;
                if(first == -1) first = prev;
            }else if(first != -1){
                last = prev;
                if(!ans.empty()) ans.pop_back();
                ans.push_back(processed(first, last));
                first = -1, last = -1;
                ans.push_back("0" + to_string(temp));
            }else ans.push_back("0" + to_string(temp));
            prev = temp;
        }
        if(first != -1){
            if(!ans.empty()) ans.pop_back();
            ans.push_back(processed(first, last));
        }
        for(auto i: ans){
            cout << i << '\n';
        }
        cout << '\n';
    }
  
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case " << i <<": ";
        solve();
    }
    return 0;
}