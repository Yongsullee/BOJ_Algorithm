/*
    #include <algorithm> 헤더의 rotate 함수 활용
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int i, j, k;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    cin >> N >> M;
    
    for(int i=1; i<=N; i++)
    {
        v.push_back(i);
    }
    
    while(M--)
    {
        cin >> i >> j >> k;
        
        rotate(v.begin()+(i-1), v.begin()+(k-1), v.begin()+j);
    }
    
    for(auto val : v)
    {
        cout << val << " ";
    }
    
    return 0;
}