#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <vector>
 
using namespace std;
 
 
 
int main(){
    long long int mod=1e9+7;
    int n;
    cin>>n;
    vector<long long int> arr(n+1);
    arr[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6 and i>=j;j++){
            arr[i]+=arr[i-j]%mod;
        }
    }
    cout<<arr[n]%mod<<endl;
 
    return 0;
}