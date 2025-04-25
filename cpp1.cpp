#include <bits\stdc++.h>
//#define int long long
using namespace std;
string add(string s1,string s2){
    int diff = abs(s1.size() - s2.size());
    //cout<<diff<<"\n";
    string leading_zero(diff,'0');
    s1.size() < s2.size() ? s1 = leading_zero + s1 : s2 = leading_zero + s2;
    string ans = "";
    int res = 0,car = 0;
    for(int i= s1.size()-1;i>=0; i--){
        res = (s1[i] -'0') + (s2[i] - '0') + car;
        car = res/10;
        res %= 10;
        char tmp = '0' + res;
        ans =  tmp + ans;
    }
    if(car) {
        char temp = '0' + car;
        ans = temp + ans;
    }
    return ans;
}
string mult(string s1,string s2){
    if(s1.size() < s2.size()) swap(s1,s2);
    vector<string> to_be_added;
    int res = 0,carry = 0;
    for(int i=s2.size()-1 ;i>=0 ;i--){
        string temp = "";
        for(int j=s1.size()-1;j>=0;j--){
            res = ((s2[i] - '0')*(s1[j] - '0')) + carry ;
            carry = res / 10;
            res %= 10;
            char result = '0' + res;
            temp = result + temp;
        }
        if(carry){
            char car = '0' + carry;
            temp = car + temp;
        }

        to_be_added.push_back(temp);
    }
    string trail_zero(s2.size()-1,'0');
    string ans = to_be_added.back() + trail_zero;
    to_be_added.pop_back();
    trail_zero.pop_back();
    while(!to_be_added.empty()){
        string temp = to_be_added.back() + trail_zero;
        ans = add(ans,temp);
        to_be_added.pop_back();
        if(!trail_zero.empty()) trail_zero.pop_back();
    }
    return ans;
}

string fact(int n){
    //if(n == 0) return "1";
    if(n == 1) return "1";
    return mult(to_string(n),fact(n-1));
}
// void solve(){
    
    
// }
int32_t main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // int t = 1;
    // //cin>>t;
    // while(t--) solve();
    string s1,s2;
    cin>>s1>>s2;
    cout<<s1<<"X"<<s2<<"="<<mult(s1,s2);
    return 0;
}