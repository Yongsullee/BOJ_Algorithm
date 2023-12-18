#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int N;

struct Node
{
    double x, y;
};

double calculateDistance(Node& a, Node& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 소수점 밑으로 2자리까지 표현
    cout.precision(2);
    cout << fixed;
    
    cin >> N;
    
    // 그래프 선언
    vector<Node> graph(N);
    for(int i=0; i<N; ++i)
    {
        cin >> graph[i].x >> graph[i].y;
    }
    
    // 프림 알고리즘
    vector<bool> visited(N, false);
    double MSTWeight = 0;
    // 우선순위 큐, pair< 가중치, 정점 인덱스 >
    priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> pq;

    pq.push({0, 0});
    
    while(!pq.empty())
    {
        int node = pq.top().second;
        double weight = pq.top().first;
        pq.pop();
        
        if(visited[node])
            continue;
        
        visited[node] = true;
        MSTWeight += weight;
        
        for(int i=0; i<N; ++i)
        {
            if(!visited[i])
                pq.push({calculateDistance(graph[node], graph[i]), i});
        }
    }
    
    cout << MSTWeight;
    
    return 0;
}
