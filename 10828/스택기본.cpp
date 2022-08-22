#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;
    
    string command;
    stack<int> s;
    for (int i=0; i<N; i++)
    {
        string command;
        cin >> command;
        
        int size = (int)command.size();
        
        if(command == "pop")
        {
            if(s.empty() == true)
            {
                cout << -1 << '\n';
            }else
            {
                cout << s.top() << '\n';
                s.pop();
            }
        }
        else if(command == "top")
        {
            if(s.empty() == true)
            {
                cout << -1 << '\n';
            }else
            {
                cout << s.top() << '\n';
            }
        }
        else if(command == "push")
        {
            int num;
            cin >> num;
            s.push(num);
        }
        else if(command == "size")
        {
            cout << s.size() << '\n';
        }
        else if(command == "empty")
        {
            if(s.empty() == true)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
    }
}