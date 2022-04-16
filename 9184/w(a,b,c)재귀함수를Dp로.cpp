#include <iostream>
using namespace std;

int a, b, c;
int wArr[51][51][51] = {
    0,
};

int w(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (wArr[a][b][c] != 0)
        return wArr[a][b][c];
    else if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);
    else if (a < b && b < c)
        return wArr[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    else
        return wArr[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}
int main()
{
    while (1)
    {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
    }
    return 0;
}