#include <iostream>
using namespace std;

int N;
int det;

// 유클리드 호제법 : 최대 공약수 구하기
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
    cin >> N;
    
    int tmp;
    int gcdVal;
    for(int i=0; i<N; i++)
    {
        if(i==0)
        {
            cin >> det;
            continue;
        }
        else
        {
            cin >> tmp;
            gcdVal = gcd(det, tmp);
            cout << det/gcdVal << "/" << tmp/gcdVal << '\n';
        }
    }
}