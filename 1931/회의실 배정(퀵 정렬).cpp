// #1. 병합 정렬

#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> p;

int N;
vector<p> v;

int Partition(vector<p>& arr, int l, int r)
{
    p piv = arr[(l + r) / 2]; // 피봇을 중간 값으로 설정
    int i = l;
    int j = r;
    
    while (i <= j) {
        while (arr[i].second < piv.second || 
              (arr[i].second == piv.second && arr[i].first < piv.first)) i++;
        while (arr[j].second > piv.second ||
              (arr[j].second == piv.second && arr[j].first > piv.first)) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return i;
}

void QuickSort(vector<p>& arr, int l, int r)
{
    if(l < r)
    {
        int piv = Partition(arr, l, r);
        
        if (l < piv - 1)
            QuickSort(arr, l, piv - 1);
        if (r > piv)
            QuickSort(arr, piv, r);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    
    for(int i=0; i<N; ++i)
    {
        int start, end;
        cin >> start >> end;
        
        v.push_back({start, end});
    }
    
    // 병합 정렬, 종료 시간 기준 오름차순 정렬
    QuickSort(v, 0, N-1);
    
    // 중복 구간 체크 및 회의의 최대 개수
    ll end = v[0].second;
    int res = 1;
    for(int i=1; i<v.size(); ++i)
    {
        if(v[i].first >= end)
        {
            end = v[i].second;
            res++;   
        }
    }
    
    cout << res;
    
    return 0;
}
