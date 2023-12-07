#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m;

// #1. Find 연산 : path-compression 최적화
int Find(int x, vector<int>& parent)
{
    if(parent[x] != x)
        parent[x] = Find(parent[x], parent);
    
    return parent[x];
}

// #2. Union 연산 : union-by-rank 최적화
void Union(int rootX, int rootY, vector<int>& parent, vector<int>& rank)
{ 
    // rootX의 랭크 > rootY의 랭크 : rootX를 rootY의 parent로 변경
    if(rank[rootX] > rank[rootY])
    {
        parent[rootY] = rootX;
    }
    // rootX의 랭크 < rootY의 랭크 : rootY를 rootX의 parent로 변경
    else if(rank[rootX] < rank[rootY])
    {
        parent[rootX] = rootY;
    }
    // rootX의 랭크 = rootY의 랭크 : rootY를 rootX의 parent로 변경, rootY의 랭크 상승 +1
    else
    {
        parent[rootX] = rootY;
        rank[rootY]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    
    // parent 목록 
    vector<int> parent(n+1);
    // parent 목록에서 해당 정점의 부모를 자신으로 초기화
    for(int i=0; i<=n; i++)
        parent[i] = i;
    // rank 목록, 0으로 초기화
    vector<int> rank(n+1, 0);
    
    int unionOrJoint = -1;
    while(cin >> unionOrJoint)
    {
        int a, b;
        cin >> a >> b;
        
        // #1. a와 b가 속해있는 집합의 루트 노드 찾기
        int rootX = Find(a, parent);
        int rootY = Find(b, parent);
        
        // #2. 합집합 연산 -> Union 연산
        if(unionOrJoint == 0)
        {
            // #1-1. 각 숫자의 루트 노드가 다르다면 서로 다른 집합으로 가정하고 Union 연산 수행
            if(rootX != rootY)
            {
                Union(rootX, rootY, parent, rank);
            }
        }
        // #3. 같은 집합 여부 -> Find 연산, 결과 출력
        else if(unionOrJoint == 1)
        {
            // #2-1. 서로 같은 루트 노드를 가지면, 같은 집합에 속해있음
            if(rootX == rootY)
            {
                cout << "YES" << '\n';
            }
            // #2-2. 서로 다른 루트 노드를 가지면, 다른 집합에 속해있음
            else
            {
                cout << "NO" << '\n';
            }
        }
    }
    
    return 0;
}