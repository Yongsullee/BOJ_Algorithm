#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

// first = 절대 값, second = 원본 값
struct Comp
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b)
    {
        // 절대 값이 같다면, 원본 값이 더 작은 수가 높은 우선순위
        if(a.first == b.first)
            return a.second > b.second;
        // 절대 값이 더 낮은 수가 높은 우선순위
        else
            return a.first > b.first;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int N;
    priority_queue<pair<int,int>, vector<pair<int,int>>, Comp> pq;
    
    cin >> N;
    
    while(N--)
    {
        int tmp;
        cin >> tmp;
        
        // #1. 절대 값이 가장 작은 값, 절대 값이 같은 값이 여러개일 경우 원래 값이 음수인 숫자 출력 후 제거
        if(tmp == 0)
        {
            if(!pq.empty())
            {
                cout << pq.top().second << '\n';
                pq.pop();
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        // #2. 숫자 입력, pair<절대 값, 원본 값>
        else
        {
            pq.push(make_pair(abs(tmp), tmp));
        }
    }
    
    return 0;
}