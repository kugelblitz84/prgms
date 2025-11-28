#include <bits/stdc++.h>
#define int long long
#define uint unsigned long long
using namespace std;


vector<vector<int>> adjList((int)2e5+7);
stack<int> scc;
vector<bool> inStack((int)2e5+7, false);
vector<vector<int>> sccs;
vector<int> id((int)2e5+7, -1), lowLink((int)2e5+7);
int idCounter = 0;

void dfs(int parent){
    id[parent] = lowLink[parent] = ++idCounter;
    scc.push(parent);
    inStack[parent] = true;
    for(auto child: adjList[parent]){
        if(id[child] == -1){
            dfs(child);
            lowLink[parent] = min(lowLink[parent], lowLink[child]);
        }
        else if(inStack[child]){
            lowLink[parent] = min(lowLink[parent], id[child]);
        }
        
    }
    if(lowLink[parent] == id[parent]){
        vector<int> component;
        int top = -1;
        while(top != parent){
            top = scc.top();
            component.push_back(top);
            scc.pop();
            inStack[top] = false;
        }
        // while(true){
        //     int top = scc.top();
        //     scc.pop();
        //     inStack[top] = false;
        //     component.push_back(top);
        //     if(top == parent) break;
        // }
        sccs.push_back(component);
    }
}


const long long MOD = 1000000007;

vector<long long> partition_numbers(int N) {
    vector<long long> p(N+1, 0);
    p[0] = 1;  

    for (int n = 1; n <= N; n++) {
        long long total = 0;

        for (int k = 1; ; k++) {

            long long g1 = 1LL * k * (3*k - 1) / 2;
            long long g2 = 1LL * k * (3*k + 1) / 2;

            if (g1 > n) break;

            long long sign = (k % 2 ? 1 : -1);

            total = (total + sign * p[n - g1]) % MOD;

            if (g2 <= n)
                total = (total + sign * p[n - g2]) % MOD;
        }

        // fix negative modulus
        if (total < 0) total = (total % MOD + MOD) % MOD;

        p[n] = total;
    }
    return p;
}



void solve(){
    vector<int> p = partition_numbers(2e5 + 1);
    int n, m;
    cin >> n >> m;
    while(m--){
        int u,v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }
    for(int i = 0; i < n; i++){
        if(id[i] == -1){
            dfs(i);
        }
    }
    int ans = 1;
    for(auto i: sccs){
        ans = (ans * p[i.size()]) % 1000000007 ;
    }
    cout << ans << '\n';
    
}

int32_t main (){
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
