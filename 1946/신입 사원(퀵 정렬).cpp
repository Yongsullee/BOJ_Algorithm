// #1. 병합 정렬

#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef pair<int, int> p;

int T, N;

int MedianOfThree(vector<p> &arr, int l, int r)
{
    int m = l + (r - l) / 2;

    if (arr[l].first > arr[m].first)
        swap(arr[l], arr[m]);

    if (arr[l].first > arr[r].first)
        swap(arr[l], arr[r]);

    if (arr[m].first > arr[r].first)
        swap(arr[m], arr[r]);

    return m;
}

int Partition(vector<p> &arr, int l, int r)
{
    int pivIdx = MedianOfThree(arr, l, r);
    swap(arr[pivIdx], arr[r]);

    int piv = arr[r].first;
    int i = l - 1;

    for (int j = l; j < r; ++j)
    {
        if (arr[j].first <= piv)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[r]);

    return i + 1;
}

void QuickSort(vector<p> &arr, int l, int r)
{
    if (l < r)
    {
        int piv = Partition(arr, l, r);

        QuickSort(arr, l, piv - 1);
        QuickSort(arr, piv + 1, r);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> N;

        vector<p> scores(N);

        for (int i = 0; i < N; ++i)
        {
            int paperScore, interviewScore;
            cin >> paperScore >> interviewScore;

            scores[i].first = paperScore;
            scores[i].second = interviewScore;
        }
        // 서류 점수 기준 오름차순 정렬
        QuickSort(scores, 0, N - 1);

        int res = 1;
        int maxInterviewScore = scores[0].second;
        for (int i = 1; i < N; ++i)
        {
            if (scores[i].second < maxInterviewScore)
            {
                res++;
                maxInterviewScore = scores[i].second;
            }
        }

        cout << res << '\n';
    }

    return 0;
}