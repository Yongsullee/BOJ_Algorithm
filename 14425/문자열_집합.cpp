#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    int cnt = 0;
    string str;
    map<string, bool> m;
    
    cin >> N >> M;
    
    for(int i=0; i<N; i++)
    {   
        cin >> str;
        m.insert(make_pair(str, true));
    }
    
    for(int i=0; i<M; i++)
    {
        cin >> str;
        
        if(m[str] == true)
            cnt++;
    }
    
    cout << cnt << endl;
}