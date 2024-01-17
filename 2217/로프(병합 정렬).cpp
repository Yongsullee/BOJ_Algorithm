// #1. 병합 정렬

#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

int N;
vector<int> weights;

/* [문제] : 최대 중량/개수 = 각 로프에 걸리는 중량, 최대 중량 = 각 로프에 걸리는 최대 중량 * 개수
 * [해결] 
 *        1. 오름차순 정렬
 *        2. 현재 로프가 감당 가능한 최대 중량(현재 로프가 감당 가능한 중량 * 현재 로프 포함 병렬 처리 가능한 로프의 개수)
 *        3. 정렬된 배열을 순서대로 탐색하며, 최대 중량 찾기
*/

void Merge(vector<int>& v, int l, int m, int r)
{
    int leftSize = m - l + 1;
    int rightSize = r - m;
    
    vector<int> leftHalf(leftSize);
    vector<int> rightHalf(rightSize);
    
    for(int i=0; i<leftSize; ++i)
        leftHalf[i] = v[l+i];
    for(int i=0; i<rightSize; ++i)
        rightHalf[i] = v[m+1+i];
    
    int leftIdx = 0;
    int rightIdx = 0;
    int resIdx = l;
    
    while(leftIdx < leftSize && rightIdx < rightSize)
    {
        if(leftHalf[leftIdx] <= rightHalf[rightIdx])
        {
            v[resIdx++] = leftHalf[leftIdx++];
        }
        else
        {
            v[resIdx++] = rightHalf[rightIdx++];
        }
    }
    
    while(leftIdx < leftSize)
        v[resIdx++] = leftHalf[leftIdx++];
    
    while(rightIdx < rightSize)
        v[resIdx++] = rightHalf[rightIdx++];
    
}
    
void MergeSort(vector<int>& v, int l, int r)
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
    
    weights.resize(N);
    
    for(int i=0; i<(int)weights.size(); ++i)
        cin >> weights[i];
    
    // #1. 병합 정렬(오름차순 정렬)
    MergeSort(weights, 0, N-1);
    
    // #2. 최대 중량 = 각 로프에 걸리는 최대 중량 * 병렬 연결된 로프의 개수
    int res = INT_MIN;
    for(int i=0; i<(int)weights.size(); ++i)
    {
        res = max(res, weights[i]*((int)weights.size()-i));
    }
    
    cout << res;
    
    return 0;
}