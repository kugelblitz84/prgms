#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> stk;
    set<pair<int,int>> ans;
    for(int i = 0; i < 2 * n; i++){
        string s;
        int vertex;
        cin >> s >> vertex;
        if(s == "in"){
            stk.push_back(vertex);
            if(stk.size() > 1){
                int size = stk.size();
                int frst = stk[size - 1];
                int sec = stk[size - 2];
                pair<int,int> edge;
                edge.first = min(frst, sec);
                edge.second = max(frst, sec);
                ans.insert(edge);
            }
        }else{
            stk.pop_back();
        }
    }
    for(auto i: ans){
        cout << i.first << " " << i.second << '\n';
    }
     
}
int32_t main (){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}