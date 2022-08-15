#include <iostream>
using namespace std;

int main()
{
    int N, M;
    while(true)
    {   
        cin >> N >> M;
        
        if(N == 0 && M == 0)
            break;
        else
        {
            if(N > M && (N % M) == 0)
                cout << "multiple" << '\n';
            if(N < M && (M % N) == 0)
                cout << "factor" << '\n';
            if((N % M) != 0 && (M % N) != 0)
                cout << "neither" << '\n';
        }
    }
}