/*
    주의할 점: 2자리 이상 숫자를 저장하기 위해서 isdigit()과 string 활용
*/

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int T,N;
    
    cin >> T;
    
    while(T--)
    {
        string orders, numStr;
        bool reverse = false, error = false;
        deque<int> dq;
        
        cin >> orders;
        cin >> N;
        cin >> numStr;
        
        string num = "";
        for(int i=0; i<numStr.length(); i++)
        {
            if(isdigit(numStr[i]))
            {
                num += numStr[i];
            }
            else if(numStr[i] == ',' || numStr[i] == ']')
            {
                if(!num.empty())
                {
                    dq.push_back(stoi(num));
                    num.clear();
                }
            }
        }
        
        for(const auto& order : orders)
        {
            if(order == 'R')
            {
                reverse = !reverse;
            }
            else
            {
                if(dq.empty())
                {
                    error = true;
                    break;
                }
                else
                {
                    reverse ? dq.pop_back() : dq.pop_front();
                }
            }
        }
        if(!error)
        {
            cout << '[';
            if(!dq.empty())
            {
                if(reverse)
                {
                    for(auto it=dq.rbegin(); it!=dq.rend(); ++it)
                    {
                        cout << *it;
                        if(it != dq.rend()-1)
                            cout << ',';
                    }
                }
                else
                {
                    for(auto it=dq.begin(); it!=dq.end(); ++it)
                    {
                        cout << *it;
                        if(it != dq.end()-1)
                            cout << ',';
                    }
                }
            }
            cout << ']' << '\n';
        }
        else
        {
            cout << "error\n";
        }
    }
    
}