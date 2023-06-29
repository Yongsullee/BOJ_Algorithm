#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[100001];
int ans[100001];
bool visited[100001] = {0,};

void DFS(int start)
{
    visited[start] = true;
    for(int i=0; i<graph[start].size(); i++)
    {
        int neighbor = graph[start][i];
        if(!visited[neighbor])
        {
            ans[neighbor] = start;
            DFS(neighbor);
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
        int x,y;
        cin >> x;
        cin >> y;
        
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    DFS(1);
    
    for(int i=2; i<=N; i++)
    {
        cout << ans[i] << '\n';
    }
    
}