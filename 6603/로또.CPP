/*
    [문제] : 백트래킹 활용 조합 문제
    [설명]
            1. DFS 구현
            2. 현재 노드가 비 방문 노드일 경우, DSF 탐색 수행 후 방문 여부 초기화와 현재 노드에 대한 결과 값 롤백
            3. 현재 노드가 방문 노드일 경우, 다음 후보 경로 탐색
*/

#include <iostream>
#include <vector>
using namespace std;

#define MAX 13

int K;
int S[MAX];
vector<bool> visited;

void dfs(int start, int cnt, vector<int>& ans)
{
    if(cnt == 6) // #1. 6개의 숫자를 골랐을 때 출력
    {
        for(int i = 0; i < 6; ++i)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = start; i < K; ++i) // #3. 이전에 선택한 숫자 다음부터 탐색 시작
    {
        if(!visited[i])
        {
            visited[i] = true;
            ans.push_back(S[i]);
            dfs(i + 1, cnt + 1, ans); // #2. dfs 재귀 호출 시 ans 전달
            visited[i] = false;
            ans.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(true)
    {
        cin >> K;

        if(K == 0)
            break;

        for(int i = 0; i < K; ++i)
        {
            cin >> S[i];
        }

        visited.resize(K, false);
        vector<int> ans;

        dfs(0, 0, ans); // 초기 start 인덱스와 cnt를 0으로 설정

        cout << '\n'; // 각 테스트 케이스 사이에 빈 줄 출력
    }

    return 0;
}
