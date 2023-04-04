#include <iostream>
using namespace std;

int res, tmp;
int row, col;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    row = col = 1;
    for(int i=1; i<=9; i++)
    {
        for(int j=1; j<=9; j++)
        {
            cin >> tmp;
            if(res < tmp)
            {
                row = i;
                col = j;
                res = tmp;
            }
        }
    }
    
    cout << res << '\n';
    cout << row << " " << col;
    
    return 0;
}