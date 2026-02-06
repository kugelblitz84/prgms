#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int grid[55][55][55];  // stores reservoir ID (0 = rock, >0 = reservoir id)
int reservoir_size[55*55*55];
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

void solve(){
    int X, Y, Z;
    cin >> X >> Y >> Z;
    
    // Read grid: -1 = unvisited gas, 0 = rock
    char c;
    for(int z = 0; z < Z; z++){
        for(int x = 0; x < X; x++){
            for(int y = 0; y < Y; y++){
                cin >> c;
                grid[x][y][z] = (c == '.') ? -1 : 0;
            }
        }
    }
    
    // BFS to find all reservoirs and their sizes
    int reservoir_id = 0;
    queue<tuple<int,int,int>> q;
    
    for(int x = 0; x < X; x++){
        for(int y = 0; y < Y; y++){
            for(int z = 0; z < Z; z++){
                if(grid[x][y][z] == -1){
                    reservoir_id++;
                    int size = 0;
                    q.push({x, y, z});
                    grid[x][y][z] = reservoir_id;
                    
                    while(!q.empty()){
                        auto [cx, cy, cz] = q.front();
                        q.pop();
                        size++;
                        
                        for(int d = 0; d < 6; d++){
                            int nx = cx + dx[d];
                            int ny = cy + dy[d];
                            int nz = cz + dz[d];
                            if(nx >= 0 && nx < X && ny >= 0 && ny < Y && nz >= 0 && nz < Z && grid[nx][ny][nz] == -1){
                                grid[nx][ny][nz] = reservoir_id;
                                q.push({nx, ny, nz});
                            }
                        }
                    }
                    reservoir_size[reservoir_id] = size;
                }
            }
        }
    }
    
    // For each (x,y), find distinct reservoirs intersecting the column
    int ans = 0;
    vector<bool> seen(reservoir_id + 1, false);
    
    for(int x = 0; x < X; x++){
        for(int y = 0; y < Y; y++){
            int total = 0;
            for(int z = 0; z < Z; z++){
                int rid = grid[x][y][z];
                if(rid > 0 && !seen[rid]){
                    seen[rid] = true;
                    total += reservoir_size[rid];
                }
            }
            ans = max(ans, total);
            // Reset seen for cells in this column
            for(int z = 0; z < Z; z++){
                if(grid[x][y][z] > 0) seen[grid[x][y][z]] = false;
            }
        }
    }
    
    cout << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}