#include <bits/stdc++.h>

using namespace std;
string add(string first,string sec){
    //cout<<(sec.size()<first.size());
    int diff = abs((int)first.size()-(int)sec.size());
    string leading_zero(diff,'0');
    first.size() < sec.size() ? first = leading_zero + first : sec = leading_zero + sec;
    string ans = "";
    int res = 0,car = 0;
    for(int i= first.size()-1;i>=0; i--){
        res = (first[i] -'0') + (sec[i] - '0') + car;
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
    string ans = "";
    string trail_zero = "";
    int decimal = 0;
    for(int i=s2.size()-1 ;i>=0 ;i--){
        if(s2[i] == '.'){
            decimal += s2.size()-i-1;
            continue;
        }
        int res = 0,carry = 0;
        string temp = "";
        for(int j=s1.size()-1;j>=0;j--){
            if(s1[i] == '.'){
                decimal += s1.size()-j-1;
                continue;
            }
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
        if(i == s2.size()-1) ans = temp;
        else {
            temp = temp + trail_zero;  
            ans = add(temp ,ans );
        }
        trail_zero += "0";
    }
    if(decimal)
    return ans;
}

int compare_string(string s1,string s2){
    if(s1.size() == s2.size()){
        for(int i=0;i<s1.size();i++) {
            if(s1[i]>s2[i]) return true;
            else if(s1[i]<s2[i]) return false;
        }
        //return -1;
    }
    return (s1.size() > s2.size());
}

string div(string s1,string s2){ //incomplete
    string ans;
    if(s2 == "0") return "INF";
    if(s1 == "0") return "0";
    if(s1 == s2) return "1";
    int decimal = 0;
    while(compare_string(s1,s2) != 1) s1+="0",decimal++;
}

int main(){
    string a,b;
    cin >> a >> b;
    cout << mult(a,b);
    return 0;
}