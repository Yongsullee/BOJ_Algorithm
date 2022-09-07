#include <iostream>
#include <string>
#include <set>
using namespace std;

// Set 사용

int main()
{   
    string str;
    set<string> s;
    
    cin >> str;

    string tmp;
    for(int i=0; i<str.size(); i++)
    {
        for(int j=i; j<str.size(); j++)
        {
            tmp += str[j];
            s.insert(tmp);
        }
        tmp.clear();
    }
    
    cout << (int)s.size() << endl;
}