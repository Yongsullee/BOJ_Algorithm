#include <iostream>
using namespace std;

/*
    풀이:
        규칙을 찾고, DP를 이용합니다.

        1.  P(N) = P(N-2) + P(N-3)
        2.  이때, 데이터 크기를 주의해야합니다.
            특히, 피보나치 수열의 경우 값이 급진적으로 증가하므로, 자료형에 주의해야합니다.
*/
long long answer[101] = {
    0,
    1,
    1,
};

long long Padovan(int num)
{
    if (num < 3)
        return answer[num];
    else if (answer[num] == 0)
        answer[num] = Padovan(num - 2) + Padovan(num - 3);
    return answer[num];
}

int main()
{
    int T, N;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        cout << Padovan(N) << '\n';
    }
}