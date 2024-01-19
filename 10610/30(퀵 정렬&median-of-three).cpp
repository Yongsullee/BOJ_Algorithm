#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

string N;

int FindMedian(string& str, int l, int r)
{
    int m = l + (r-l)/2;

    if(str[l] > str[m])
    {
        swap(str[l], str[m]);
    }
    if(str[l] > str[r])
    {
        swap(str[l], str[r]);
    }
    if(str[m] > str[r])
    {
        swap(str[m], str[r]);
    }
    return m;
}

int Partition(string& str, int l, int r)
{
    int pivIdx = FindMedian(str, l, r);
    swap(str[pivIdx], str[r]);

    int piv = str[r];
    int i = l-1;

    for(int j=l; j<r; ++j)
    {
        if(str[j] >= piv)
        {
            i++;
            swap(str[j], str[i]);
        }
    }
    swap(str[i+1], str[r]);
    return i+1;
}

void QuickSort(string& str, int l, int r)
{
    if(l < r)
    {
        int piv = Partition(str, l, r);

        QuickSort(str, l, piv-1);
        QuickSort(str, piv+1, r);
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
    QuickSort(N, 0, N.length()-1);

    // #2. 30의 배수중 최대가 되는 수
    FindMaxMultipleOf30(N);

    return 0;
}