#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    map<int, int> hash;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if(hash[temp] == 0) arr.push_back(temp);
        hash[temp]++;
        
    }
    //sort(arr.begin(), arr.end());
    int ops = 0;
    for(int i = 0; i < arr.size(); i++){
        //int arr[i] = arr[i];
        //if(hash[i]) cout << i << ": " << hash[i] << endl;
        if(hash[arr[i]] > k){
            int opsRequired = hash[arr[i]] - k;
            int endPoint = arr[i] + opsRequired;
            if(i + 1 < arr.size() and endPoint >= arr[i + 1]) {
                hash[arr[i + 1]] += hash[arr[i]] - (arr[i + 1] - arr[i]);
                ops += (arr[i + 1] - arr[i]);
            }else {
                ops += opsRequired;
            }
            //hash[arr[i]] = 1;
            
        }
    }
    //if(hash[n - 1] > k) ops += hash[n - 1];
    cout << ops << '\n';
  
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