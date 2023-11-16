#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int N;
    cin >> N;
    
    int cnt = 0;
    while(cnt < N)
    {
        // cnt = 별의 갯수, N-cnt = 공백 갯수
        for(int i=0; i<N; i++)
        {
            if(i < cnt)
                cout << ' ';
            else
                cout << '*';
        }
        cout << '\n';
        cnt++;
    }
    
    return 0;
}