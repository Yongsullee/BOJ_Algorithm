// Commit 수정

/*
*   [목적] : 오른쪽 값들 중 현재 값보다 크며 가장 왼쪽에 위치한 값을 찾는 문제
*   [풀이]
*   
*   1. 문제에서 주어진 배열을 역순으로 두어 생각합니다.
*       eg) 기존의 수열 : 3, 5, 2, 7    ->  역순의 수열 : 7, 2, 5, 3
*
*   2. stack이 비어있지 않고, i 위치의 현재 값이 stack.top()의 값보다 크다면 stack.pop()을 수행합니다.
*   3. stack이 비어있지 않고, i 위치의 현재 값이 stack.top()의 값보다 작다면 stack.top()의 값이 NEG(i)가 됩니다.
*   4. 마지막으로, stack에 i위치의 현재 값을 push하고, i+1로 넘어갑니다.
*   
*   왜?
*   1. s.top()을 현재 i위치의 값보다 작다면, i+1 위치의 값이 찾고 있는 NGE(i+1)이 절대 될 수 없기 때문입니다.
*   2. stack 내부에 현재 i위치의 값보다 왼쪽에 위치하는 최신의 값들(s.top()) 오름차순(top -> bottom)으로 유지함으로써,
*       위 조건을 충족하는 수를 찾을 수 있기 때문입니다.
*/


#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int N;
    stack<int> s;
    
    cin >> N;
    
    vector<int> seq(N);
    vector<int> ans(N);
    
    for(int i=0; i<N; i++)
    {
        cin >> seq[i];
    }
    
    for(int i=N-1; i >= 0; i--)
    {
        while(!s.empty() && seq[i] >= s.top())
            s.pop();
        
        if(s.empty()) ans[i] = -1;
        else ans[i] = s.top();
        
        s.push(seq[i]);
    }
    
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << ' ';
    
    return 0;
    
}