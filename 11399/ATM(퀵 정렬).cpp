// #2. 퀵 정렬

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
vector<int> v;

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

    cin >> N;
    
    v.resize(N);
    
    for(int i=0; i<N; ++i)
        cin >> v[i];
    
    // #1. 퀵 소트 수행
    QuickSort(v, 0, N-1);
    
    // #2. 결과 출력
    int res = v[0];
    for(int i=1; i<N; ++i)
    {
        v[i] = v[i-1] + v[i];
        res += v[i];
    }
    
    cout << res;
    
    return 0;
}