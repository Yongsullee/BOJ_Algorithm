/*

    [문제] : 히스토그램의 최대 직사각형 넓이를 "스택"을 활용해 구하는 문제

    [풀이]

    1.  먼저, 히스토그램 각 막대의 높이를 저장하는 배열 정의
    2.  현재 막대가 stack의 top의 높이보다 작을 경우, 직사각형 계산을 수행
    3.  i = 5 이고 s.top() = 4 일 경우, 직사각형의 넓이는 height = s.top(), 밑변은 width = i - s.top() - 1 이됩니다.
    4.  주의할점은 배열을 순회할 경우 N+1까지 순회합니다. 왜냐하면, 마지막 막대가 s.top() 값보다 크거나 같을 경우 stack에 push만 하고 작업이 종료되기 때문입니다.
    5.  주의할점은 직사각형의 Width를 계산할 때 단순히 widht = 1로 설정하고 왼쪽으로 base++ 할 경우, stack에 저장된 인덱스가 (bottom) [ 0, 2, 3, 4 ] (top) 오름차순만 유지하며
        각 인덱스가 1차이라고 보장할 수 없기 때문입니다. 따라서, 단순히 왼쪽으로 1씩 카운트 하지 않고, i - top() - 1 처럼 인덱스 값의 차이를 구하는 것이 바람직합니다.

*/

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int N, ans, h[100002];
stack<int> s;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    cin >> N;
    
    for(int i=1; i<=N; i++)
    {
        cin >> h[i];
    }
    
    s.push(0);
    for(int i=1; i<=N+1; i++)
    {
        while(!s.empty() && h[s.top()] > h[i])
        {
            int cur = s.top();
            s.pop();
            int width = i - s.top() - 1;
            ans = max(ans, h[cur] * width);
        }
        s.push(i);
    }
    
    cout << ans;
    
    return 0;
}