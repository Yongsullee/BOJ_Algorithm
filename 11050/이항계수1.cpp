#include <iostream>
using namespace std;

/*
    문제: 
        이항 계수
    설명:   
        ( N )           N!
        ( K )    =  --------
                    K!(N-K)!
*/

int N, K;

// 재귀문을 활용한 Factorial 구현
int Factorial(int num)
{
    if(num == 0 || num == 1)
        return 1;
    else
        return num * Factorial(num-1);
}

int main()
{
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    cin >> N >> K;
    
    cout << Factorial(N) / (Factorial(K) * Factorial(N-K)) << endl;
}