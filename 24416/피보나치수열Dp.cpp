#include <iostream>
using namespace std;

long long f[41];

int main()
{
    f[1] = f[2] = 1;
    for (int i = 3; i < 41; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }

    int N;
    cin >> N;

    cout << f[N] << " " << N - 2 << endl;
}