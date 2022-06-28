#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> arr;
bool visited[20] = {0,};

void dfs(int cnt)
{
    if(cnt == M)
    {
        
    }
    for(int i=0; i<N; i++)
    {
        if(visited[i] == false)
        {
            visited[i] = true;
            
        }
    }
}

int main ()
{   
    cin >> N;
    M = N/2;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    dfs(0);
}