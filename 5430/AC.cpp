#include <iostream>
#include <deque>
using namespace std;

int T;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    cin >> T;
    
    while(T--)
    {
        // funStr : 수행할 함수를 담고 있는 문자열
        // numStr : 배열을 담고 있는 문자열
        string funStr, numStr;
        int n;
        deque<int> dq;
        
        cin >> funStr;
        cin >> n;
        cin >> numStr;
        
        string resStr = "";
        // #1. [x1, x2, ...] 배열을 순서대로 덱에 삽입 하는 작업
        for(int i=0; i<numStr.size(); i++)
        {
            // #1. numStr에서 숫자를 만날 경우
            if(isdigit(numStr[i]))
            {
                resStr += numStr[i];
            }
            // #2. numStr에서 ']' 혹은 ','를 만날 경우
            else if(numStr[i] == ']' ||
                   numStr[i] == ',')
            {
                if(!resStr.empty())
                {
                    dq.push_back(stoi(resStr));
                    resStr.clear(); 
                }
            }
        }
        
        // 덱의 역순 여부
        bool reverse = false;
        // 덱의 에러 발생 여부(비어 있는 덱에서 D연산 수행할 경우)
        bool error = false; 
        // #2. funStr을 순서대로 순회하며 'R' 혹은 'D'에 해당되는 작업 수행
        for(const auto& func : funStr)
        {
            // #1. 'R' : 덱의 순서 뒤집기
            if(func == 'R')
            {
                reverse = !reverse;
            }
            // #2. 'D' : 덱의 첫 번째 원소 제거
            else if(func == 'D')
            {
                // #1. 비어있지 않을 경우
                if(!dq.empty())
                {
                    //역순이면 마지막 원소 제거, 원순 이면 첫 번째 원소 제거
                    reverse ? dq.pop_back() : dq.pop_front();
                }
                // #2. 비어있을 경우
                else
                {
                    error = true;
                    break;
                }
            }
        }
        // #3. 만약, 에러가 발생했다면?
        if(error)
        {
            cout << "error" << '\n';
        }
        // #4. 만약, 에러가 발생하지 않았다면?
        else
        {
            cout << '[';
            if(!dq.empty())
            {
                // #1. 역순으로 출력, rbegin과 rend 활용
                if(reverse)
                {
                    for(auto it = rbegin(dq); it != rend(dq); ++it)
                    {
                        cout << *(it);
                        if(it != rend(dq)-1)
                            cout << ',';
                    }
                }
                // #2. 원래 순서로 출력, begin과 end 활용
                else
                {
                    for(auto it  = begin(dq); it != end(dq); ++it)
                    {
                        cout << *(it);
                        if(it != end(dq)-1)
                            cout << ',';
                    }
                }
            }
            cout << ']' << '\n';
        }
    }
}