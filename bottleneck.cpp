#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> adj_list(101);
//vector<int> dist(100), parent(100);

void dijkstra(int from, int dest, int &max_band){
    priority_queue<pair<int,int>> q;
    //vector<bool> visited(100);
    vector<int>bandwidth_to(101);
    bandwidth_to[from] = 1e9 + 10;
    //visited[from] = true;
    q.push({1e9 + 10,from});
    int current_max = 0;
    while(!q.empty()){
        pair<int,int> parent_node = q.top();
        q.pop();
        if(parent_node.second == dest){
            max_band = bandwidth_to[dest];

            // cout << "found\n";
            // for(int i = from; i <= dest; i++){
            //     cout << from << "->" << i << "=" << bandwidth_to[i] <<'\n';
            // }
            // return;
        }
        // if(visited[parent_node.second]){
        //    continue;
        // }else visited[parent_node.second] = true;
        for(auto to : adj_list[parent_node.second]){
            int weight = to.second;
            if(min(weight,bandwidth_to[parent_node.second]) > bandwidth_to[to.first]){
                bandwidth_to[to.first] = min(weight,bandwidth_to[parent_node.second]);
                q.push({to.second, to.first});
            }
        }
    }
}
int main(){
    int n, m, q;
    cin >> n >> m >> q;
    while(m--){
        int from, to, cost;
        cin >> from >> to >> cost;
        adj_list[from].push_back({to, cost});
        adj_list[to].push_back({from, cost});
    }
    while(q--){
        int from, to, need;
        //vector<int> parent(100);
        int max_band = 0;
        cin >> from >> to >> need;
        dijkstra(from, to, max_band);
        cout << (need > max_band ? "NO\n" : "YES\n"); 
    }
    return 0;
}