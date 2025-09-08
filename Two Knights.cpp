#include <iostream>
#include <vector>

using namespace std;

vector<long long> two_knights_non_attacking(int n) {
    vector<long long> result;
    for (int k = 1; k <= n; ++k) {
        long long kk = k; // promote to long long
        long long total = kk * kk * (kk * kk - 1) / 2;
        long long attacking = 4 * (kk - 1) * (kk - 2);
        result.push_back(total - attacking);
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<long long> answer = two_knights_non_attacking(n);

    for (int i = 0; i < answer.size(); ++i) {
        cout << answer[i] << endl;
    }

    return 0;
}
