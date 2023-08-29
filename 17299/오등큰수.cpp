/*

    [문제] : 주어진 숫자의 현재 위치 보다 오른쪽 위치에 있는 수들 중 수열에 등장한 횟수가 더 많은 수를 찾는 문제
  
    [풀이]

    1.  17298 문제와 동일, 수열을 뒤집고 스택의 top과 비교하며, pop 하고 push 할것인지, push만 할것인지 결정하고
        스택을 오름차순으로 정리
    2.  다만, 수열의 숫자 간 비교가 아니라, 수열에서 해당 숫자가 등장한 횟수를 비교해하기 때문에 unordered_map 활용
    3.  일반적으로, unordered_map은 컨테이너의 숫자들의 중복 횟수를 카운트하기 용이함.
    4.  결과적으로, unorderd_map을 활용해 수열의 숫자를 Key 값으로, 숫자가 수열에 등장한 횟수는 Value로 설정.

*/

#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int N;
    
    cin >> N;
    
    vector<int> seq(N);
    vector<int> ans(N);
    unordered_map<int, int> um;
    stack<int> s;
    
    for(int i=0; i<N; i++)
    {
        cin >> seq[i];
        um[seq[i]]++;
    }
    
    for(int i=N-1; i >= 0; i--)
    {
        while(!s.empty() && um[seq[i]] >= um[s.top()])
            s.pop();
        
        if(s.empty()) ans[i] = -1;
        else ans[i] = s.top();
        
        s.push(seq[i]);
    }
    
    for(int i=0; i<N; i++)
        cout << ans[i] << ' ';
    
    return 0;
}