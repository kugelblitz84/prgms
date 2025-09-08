//  Relay (handoff) model solution with binary search:
//  Statement allows: a swimmer rides a boat for some prefix, leaves it; trailing swimmer reaches boat later and continues.
//  Boat cannot move without a swimmer, so after delivering distance r for a swimmer, if it is to be reused it must WAIT
//  until the next swimmer (speed X) reaches that handoff point. Thus commitment time per swimmer using r boat distance
//  is at least r / X (boat moving + possible waiting). For a candidate finish time T (< D/X so help is needed), each
//  swimmer must get minimum boat distance:
//      r(T) = (D/X - T) / (1/X - 1/Y) = Y (D - X T) / (X (Y - X))   (clamped to >=0).
//  Feasibility condition (all swimmers finish by T): total boat time supply K * T >= total demand N * r(T) / X.
//  If T >= D/X then r(T)=0 and everyone can just swim. Edge cases:
//    - Y <= X: boats give no speedup -> answer D / X.
//    - K >= N: every swimmer can keep a boat entire way -> answer D / Y.
//  Otherwise binary search minimal T in [0, D/X].

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int Tcases; if(!(cin>>Tcases)) return 0;
    cout.setf(ios::fixed); cout<<setprecision(10);
    while(Tcases--){
        long long N, K; long double D, X, Y; // input order: N K  then D X Y
        cin >> N >> K >> D >> X >> Y;
        long double ans;
        if (Y <= X) {
            ans = D / X; // boats useless
        } else if (K >= N) {
            ans = D / Y; // every swimmer can stay on a boat
        } else {
            // Effective speed derived: v = ( N*X + 2*K*Y ) / ( N + 2*K )
            long double v = ( (long double)N * X + 2.0L * (long double)K * Y ) / ( (long double)N + 2.0L * (long double)K );
            ans = D / v;
        }
        cout << ans << '\n';
    }
    return 0;
}
