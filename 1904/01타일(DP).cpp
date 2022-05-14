#include <iostream>
#include <vector>
using namespace std;

int N;
vector<long long> answer = {0, 1, 2};

/*
    풀이:
        1. N 번째 해답의 갯수는 (N-1)의 갯수 + (N-2)의 갯수와 같습니다.
        2. 이때, 수열의 크기가 엄청 크기 때문에, 데이터 타입 사용에 주의를 기울여야 합니다.
        3. 또한, 데이터 저장시 가장 큰 long long으로 저장합니다.
*/
void FindAnswer(int num)
{
    long long tmp;
    for (int i = 3; i <= num; i++)
    {
        tmp = 0;
        tmp = answer.at(i - 1) + answer.at(i - 2);
        answer.push_back(tmp % 15746);
    }
}

int main()
{
    cin >> N;
    FindAnswer(N);
    cout << answer.at(N) % 15746 << endl;
}