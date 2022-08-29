#include <iostream>
using namespace std;

/*
    std::precision(N)   : 실수 전체의 자리수를 n개로 제한합니다. 이상의 자릿수는 반올림됩니다.
    cout << fixed;      : precision(n)을 통해 설정한 자릿수 n개를 소수점 아래의 자릿수로 변경됩니다.
*/

int main()
{
    double A, B;
    
    cin >> A >> B;
    
    cout.precision(12);
    cout << fixed;
    
    cout << A / B;
}