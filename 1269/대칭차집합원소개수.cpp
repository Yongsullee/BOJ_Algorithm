#include <iostream>
#include <set>
#include <algorithm>
typedef long long ll;
using namespace std;

int main()
{
    int N, T;
    set<ll> s;
    
    cin >> N >> T;
    
    int set1Num = N;
    int set2Num = T;
    int res;
    
    ll num;
    for(int i=0; i<N; i++)
    {
        cin >> num;
        
        s.insert(num); 
    }
    
    for(int i=0; i<T; i++)
    {
        cin >> num;
        
        auto it = s.find(num);
        if(it != end(s))
        {
            set1Num--;
            set2Num--;         
        }
    }
    
    cout << set1Num + set2Num << endl;
}