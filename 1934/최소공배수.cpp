#include <iostream>
using namespace std;

int T, A, B;

// 유클리드 호제법 : 최대 공약수 구하는 공식
int gcd(int a, int b)
{
    int c = a % b;
    while(c != 0)
    {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

int main()
{
    cin >> T;
    
    for(int i=0; i<T; i++)
    {
        cin >> A >> B;
        cout << (A*B) / gcd(A,B) << '\n';
    }
}