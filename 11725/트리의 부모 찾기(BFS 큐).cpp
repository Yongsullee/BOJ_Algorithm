#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[100001];
int ans[100001];

void BFS(int start)
{
    queue<int> q;
    bool visited[100001] = {0,};
    
    q.push(start);
    visited[start] = true;
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(const auto& neighbor : graph[cur])
        {
            if(!visited[neighbor])
            {
                visited[neighbor] = true;
                ans[neighbor] = cur;
                q.push(neighbor);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int N;
    cin >> N;
    
    for(int i=1; i<=N; i++)
    {
        int from, to;
        cin >> from;
        cin >> to;
        
        graph[to].push_back(from);
        graph[from].push_back(to);
    }
    
    BFS(1);
    
    for(int i=2; i<=N; i++)
        cout << ans[i] << '\n';
}