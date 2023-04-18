/*
    1번 코드는 아마도 <cmath>가 제공하는 pow 함수의 인자가 double 타입이기 때문에
    오차가 발생하는 듯 합니다.
    2번 코드는 사용자 정의 pow 함수를 정의해 int 타입으로 인자를 전달 받아 제곱 연산을
    수행합니다.
*/

// 1번 오류 코드
#include <iostream>
#include <cmath>
using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> N;
    
    cout << pow(pow(2, N)+1, 2) << endl;
}


// 2번 정답 코드
#include <iostream>
using namespace std;

int pow(int x, int n);

int N;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> N;
    
    cout << pow(pow(2, N)+1, 2) << endl;
}

int pow(int x, int n)
{
    int result =1;
    while(n)
    {
        result *= x;
        n--;
    }
    return result;
}