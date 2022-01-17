#include <iostream>
using namespace std;

int main () {
    int N;
    cin >> N;
    
    int div=1;
    while(1){
        if(N == 1){
            break;
        }
        ++div;
        if((N%div) == 0){
            N/=div;
            cout << div <<endl;
            div = 1;
        }
    }
    return 0;
}