#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

vector<int> fen(200000 + 7);

void updateRange(int start, int end, int size, int val){
    while(start <= size){
        fen[start] += val;
        start += start & -start;
    }
    end++;
    while(end <= size){
        fen[end] -= val;
        end += end & -end;
    }
}

int sum(int k){
    int s = 0;
    while(k > 0){
        s += fen[k];
        k -= k & -k;
    }
    return s;
}
void solve()
{
    int n, m;
    cin >> n>> m;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++) cin >> arr[i];
    while(m--){
        int t;
        cin >> t;
        if(t == 1){
            int start, end, val;
            cin >> start >> end >> val;
            updateRange(start, end, n, val);
        }else{
            int k;
            cin >> k;
            cout << arr[k] + sum(k) << '\n';
        }
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