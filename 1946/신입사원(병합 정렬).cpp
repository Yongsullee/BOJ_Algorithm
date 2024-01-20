// #1. 병합 정렬

#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef pair<int, int> p;

int T, N;

void Merge(vector<p> &arr, int l, int m, int r)
{
    int leftSize = m - l + 1;
    int rightSize = r - m;

    vector<p> left(leftSize);
    vector<p> right(rightSize);

    for (int i = 0; i < leftSize; ++i)
    {
        left[i] = arr[l + i];
    }

    for (int i = 0; i < rightSize; ++i)
    {
        right[i] = arr[m + 1 + i];
    }

    int leftIdx = 0;
    int rightIdx = 0;
    int resIdx = l;

    while (leftIdx < leftSize && rightIdx < rightSize)
    {
        if (left[leftIdx] < right[rightIdx])
        {
            arr[resIdx++] = left[leftIdx++];
        }
        else
        {
            arr[resIdx++] = right[rightIdx++];
        }
    }

    while (leftIdx < leftSize)
    {
        arr[resIdx++] = left[leftIdx++];
    }

    while (rightIdx < rightSize)
    {
        arr[resIdx++] = right[rightIdx++];
    }
}

void MergeSort(vector<p> &arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);

        Merge(arr, l, m, r);
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
        MergeSort(scores, 0, N - 1);

        int res = 0;
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