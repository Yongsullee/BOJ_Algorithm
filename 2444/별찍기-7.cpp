#include <iostream>
using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    cin >> N;
    
    for(int i=0; i<N-1; i++)
    {
        for(int j=0; j<N-1-i; j++)
        {
            cout << " ";
        }
        for(int k=0; k<2*i+1; k++)
        {
            cout << "*";
        }
        cout << '\n';
    }
    for(int i=N; i>0; i--)
    {
        for(int j=N; j>i; j--)
        {
            cout << " ";
        }
        for(int k=0; k < 2*i-1; k++)
        {
            cout << "*";
        }
        cout << '\n';
    }
    
}