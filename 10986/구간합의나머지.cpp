#include<iostream>
#include<vector>
using namespace std;

int N, M, x;
long long cnt[1001];
long long sum, ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		sum += x;
		cnt[sum % M]++;
	}

	for (int i = 0; i <= 1000; i++)
	{
		ans += cnt[i] * (cnt[i] - 1) / 2;
	}
	
	cout << cnt[0] + ans;
}

// 실패한 방법, 이중 for문 작성 방법 실패...
/*
    int tmp;
    for(int i=1; i<=N; i++)
    {
        cin >> tmp;
        prefixSum.push_back(tmp + v[i-1]);
    }

    for(int i=1; i<prefixSum.size(); i++)
    {
        for(int j=i; j<prefixSum.size(); j++)
        {
            //...
        }
    }
*/