#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

string N;

void Merge(string& str, int l, int m, int r)
{
    int leftSize = m-l+1;
    int rightSize = r-m;

    string left =  str.substr(l, leftSize);
    string right = str.substr(m+1, rightSize);

    int leftIdx = 0;
    int rightIdx = 0;
    int resIdx = l;

    while(leftIdx < leftSize && rightIdx < rightSize)
    {
        if(left[leftIdx] > right[rightIdx])
        {
            str[resIdx++] = left[leftIdx++];
        }
        else{
            str[resIdx++] = right[rightIdx++];
        }
    }

    while(leftIdx < leftSize)
    {
        str[resIdx++] = left[leftIdx++];
    }

    while(rightIdx < rightSize)
    {
        str[resIdx++] = right[rightIdx++];
    }

}

void MergeSort(string& str, int l, int r)
{
    if(l < r)
    {
        int m = l + (r-l)/2;

        MergeSort(str, l, m);
        MergeSort(str, m+1, r);

        Merge(str, l, m, r);
    }
}

void FindMaxMultipleOf30(string& str)
{
    bool hasZero = false;
    int sum = 0;

    for(const auto& c : str)
    {
        sum += c-'0';
        if(c == '0') hasZero = true;
    }

    if(hasZero && sum%3 == 0)
    {
        cout << str;
    }
    else{
        cout << -1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    // #1. 병합 정렬
    MergeSort(N, 0, N.length()-1);

    // #2. 30의 배수중 최대가 되는 수
    FindMaxMultipleOf30(N);

    return 0;
}