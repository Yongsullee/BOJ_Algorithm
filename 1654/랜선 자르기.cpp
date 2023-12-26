#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int K, N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> K >> N;
   
    vector<long long> rans(K);
    
    for(int i=0; i<K; ++i)
    {
        cin >> rans[i];
    }
    
    // #1. 오름차순 정렬
    sort(begin(rans), end(rans));
    
    // #2. 왼쪽 경계와 오른쪽 경계
    // 왼쪽 경계 : 자른 길이가 최소가 되는 값, 1
    long long left = 1;
    // 오른쪽 경계 : 자른 길이가 최대가 되는 값, rans의 마지막 항목
    long long right = rans.back();
    // 자른 길이가 최대가 되어야 같은 길이의 나무가 N개 이상이면서 N과 가장 가까운 값을 가지게 됩니다.
    long long maxLength = 1;
    while(left <= right)
    {
        long long mid = (left+right)/2;
        int cnt = 0;
        // #1. 중간 길이로 각 나무를 자르면, 몇개의 나무가 생성되는지 셉니다.
        for(int i=0; i<(int)rans.size(); ++i)
            cnt += rans[i]/mid;
        
        // #2. cnt가 N개 이상일 경우, 최대 자른 길이 값 갱신, left 경계 mid+1로 이동
        //     자른 길이가 최대가 될수록, N개와 가까워지기 때문입니다. 
        if(cnt >= N)
        {
            maxLength = max(maxLength, mid);
            left = mid+1;
        }
        // #2. cnt가 N개 미만일 경우, right 경계 mid-1로 이동
        //     오른쪽 경계를 mid-1위치로 변경함으로써, 자른 길이 값을 증가시키고, 'N개'의 나무 개수로 근접합니다.
        else
        {
            right = mid-1;
        }
    }
    
    cout << maxLength;
    
    return 0;
    
}