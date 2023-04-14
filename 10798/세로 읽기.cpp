#include <iostream>
#include <string>
using namespace std;

string arr[5];
string ans = "";

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int maxLen = 0;
    for(int i=0; i<5; i++)
    {
        string str;
        getline(cin, str);
        if(maxLen < str.size()) maxLen = str.size();
        arr[i] = str;
    }
    
    for(int i=0; i<maxLen; i++)
    {
        for(int j=0 ; j<5; j++)
        {
            if(!arr[j][i]) continue;
            ans.push_back(arr[j][i]);
        }
    }
  
    cout << ans << endl;
}