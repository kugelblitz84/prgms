#include <bits/stdc++.h>
#define int long long 
using namespace std;
static bool init = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return true;
}();
//int MAX = 200000;
vector<int> tree[400005];
int arr[200010];
void build_tree(int low,int high,int at_node){
    if(high == low){
        tree[at_node].push_back(arr[high]);
        return ;
    }
    int mid = (high + low) >> 1;
    build_tree(low,mid,(2*at_node)+1);
    build_tree(mid+1,high,(2*at_node)+2);
    tree[at_node].resize(high - low + 1);
    merge(tree[(2*at_node)+1].begin(),tree[(2*at_node)+1].end(),tree[(2*at_node)+2].begin(),tree[(2*at_node)+2].end(),tree[at_node].begin());
}

int number_of_items_lessthan(int x,int low,int high,int at_node,int node_low,int node_high){
    if(node_high < low or node_low > high) return 0;
    if(node_high <= high and node_low >= low){
        return (upper_bound(tree[at_node].begin(),tree[at_node].end(),x) - tree[at_node].begin());
    }
    int mid = (node_low + node_high) >> 1;
    return (number_of_items_lessthan(x,low,high,(2*at_node)+1, node_low,mid) + number_of_items_lessthan(x,low,high,(2*at_node)+2,mid+1,node_high));
}
void solve(){
    int q,n;
    cin>>n>>q;
    for(int i=0;i<n;i++) {
    	cin>>arr[i];
    }
    build_tree(0,n-1,0);
    while(q--){
        int l,r,k,ans=0;
        cin>>l>>r>>k;
        int high = (int)(1e9+1),low = INT_MIN/2;
        while(high > low){
            int mid = (high + low) >> 1;
            int num = number_of_items_lessthan(mid,l-1,r-1,0,0,n-1);
            if(num < k) low = mid+1;
            else {
                high = mid;
            }
        }
        cout << low << "\n";        
    }


}

int32_t main(){
    //cout<<1;
    int t = 1;
    //cin>>t;
    while(t--) {
    	solve();
    }
    return 0;
}