#include <iostream>
using namespace std;

/*
    1번, 2번, 3번 축을 이용하여 n개의 원반을 옮긴다.
    이때, n-1 개의 원반을 1번에서 2번으로 옮기고, 3번을 중간 과정에서 사용한다.
    n번째 원반을 3번으로 옮기고,
    다시 n-1 개의 원반을 2번에서 3번으로 옮기고, 1번을 중간 과정에서 사용한다.
    따라서, hanoi(int N-1, start, via, to), hanoi(int N-1, via, to, start)가 재귀적 호출
    
*/
void hanoi(int n, int start, int to, int via)
{
    if (n == 1)
    {
        printf("%d %d\n", start, to);
    }
    else
    {
        hanoi(n - 1, start, via, to);
        printf("%d %d\n", start, to);
        hanoi(n - 1, via, to, start);
    }
}

int main()
{
    int N;
    cin >> N;
    cout << (1 << N) - 1 << "\n";
    hanoi(N, 1, 3, 2);
}