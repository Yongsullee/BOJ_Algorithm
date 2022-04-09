#include <iostream>
using namespace std;
/*
    문제:
        1과 0의 빈도수를 구하는 문제
    풀이:
        1과 0의 빈도수는 규칙이 존재합니다.

        0 : 1 0 1 1 2 3 ...
        1 : 0 1 1 2 3 5 ...

        위 규칙은 기존의 피보나치 수열과 동일하며,
        이를 이용하여 동적계획법을 구현할 수 있습니다.
*/
long long arr[50] = {
    0,
    1,
};

long long fib(int N)
{
    if (N == 0 || N == 1)
        return arr[N];
    else if (arr[N] == 0)
    {
        arr[N] = fib(N - 1) + fib(N - 2);
    }
    return arr[N];
}

int main()
{
    int T;
    int tmp;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> tmp;
        if (tmp == 0)
        {
            cout << "1 0" << '\n';
        }
        else
        {
            cout << fib(tmp - 1) << ' ' << fib(tmp) << '\n';
        }
    }
}