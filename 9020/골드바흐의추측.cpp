#include <iostream>
#include <cmath>

using namespace std;

int main () {
    int T;
    cin >> T;
    
    int max=0;
    int* even = new int[T];
    for(int i=0; i<T; i++){
        cin >> even[i];
        if(max < even[i])
            max = even[i];
    }
    bool* prime = new bool[max+1];
    fill_n(prime, max+1, 1);
    prime[0] = false;
    prime[1] = false;
    for(int i=2; i<=sqrt(max); i++){
        if(prime[i] == true){
            for(int j=i*2; j<= max; j+=i){
                prime[j] = false;
            }
        }
    }
    for(int i=0; i<T; i++){
        for(int j=even[i]/2; j>0; j--){
            if(prime[j] && prime[even[i]-j]){
                cout << j << " " << even[i]-j << '\n';
                break;
            }
        }
    }
}