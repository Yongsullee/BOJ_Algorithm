/*
*   std::getline 함수 :  getline은 문자열을 입력 받는 함수 중 하나입니다. getline 함수는 특정 delimiter 문자를 기준으로 문자열을 분리합니다.
                        이때, delimiter를 작성하지 않을 경우, 기본적으로 "\n(개행자)"가 나타날 때까지 문자열을 읽어서 문자열을 저장합니다.
*/

#include <iostream>
#include <string>
using namespace std;

string str;

int main()
{
    while(true)
    {
        getline(cin, str);
        if(str.empty())
            break;
        cout << str << endl;
    }
    
    return 0;
}