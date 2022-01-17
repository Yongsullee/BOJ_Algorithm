#include <iostream>
#include <cmath>
using namespace std;

int main () {
    while(1){
        int X, max=0, cnt=0;
        bool* prime;
        cin >> X;
        
        if(X == 0)
            return 0;
        
        max = 2*X;
        prime = new bool[max+1];
        fill_n(prime, max+1, 1);
        prime[0] = false;
        prime[1] = false;
        
        for(int i=2; i<=sqrt(max); i++){
            if(prime[i] == true){
                for(int j= i*2; j<=max; j+=i){
                    prime[j] = false;
                }
            }
        }
        
        for(int i=X+1; i<=max; i++){
            if(prime[i] == true){
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}