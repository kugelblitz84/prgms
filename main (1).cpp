#include <iostream>
#include <string>
#include <cstring>
using namespace std;


long long int value[1000000],weight[100000];
long long int dp[1000][100000];//memoization
memorisation 

long long int knapsack(int index,int capacity){
   if(index<0) return 0;
   if(dp[index][capacity]!=-12) return dp[index][capacity];
   if(capacity>=weight[index]){
      return dp[index][capacity]=max(knapsack(index-1,capacity),knapsack(index-1,capacity-weight[index])+value[index]);
   }else return dp[index][capacity]=knapsack(index-1,capacity);
}
int main() {
   memset(dp,-12,sizeof(dp));
   int n,w;
   cin>>n>>w;
   for(int i=0;i<n;i++){
      cin>>weight[i]>>value[i];
   }
   cout<<knapsack(n-1,w)<<endl;
    return 0;
}    