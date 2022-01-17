#include <iostream>
using namespace std;

int main (){
    int N;
    cin >> N;
    
    if(N == 1){
        cout << 1 << endl;
        return 0;
    }
    int max_boundary = 1;
    int min_boundary = 1;
    int cnt = 0;
    int ans = 0;
    while(1){
        int diff = 0;
        min_boundary = max_boundary;
        max_boundary +=(cnt * 6);
        if(max_boundary >= N){
            diff = max_boundary - min_boundary;
            ans = (diff/6) + 1;
            cout << ans << endl;
            break;
        }
        cnt++;
    }
}