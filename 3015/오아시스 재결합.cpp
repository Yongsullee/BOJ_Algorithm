/*
*   [문제] : 줄에서 서로 발견할 수 있는 쌍의 개수

    [풀이]

    1.      배열을 차례대로 순회하며, stack에 push합니다.
    2-1.    stack을 while 문을 통해 순회하며, 현재 위치의 값과 s.top 값을 비교합니다.
    2-2.    현재 위치의 값이 s.top()과 같거나 크다면, pop을 수행합니다.
            이때, 주의할 점은 연속되어 같은 값이 나올 경우 [2, 2, 2], 첫 번재 2와 세 번째 2는
            서로를 볼 수가 없습니다! 따라서, stack에 사람의 키만 저장하지 않고,
            stack에 연속되어 나오는 횟수를 함께 저장하기 위해 stack <pair<int,int>> 형식으로 stack을 선언합니다.
    2-3.    현재 위치의 값과 s.top()이 같을 경우, 현재 위치의 높이 와 연속되는 갯수를 저장하는 pair의 second 에
            s.top().second를 더해주고, pop을 수행합니다.
    3.    while 문을 나와 스택이 비어있지 않다면 answer + 1을 해주고, 현재 위치의 값을 stack에 push합니다.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{

	int N;
	long long ans = 0;

    cin >> N;
    
	vector<long long> v(N);
	stack<pair<int, int>> s;
    
    for(int i=0; i<N; i++)
    {
        cin >> v[i];
    }

    for(int i=0; i<N; i++)
    {
        pair<int, int> p = make_pair(v[i], 1);
        while(!s.empty())
        {
            if(p.first >= s.top().first)
            {
                ans += (long long)s.top().second;
                if(p.first == s.top().first)
                    p.second += s.top().second;
                s.pop();
            }
            else
            {
                break;
            }
        }
        
        if(!s.empty()) ans++;
        
        s.push(p);
    }

	cout << ans << '\n';

	return 0;

}