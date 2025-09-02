#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
 
 
using namespace std;
 
vector<vector<int>> adj_list(1000000);
int visited[1000000];
int dist[1000000];
int mx=-1,mx_node;
 
void dfs(int n){
	if(mx<dist[n]){
		mx=dist[n];
		mx_node=n;
	}
	if(!visited[n]){
		visited[n]=true;
		for(auto i:adj_list[n]){
			if(!visited[i]) dist[i]=dist[n]+1;
			dfs(i);
		}
		
	}
}
void solve(){
	memset(dist,0,sizeof(dist));
	memset(visited,0,sizeof(visited));
	int n,a,b;
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>a>>b;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}
	dfs(1);
	//cout<<mx<<endl<<mx_node<<endl;
	mx=-1;
	memset(dist,0,sizeof(dist));
	memset(visited,0,sizeof(visited));
	dfs(mx_node);
	//cout<<mx<<endl<<mx_node<<endl;
	cout<<mx<<endl;
}
int main() {
	//memset(dp,-1,sizeof(dp));
    int t=1;
    //cin>>t;
    while(t--){
    	solve();
    }
    return 0;
