#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;


int parse_table[100000 + 7][18];

void build_parse_table(const vector<int>& arr, int n) {
    for(int pOfLengthOfWindow = 0; pOfLengthOfWindow <= 17; pOfLengthOfWindow++) {
        int lengthOfWindow = 1 << pOfLengthOfWindow;
        for(int startIndex = 0; startIndex + lengthOfWindow - 1 < n; startIndex++){
            if(lengthOfWindow == 1){
                parse_table[startIndex][pOfLengthOfWindow] = arr[startIndex];
            }else {
                int halfLength = lengthOfWindow >> 1;
                parse_table[startIndex][pOfLengthOfWindow] = min(
                    parse_table[startIndex][pOfLengthOfWindow - 1],
                    parse_table[startIndex + halfLength][pOfLengthOfWindow - 1]
                );
            }
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &x : arr) cin >> x;
    build_parse_table(arr, n);
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        int length = r - l + 1;
        int pOfLength = 0;
        while((1 << (pOfLength + 1)) <= length) pOfLength++;
        //int lengthOfWindow = 1 << pOfLength;
        cout << min(
            parse_table[l][pOfLength],
            parse_table[r - (1 << pOfLength) + 1][pOfLength]
        ) << '\n';
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