// #1. 실패 코드, Prim 알고리즘 활용

// #include <iostream>
// #include <vector>
// #include <queue>
// #include <cmath> // 거리 계산을 위한 헤더 파일 추가
// using namespace std;

// struct Star
// {
//     int idx;
//     double x, y, z;
// };

// struct Edge
// {
//     Star from, to;
//     double weight;

//     // 비교 연산자 수정
//     bool operator<(const Edge &other) const
//     {
//         return weight < other.weight;
//     }
// };

// int N;
// vector<Star> stars;

// // 유클리드 거리를 계산하는 함수
// double calculateDistance(const Star &a, const Star &b)
// {
//     return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
// }

// int Prim()
// {
//     priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
//     vector<bool> visited(N, false);
//     int MSTSum = 0;

//     // 정점 0을 시작 정점으로 선택
//     visited[0] = true;

//     // 시작 정점과 나머지 모든 정점 간의 간선을 우선순위 큐에 삽입
//     for (int i = 1; i < (int)stars.size(); ++i)
//     {
//         double dist = calculateDistance(stars[0], stars[i]); // 유클리드 거리 계산 사용
//         pq.push(Edge({stars[0], stars[i], dist}));
//     }

//     while (!pq.empty())
//     {
//         Edge curEdge = pq.top();
//         pq.pop();

//         Star to = curEdge.to;
//         double weight = curEdge.weight;

//         if (visited[to.idx])
//             continue;

//         MSTSum += weight;
//         visited[to.idx] = true;

//         // 현재 정점과 연결된 간선을 우선순위 큐에 삽입
//         for (int i = 0; i < N; ++i)
//         {
//             if (!visited[i] && i != to.idx)
//             {
//                 double dist = calculateDistance(to, stars[i]); // 유클리드 거리 계산 사용
//                 pq.push(Edge({to, stars[i], dist}));
//             }
//         }
//     }

//     return MSTSum;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     cin >> N;

//     for (int i = 0; i < N; ++i)
//     {
//         double x, y, z;
//         cin >> x >> y >> z;

//         stars.push_back(Star({i, x, y, z}));
//     }

//     // 프림 알고리즘 수행
//     cout << Prim();

//     return 0;
// }

// #2. 성공 코드 :  모든 간선을 우선 구하고, 크루스칼 수행

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Star
{
    int idx, x, y, z;
};

struct Edge
{
    int from, to, weight;
    bool operator<(const Edge &other) const
    {
        return weight < other.weight;
    }
};

int N;
vector<Star> star;
vector<Edge> edge;
vector<int> parent;

int find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = find(parent[u]);
}

bool merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return false;
    parent[u] = v;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    star.resize(N);
    parent.resize(N);
    for (int i = 0; i < N; i++)
    {
        star[i].idx = i;
        cin >> star[i].x >> star[i].y >> star[i].z;
    }

    for (int d = 0; d < 3; d++)
    {
        sort(star.begin(), star.end(), [d](Star &a, Star &b)
             {
            if(d == 0) return a.x < b.x;
            else if(d == 1) return a.y < b.y;
            else return a.z < b.z; });
        for (int i = 0; i < N - 1; i++)
        {
            int w;
            if (d == 0)
                w = abs(star[i].x - star[i + 1].x);
            else if (d == 1)
                w = abs(star[i].y - star[i + 1].y);
            else
                w = abs(star[i].z - star[i + 1].z);
            edge.push_back({star[i].idx, star[i + 1].idx, w});
        }
    }

    sort(edge.begin(), edge.end());
    for (int i = 0; i < N; i++)
        parent[i] = i;

    int answer = 0, cnt = 0;
    for (auto &e : edge)
    {
        if (merge(e.from, e.to))
        {
            answer += e.weight;
            if (++cnt == N - 1)
                break;
        }
    }

    cout << answer;

    return 0;
}
