#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll; 
using namespace std;

int N;
vector<ll> factorV;

int main()
{
    // 수행 시간 감소를 위한 라인
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    cin >> N;
    
    int tmp;
    for(int i=0; i<N; i++)
    {
        cin >> tmp;
        factorV.push_back(tmp);
    }
    
    sort(begin(factorV), end(factorV));
    
    // 배수는 가장 큰 약수 x 가장 작은 약수
    cout << factorV.front() * factorV.back() << endl;
}