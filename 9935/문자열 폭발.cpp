#include <iostream>
#include <string>
using namespace std;

string str, bomb;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    cin >> str;
    cin >> bomb;
    
    string res;
    for(int i=0; i<str.size(); i++)
    {
        res.push_back(str[i]);
        
        if(res.size() >= bomb.size())
        {
            int idx = (int)res.size()-1;
            bool flag = true;
            for(int j=(int)bomb.size()-1; j>=0; j--)
            {
                if(res[idx] != bomb[j])
                {
                    flag = false;
                    break;
                }
                idx--;
            }
            
            if(flag)
            {
                res.erase(res.end()-bomb.size(), res.end());
            }
        }
    }

    if(res.empty())
        cout << "FRULA";
    else
        cout << res;
    
    return 0;
    
}