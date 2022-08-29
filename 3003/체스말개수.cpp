#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N;
    vector<int> v1 = {1, 1, 2, 2, 2, 8};
    vector<int> v2;
    
    for(int i=0; i<6; i++)
    {
        cin >> N;
        
        v2.push_back(N);
    }
   
    for(int i=0; i<v2.size(); i++)
    {
        cout << v1[i] - v2[i] << " ";
    }
}