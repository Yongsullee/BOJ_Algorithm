/*
    설명: While 문 안에 for문 사용 및 STL의 queue 컨테이너 활용
*/

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int N,K;
    queue<int> q;
    cin >> N >> K;
    
    for(int i=1; i<=N; i++)
    {
        q.push(i);
    }
    
    int cnt = 1;
    cout << "<";
    while(!q.empty())
    {
        for(int i=1; i<K; i++)
        {
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        if(q.size() != 1)
            cout << ", ";
        q.pop();
    }
    cout << ">";
}