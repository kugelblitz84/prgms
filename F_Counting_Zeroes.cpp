#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

vector<int> primes;
map<int, bool> isNotPrime;
void sieve(){
    int n = 1000000;
    isNotPrime[1] = true;
    for(int i = 2; i * i <= n; i++){
        if(!isNotPrime[i]){
            for(int j = i * i; j <= n; j += i){
                isNotPrime[j] = true;
            }
        }
    }
    for(int i = 2; i <= n; i++) if(!isNotPrime[i]) primes.push_back(i);
}
void solve()
{
    int t;
    while(cin >> t){
        if(t == 0) break;
        int temp = t;
        int ans = 0;
        int totalDivisors = 1;
        for(auto i: primes){
            //cout << i << "\n";
            if(1ULL * i * i > temp) break;
            int cnt = 0;
            while(temp % i == 0){
                temp /= i;
                cnt++;
            }
            totalDivisors *= (cnt + 1);
            ans += cnt - 1; //since we have counted 1 zero for each divisors we should consider 1 less for each prime divisros
        }
        if(temp > 1) totalDivisors *= 2;
        ans += totalDivisors - 1; //excluding 1 as divisor
        cout << t << ' ' << ans << '\n';
        cout << "Total divisors: " << totalDivisors << "\n";
    }
  
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case " << i <<": ";
        solve();
    }
    return 0;
}