#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    while(true)
    {
        string str;
        getline(cin, str);
        
        if(str == ".")
            break;
        
        stack<char> s;
        bool flag = false;
        for(int i=0; i<str.size(); i++)
        {
            if(str[i] == '.')
                break;
            
            if(str[i] == '(' || str[i] == '[')
            {
                s.push(str[i]);
            }
            else if(str[i] == ')')
            {
                if(!s.empty() && s.top() == '(')
                {
                      s.pop();
                }
                else
                {                    
                    flag = true;
                    break;
                }
            }
            else if(str[i] == ']')
            {
                if(!s.empty() && s.top() == '[')
                {
                    s.pop();}
                else
                {
                    flag = true;
                    break;
                }
            }
        }
        
        if(s.empty() && !flag)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}