/*
    재귀 호출 관련 문제임에도 불구하고, 재귀 호출 시 "시간 초과"가 발생하는 미친 문제...
*/

#include <iostream>
#include <string>
using namespace std;

// 주요 포인트 : 두 char가 같을 때, 재귀 호출이 일어난다.

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T; string S;
    cin >> T;
    for(int i=0; i<T; i++)
    {
        cin >> S;
        int right = (int)S.size()-1;
        // 0. 비교를 시작하는 시점에서 재귀 함수를 일단 호출하기 때문에, cnt를 1부터 시작.
        int isPalindrome = 1, cnt = 1;
        for(int left=0; left<right; left++, right--)
        {
            // 1. 두 char가 같지 않으면 반복문을 끝냅니다.
            if(S[left] != S[right])
            {
                isPalindrome = 0;
                break;
            }
            // 2. 두 char가 같을 경우 재귀 호출이 발생했다고 가정하고, cnt를 증가시킵니다.
            cnt++;
        }
        cout << isPalindrome << " " << cnt << '\n';
    }
}

/*
    시간 초과가 발생하는 2번 코드
*/

#include <iostream>
#include <string>
using namespace std;

int recursion(const string S, int l, int r);
int isPalindrome(const string S);
int cnt;
    
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T; string S;
    cin >> T;
    for(int i=0; i<T; i++)
    {
        cnt = 0;
        cin >> S;
        
        cout << isPalindrome(S) << " " << cnt << '\n';
    }
}

int recursion(const string s, int l, int r){
    cnt++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const string s){
    return recursion(s, 0, s.size()-1);
}