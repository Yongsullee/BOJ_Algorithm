#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <queue>
using namespace std;

typedef pair<int,int> p;

int n;
vector<vector<int>> graph, dist;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

int flip(int num)
{
    return num^1;
}

void dijkstra()
{
    priority_queue<pair<int, p>, vector<pair<int,p>>, greater<pair<int,p>>> pq;
    dist[0][0] = flip(graph[0][0]);
    pq.push({dist[0][0], {0,0}});
    
    while(!pq.empty())
    {
        p cur_vertex = pq.top().second;
        int cur_weight = pq.top().first;
        pq.pop();
        
        if(cur_weight > dist[cur_vertex.first][cur_vertex.second])
            continue;
        
        for(int i=0; i<4; ++i)
        {
            int ny = cur_vertex.first + dy[i];
            int nx = cur_vertex.second + dx[i];
            
            if(ny >= n || ny < 0 || nx >= n || nx < 0)
                continue;
            
            int new_dist = cur_weight + flip(graph[ny][nx]);
            if(dist[ny][nx] > new_dist)
            {
                dist[ny][nx] = new_dist;
                pq.push({new_dist, {ny, nx}});
            }
        }
    }
    
    cout << dist[n-1][n-1];
}
    
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    
    graph.resize(n, vector<int>(n));
    dist.resize(n, vector<int>(n, INT_MAX));
    
    for(int i=0; i<n; ++i)
    {
        string temp;
        cin >> temp;
        for(int j=0; j<n; ++j)
        {
            graph[i][j] = temp[j] - '0';
        }
    }
    
    dijkstra();
    
    return 0;
}
