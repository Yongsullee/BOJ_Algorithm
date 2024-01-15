// #1. 병합 정렬

#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> p;

int N;
vector<p> v;

void Merge(vector<p>& v, int l, int m, int r)
{
    int leftSize = m-l+1;
    int rightSize = r-m;
    
    vector<p> leftHalf(leftSize);
    vector<p> rightHalf(rightSize);
    
    for(int i=0; i<leftSize; ++i)
        leftHalf[i] = v[l+i];
    
    for(int i=0; i<rightSize; ++i)
        rightHalf[i] = v[m+1+i];
    
    int leftIdx = 0;
    int rightIdx = 0;
    int resIdx = l;
    
    while(leftIdx < leftSize && rightIdx < rightSize)
    {
        // 끝나는 시간 비교
        if(leftHalf[leftIdx].second < rightHalf[rightIdx].second)
        {
            v[resIdx++] = leftHalf[leftIdx++];
        }
        else if(leftHalf[leftIdx].second > rightHalf[rightIdx].second)
        {
            v[resIdx++] = rightHalf[rightIdx++];
        }
        else // 끝나는 시간이 같을 경우 시작 시간이 빠른 회의를 먼저 선택
        {
            if(leftHalf[leftIdx].first <= rightHalf[rightIdx].first)
            {
                v[resIdx++] = leftHalf[leftIdx++];
            }
            else
            {
                v[resIdx++] = rightHalf[rightIdx++];
            }
        }
    }

    
    while(leftIdx < leftSize)
    {
        v[resIdx++] = leftHalf[leftIdx++];
    }
    
    while(rightIdx < rightSize)
    {
        v[resIdx++] = rightHalf[rightIdx++];
    }
    
}

void MergeSort(vector<p>& v, int l, int r)
{
    if(l < r)
    {
        int m = l + (r-l)/2;
        
        MergeSort(v, l, m);
        MergeSort(v, m+1, r);
        
        Merge(v, l, m, r);
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
    MergeSort(v, 0, N-1);
    
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
