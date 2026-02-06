#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    map<int, int> cnt;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        cnt[temp]++;
    }
    
    // Track "running" = drones flowing through current position
    // As we move right between levels, running decreases by 1 per level (1 drone settles)
    // At each level, add cnt[level] to running
    // Answer = (last level with running > k) - (first level with running > k) + 1
    
    int running = 0;
    int prevLevel = -1;
    int firstOverflow = -1;
    int lastOverflow = -1;
    
    for(auto& [level, c] : cnt){
        // Move from prevLevel to level: running decreases by gap
        if(prevLevel != -1){
            int gap = level - prevLevel;
            running = max(0LL, running - gap);
        }
        
        // Add new drones at this level
        running += c;
        
        // Check if overflow (count > k)
        if(running > k){
            if(firstOverflow == -1) firstOverflow = level;
            lastOverflow = level;
        }
        
        prevLevel = level;
    }
    
    // After last level, if running still > k, it continues to spread
    // Last level with count > k is prevLevel + (running - k - 1) when running > k
    if(running > k){
        lastOverflow = prevLevel + running - k - 1;
    }
    
    if(firstOverflow == -1){
        cout << 0 << '\n';
    } else {
        cout << lastOverflow - firstOverflow + 1 << '\n';
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
// k = 2
//2 2 2 2 2 2 2
//2 3 3 3 3 3 3
//2 3 4 4 4 4 4