/*
    설명:
        Binary Search를 사용합니다.
    풀이:
        1. 먼저 숫자 카드를 오름 차순(less) 정렬 합니다.
        2. left = 0, right = N-1, mid = (left + right)/2
        3. 정수를 mid와 비교하고, mid보다 작다면 right = mid-1 로 변경, mid보다 크다면 left = mid+1로 설정
        4. 퀵 정렬하고 비슷하지만, 정확하게는 Pivot을 정하며 잘게 잘게 분할 하는 과정을 통해 마지막에 다다르면 정답을 찾는 풀이입니다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    vector<int> nVector; vector<int> mVector;
    
    cin >> N;
    for(int i=0; i<N; i++)
    {
        int tmp;
        cin >> tmp;
        
        nVector.push_back(tmp);
    }
    
    cin >> M;
    for(int i=0; i<M; i++)
    {
        int tmp2;
        cin >> tmp2;
        
        mVector.push_back(tmp2);
    }
    
    sort(begin(nVector), end(nVector));
    
    for(int i=0; i<M; i++)
    {
        int right = N-1;
        int left = 0;
        bool check = false;
        while(left <= right)
        {
            int mid = (left + right)/2;
            if (mVector[i] == nVector[mid])
                check = true;
            if (mVector[i] < nVector[mid])
                right = mid-1;
            else
                left = mid+1;
        }
        
        if(check == true)
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }
}