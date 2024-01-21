#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Score
{
    string name;
    int score1, score2, score3;
};

void Merge(vector<Score> &arr, int l, int m, int r)
{
    int leftSize = m - l + 1;
    int rightSize = r - m;

    vector<Score> left(leftSize);
    vector<Score> right(rightSize);

    for (int i = 0; i < leftSize; ++i)
        left[i] = arr[l + i];

    for (int i = 0; i < rightSize; ++i)
        right[i] = arr[m + 1 + i];

    int leftIdx = 0;
    int rightIdx = 0;
    int resIdx = l;

    while (leftIdx < leftSize && rightIdx < rightSize)
    {
        // 국어 점수 기준 내림차순 정렬
        if (left[leftIdx].score1 > right[rightIdx].score1)
        {
            arr[resIdx++] = left[leftIdx++];
        }
        else if (left[leftIdx].score1 < right[rightIdx].score1)
        {
            arr[resIdx++] = right[rightIdx++];
        }
        // 국어 점수가 같다면, 영어 점수 기준 오름차순 정렬
        else
        {
            if (left[leftIdx].score2 < right[rightIdx].score2)
            {
                arr[resIdx++] = left[leftIdx++];
            }
            else if (left[leftIdx].score2 > right[rightIdx].score2)
            {
                arr[resIdx++] = right[rightIdx++];
            }
            // 국어, 영어 점수가 같을 경우, 수학 점수 기준으로 내림차순 정렬
            else
            {
                if (left[leftIdx].score3 > right[rightIdx].score3)
                {
                    arr[resIdx++] = left[leftIdx++];
                }
                else if (left[leftIdx].score3 < right[rightIdx].score3)
                {
                    arr[resIdx++] = right[rightIdx++];
                }
                // 국어, 영어, 수학 점수 같을 경우, 이름 기준 사전순 정렬
                else
                {
                    if (left[leftIdx].name < right[rightIdx].name)
                    {
                        arr[resIdx++] = left[leftIdx++];
                    }
                    else
                    {
                        arr[resIdx++] = right[rightIdx++];
                    }
                }
            }
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

void MergeSort(vector<Score> &arr, int l, int r)
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

    int N;
    cin >> N;

    vector<Score> arr(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i].name >> arr[i].score1 >> arr[i].score2 >> arr[i].score3;
    }

    MergeSort(arr, 0, N - 1);

    for (int i = 0; i < N; ++i)
        cout << arr[i].name << '\n';

    return 0;
}
