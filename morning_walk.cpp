#include <bits/stdc++.h>
// #define int long long
#define uint unsigned long long
#define endl '\n'

using namespace std;

char grid[60][60][60];
int cnt = 0;
int sz = 0;
int visited[60][60][60] = {-1};
int time_stamp = 0;
int res_size[60 * 60 * 60] = {0};

void dfs(int x, int y, int z, int &X, int &Y, int &Z, int time_stamp)
{
    visited[x][y][z] = time_stamp;
    cnt++;

    if (x + 1 < X and visited[x + 1][y][z] != time_stamp and grid[x + 1][y][z] == '.')
        dfs(x + 1, y, z, X, Y, Z, time_stamp);
    if (y + 1 < Y and visited[x][y + 1][z] != time_stamp and grid[x][y + 1][z] == '.')
        dfs(x, y + 1, z, X, Y, Z, time_stamp);
    if (z + 1 < Z and visited[x][y][z + 1] != time_stamp and grid[x][y][z + 1] == '.')
        dfs(x, y, z + 1, X, Y, Z, time_stamp);
    if (x - 1 >= 0 and visited[x - 1][y][z] != time_stamp and grid[x - 1][y][z] == '.')
        dfs(x - 1, y, z, X, Y, Z, time_stamp);
    if (y - 1 >= 0 and visited[x][y - 1][z] != time_stamp and grid[x][y - 1][z] == '.')
        dfs(x, y - 1, z, X, Y, Z, time_stamp);
    if (z - 1 >= 0 and visited[x][y][z - 1] != time_stamp and grid[x][y][z - 1] == '.')
        dfs(x, y, z - 1, X, Y, Z, time_stamp);
}
void solve()
{
    int X, Y, Z;
    cin >> X >> Y >> Z;
    for (int z = 0; z < Z; z++)
    {
        for (int x = 0; x < X; x++)
        {
            for (int y = 0; y < Y; y++)
            {
                cin >> grid[x][y][z];
            }
        }
    }
    time_stamp = 0;
    memset(visited, -1, sizeof(visited));

    for (int x = 0; x < X; x++)
    {
        for (int y = 0; y < Y; y++)
        {
            time_stamp++;
            for (int z = 0; z < Z; z++)
            {
                if(visited[x][y][z] == -1 and grid[x][y][z] == '.')
                {
                    cnt = 0;
                    dfs(x, y, z, X, Y, Z, time_stamp);
                    res_size[time_stamp] = cnt;
                    time_stamp++;
                   
                }
            }
        }
    }

    int ans = 0;
    for(int x=0; x<X; x++){
        for(int y=0; y<Y; y++){
            int sz = 0;
            vector<bool> checked(time_stamp+1,false);
            for(int z=0; z<Z; z++){
                int id = visited[x][y][z];
                if(id>0 and !checked[id]){
                    checked[id]=true;
                    sz += res_size[id];
                }
            }
            ans = max(ans, sz);
        }
    }
    cout << ans << endl;
}
int32_t main()
{
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}