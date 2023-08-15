#include <iostream>
#include <deque>
using namespace std;

bool arr[100001];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int N;
    deque<int> dq;
    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> arr[i];
    }
    for(int i=0; i<N; i++)
    {
        int tmp;
        cin >> tmp;
        if(arr[i]) continue;
        dq.push_back(tmp);
    }
    
    int M;
    cin >> M;
    while(M--)
    {
        int tmp;
        cin >> tmp;
        dq.push_front(tmp);
        cout << dq.back() << ' ';
        dq.pop_back();
    }
    
    return 0;
}