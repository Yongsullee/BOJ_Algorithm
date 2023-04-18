#include <iostream>
using namespace std;

int T, C;
int arr[4] = { 25, 10, 5, 1 };

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> T;
    while(T--)
    {
        cin >> C;
        for(int i=0; i<4; i++)
        {
            cout << C/arr[i] << " ";
            C %= arr[i];
        }
        cout << '\n';
    }
}