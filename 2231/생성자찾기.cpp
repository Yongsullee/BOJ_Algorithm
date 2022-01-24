#include <iostream>
using namespace std;

/*
    입력 받은 자연수의 값이 최대 1000,000이므로
    총 7자리 숫자를 구한다.
*/
int generator(int a)
{
    int no_1 = a / 1000000;
    int no_2 = (a % 1000000) / 100000;
    int no_3 = ((a % 1000000) % 100000) / 10000;
    int no_4 = (((a % 1000000) % 100000) % 10000) / 1000;
    int no_5 = ((((a % 1000000) % 100000) % 10000) % 1000) / 100;
    int no_6 = (((((a % 1000000) % 100000) % 10000) % 1000) % 100) / 10;
    int no_7 = ((((((a % 1000000) % 100000) % 10000) % 1000) % 100) % 10);

    int res = a + no_1 + no_2 + no_3 + no_4 + no_5 + no_6 + no_7;

    return res;
}

int main()
{
    int N;
    cin >> N;

    bool present = false;
    for (int i = 0; i < N; i++)
    {
        if (N == generator(i))
        {
            cout << i << endl;
            present = true;
            break;
        }
    }
    if (!present)
        cout << 0 << endl;
}