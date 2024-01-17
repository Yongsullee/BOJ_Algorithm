#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> v(3);

int Partition(vector<int>& v, int l, int r)
{
    int piv = v[r];
    int i = l-1;
    
    for(int j=l; j<r; ++j)
    {
        if(v[j] <= piv)
        {
            i++;
            swap(v[j], v[i]);   
        }
    }
    
    swap(v[i+1], v[r]);
    
    return i+1;
}

void QuickSort(vector<int>& v, int l, int r)
{
    if(l < r)
    {
        int piv = Partition(v, l, r);
        
        QuickSort(v, l, piv-1);
        QuickSort(v, piv+1, r);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    for(int i=0; i<3; ++i)
        cin >> v[i];
    
    QuickSort(v, 0, 2);
    
    for(int i=0; i<3; ++i)
        cout << v[i] << ' ';
    
    return 0;
}