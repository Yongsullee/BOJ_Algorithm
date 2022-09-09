#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    set<string> s;
    vector<string> v;
    
    cin >> N >> M;
    
    string str;
    for(int i=0; i<N+M; i++)
    {
        cin >> str;
        
        auto it = s.find(str);
        if(it == end(s))
        {
            s.insert(str);
        }
        else
        {
            v.push_back(str);
        }
    }
    sort(begin(v), end(v));
    
    cout << v.size() << '\n';
    
    for(string val : v)
        cout << val << '\n';
}