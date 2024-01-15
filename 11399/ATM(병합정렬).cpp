// #1. 병합 정렬

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
vector<int> v;

void Merge(vector<int>& arr, int left, int mid, int right)
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    
    vector<int> leftHalf(leftSize);
    vector<int> rightHalf(rightSize);
    
    for(int i=0; i<leftSize; ++i)
        leftHalf[i] = arr[left+i];
    
    for(int i=0; i<rightSize; ++i)
        rightHalf[i] = arr[mid+1+i];
    
    int leftIdx = 0;
    int rightIdx = 0;
    int resIdx = left;
    
    while(leftIdx < leftSize && rightIdx < rightSize)
    {
        if(leftHalf[leftIdx] <= rightHalf[rightIdx])
            arr[resIdx++] = leftHalf[leftIdx++];
        else
            arr[resIdx++] = rightHalf[rightIdx++];
    }
    
    while(leftIdx < leftSize)
    {
        arr[resIdx++] = leftHalf[leftIdx++];
    }
    
    while(rightIdx < rightSize)
    {
        arr[resIdx++] = rightHalf[rightIdx++];
    }
    
}

void MergeSort(vector<int>& arr, int left, int right)
{
    if(left < right)
    {
        int mid = left + (right-left)/2;
        
        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);
        
        Merge(arr, left, mid, right);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    
    while(N--)
    {
        int tmp;
        cin >> tmp;
        
        v.push_back(tmp);
    }
    
    // 병합 정렬
    MergeSort(v, 0, v.size()-1);
    
    // 누적 합 계산 및 결과 출력
    long long res = 0;
    for(int i=0; i<v.size(); ++i)
    {
        if(i != 0)
            v[i] += v[i-1];
        res += v[i];
    }
    
    cout << res;
    
    return 0;
}
