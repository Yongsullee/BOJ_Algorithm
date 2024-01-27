#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, x;
vector<int> v;

int MedianOfThree(vector<int>& arr, int l, int r)
{
    int m = l + (r-l)/2;
    
    if(arr[l] > arr[m])
        swap(arr[l], arr[m]);

    if(arr[l] > arr[r])
        swap(arr[l], arr[r]);

    if(arr[m] > arr[r])
        swap(arr[m], arr[r]);

    return m;
}

int Partition(vector<int>& arr, int l, int r)
{
    int pivIdx = MedianOfThree(arr, l, r);
    swap(arr[pivIdx], arr[r]);

    int piv = arr[r];
    int i = l-1;

    for(int j=l; j<r; ++j)
    {
        if(arr[j] <= piv)
        {
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[r]);

    return i+1;
}

void QuickSort(vector<int>& arr, int l, int r)
{
    if(l < r)
    {
        int piv = Partition(arr, l, r);

        QuickSort(arr, l, piv-1);
        QuickSort(arr, piv+1, r);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    v.resize(n);

    for(int i=0; i<n; ++i)
    {
        cin >> v[i];
    }

    cin >> x;

    // #1. 퀵 정렬
    QuickSort(v, 0, n-1);

    // #2. 투 포인터
    int left = 0;
    int right = n-1;
    int ans = 0;

    while(left <= right)
    {
        // #1. x와 같을 경우
        if(v[left] + v[right] == x)
        {
            ans++;
            left++;
            right--;
        }
        // #2. x보다 작을 경우, left(시작점)을 오른쪽으로 1칸 이동
        else if(v[left] + v[right] < x)
        {
            left++;
        }
        // #3. x보다 클 경우, right(끝)을 왼쪽으로 1칸 이동
        else{
            right--;
        }
    }

    cout << ans;

    return 0;
}