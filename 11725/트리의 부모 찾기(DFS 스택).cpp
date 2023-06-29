#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> graph[100001];
int ans[100001];
bool visited[100001] = {0,};

void DFS(int start)
{
    stack<int> s;
    visited[100001] = {0,};
    
    s.push(start);
    visited[start] = true;
    
    while(!s.empty())
    {
        int cur = s.top();
        s.pop();
        for(const auto& next : graph[cur])
        {
            if(!visited[next])
            {
                visited[next] = true;
                ans[next] = cur;
                s.push(next);
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