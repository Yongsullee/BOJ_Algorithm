#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int N;
    cin >> N;
    
    // pair< 인덱스, 회전 수 > 형식을 담은 덱 선언
    deque<pair<int,int>> dq;
    
    for(int i=1; i<=N; i++)
    {
        int tmp;
        cin >> tmp;
        
        dq.push_back({i, tmp});
    }
    
    while(!dq.empty())
    {
        // #1. 덱 가장 앞에 위치한 항목 출력 및 제거
        pair<int,int> cur = dq.front();
        cout << cur.first << '\n';
        
        dq.pop_front();
        
        // #2. 양수 일 경우, 오른쪽 회전
        if(cur.second > 0)
        {
            cur.second--;
            // cur.second = 양수 회전수, 즉 회전수가 1이 될 때까지 앞에 있는 항목을 덱의 마지막 위치로 재배치
            while(cur.second > 0)
            {
                dq.push_back(dq.front());
                dq.pop_front();
                cur.second--;
            }
        }
        // #3. 음수 일 경우, 왼쪽 회전
        else
        {
            // cur.second = 음수 회전수, 즉 회전수가 -1이 될 때까지 뒤에 있는 항목을 덱의 첫번째 위치로 재배치
            while(cur.second < 0)
            {
                dq.push_front(dq.back());
                dq.pop_back();
                cur.second++;
            }
        }
    }
    
    
}