#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;

bool comp (string a, string b)
{
    /*  문자열 길이가 같다면, 사전 순서대로 정렬 string 간의 기본 정렬은
        사전 순이므로 return a<b 합니다.
    */
    if(a.length() == b.length()) return a<b;
    return a.length() < b.length();
}

int main ()
{
    int N;
    cin >> N;
    
    string str;
    vector<string> v;

    for(int i=0; i<N; i++)
    {
        cin >> str;
        v.push_back(str);
    }
    
    sort(v.begin(), v.end(), comp);

    cout << v[0] << '\n';
    for(int i=1 ;i<N; i++)
    {
        if(v[i-1] == v[i])
            continue;
        cout << v[i] << '\n';
    }
}