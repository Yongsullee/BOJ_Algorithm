#include <iostream>
#include <vector>
using namespace std;

typedef pair<int,int> p;

int w, h, island;
vector<vector<int>> map;

int dy[] = {1,1,1,0,0,-1,-1,-1};
int dx[] = {-1,0,1,-1,1,-1,0,1};

void dfs(p cPos)
{
    int cy = cPos.first;
    int cx = cPos.second;

    map[cy][cx] = 0;

    for(int i=0; i<8; ++i)
    {
        int ny = cy + dy[i];
        int nx = cx + dx[i];

        if(ny < 0 || ny >= h || nx < 0 || nx >= w || map[ny][nx] == 0)
            continue;

        dfs({ny,nx});
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(1)
    {
        cin >> w >> h;

        if(w == 0 && h == 0)
            break;

        map.clear();
        island = 0;

        map.resize(h, vector<int>(w));

        for(int i=0; i<h; ++i)
        {
            for(int j=0; j<w; ++j)
            {
                cin >> map[i][j];
            }
        }

        // dfs 수행
        for(int i=0; i<h; ++i)
        {
            for(int j=0; j<w; ++j)
            {
                if(map[i][j] == 1)
                {
                    dfs({i,j});
                    island++;
                }
            }
        }

        cout << island << '\n';
    }

    return 0;
}