/*
    목적:
        Set 컨테이너를 활용해 문자열을 사전순 역순으로 출력하기
    설명:
        1. 단순히 rbegin 과 rend를 통해 Set을 순회하는 방법
        2. set<string, greater<string>> 으로 정의하는 방법
*/

#include <iostream>
#include <set>
using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    cin >> N;
    
    set<string, greater<string>> s;
    
    while(N--)
    {
        string name;
        string entrance;
        
        cin >> name >> entrance;
        
        if(entrance == "enter")
        {
            s.insert(name);
        }
        else
        {
            s.erase(name);
        }
    }
    
    for(const auto& name : s)
        cout << name << '\n';
    
}