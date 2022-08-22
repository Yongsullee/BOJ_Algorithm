#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int A, B;
    cin >> A >> B;
    
    int C;
    cin >> C;
    
    int plusA, plusB;
    plusA = C / 60;
    plusB = C % 60;

    if(plusA >= 24)
        plusA %= 24;
    
    B += plusB;
    if (B >= 60)
    {
        A++;
        B -= 60;   
    }
    
    A += plusA;
    if (A >= 24)
        A -= 24;
    
    cout << A << " " << B << endl;
    
}