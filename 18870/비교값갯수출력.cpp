#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> input(N);
    for (int i = 0; i < N; i++)
    {
        cin >> input[i];
    }
    vector<int> tmp(input);

    sort(tmp.begin(), tmp.end());
    /*
        unique 함수란, 중복되는 값을 vector의 가장 마지막으로 옮겨 놓는다.
        중복 원소의 시작 주소값을 반환 합니다.

        erase 함수를 이용해, 중복 원소들을 지웁니다.
    */
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for (int i = 0; i < N; i++)
    {
        /*  lower_bound ( 시작주소, 마지막 주소, lower bound의 기준 값 )
            lower_bound의 반환 값은 iterator, 즉 주소값이므로, 
            반환값 - 배열의 시작주소 하면, 원소 값을 얻을 수 있습니다.
        */
        auto it = lower_bound(tmp.begin(), tmp.end(), input[i]);
        cout << it - tmp.begin() << ' ';
    }
}