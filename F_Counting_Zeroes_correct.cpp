#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using u64 = unsigned long long;

// Count prime factors of n (n <= 1e13)
static vector<int> primes;

static void sieve(int limit = 1000000) {
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * 1LL * i <= limit; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) isPrime[j] = false;
        }
    }
    for (int i = 2; i <= limit; ++i) if (isPrime[i]) primes.push_back(i);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    u64 n;
    while (cin >> n && n != 0) {
        if (n == 1) {
            cout << 1 << " 0\n";
            continue;
        }

        u64 tmp = n;
        vector<int> exps;
        for (int p : primes) {
            if (1ULL * p * p > tmp) break;
            if (tmp % p == 0) {
                int cnt = 0;
                while (tmp % p == 0) {
                    tmp /= p;
                    ++cnt;
                }
                exps.push_back(cnt);
            }
        }
        if (tmp > 1) exps.push_back(1); // remaining prime factor

        int maxE = *max_element(exps.begin(), exps.end());

        u64 ans = 0;
        for (int k = 1; k <= maxE; ++k) {
            u64 ways = 1;
            for (int e : exps) {
                ways *= (e / k + 1);
            }
            ans += ways - 1; // exclude base=1
        }

        cout << n << " " << ans << '\n';
    }

    return 0;
}