#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    vector<string> v(5); 
    int maxLen = -1;
    
    // #1. 입력 받기
    for(int i=0; i<5; i++)
    {
        string str;
        // #1. getline : 세 번째 인자로 전달받은 delim이 나올때 까지 문자열 입력 받는다.
        getline(cin, str);
        
        // #2. 문자열 최대 길이 찾기
        if((int)str.size() > maxLen)
            maxLen = (int)str.size();
        
        // #3. 벡터에 새로운 문자열 추가
        v[i] = str;
    }
    
    // 2. 세로 문자 만들기
    string ans = "";
    for(int i=0; i<maxLen; i++)
    {
        for(int j=0 ; j<5; j++)
        {
            // #1. 문자열의 길이가 i보다 짧을 경우 패스
            if(v[j].size()-1 < i)
                continue;
            // #2. 새로운 문자 추가
            ans.push_back(v[j][i]);
        }
    }
    
    cout << ans;
    
    return 0;
}