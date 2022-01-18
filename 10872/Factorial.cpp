#include <iostream>
using namespace std;

int factorial (int input){
    // 0으로 내려가지 않도록 합니다.
    if(input <= 1){
        return 1;
    }
    return input * factorial(input-1); 
}

int main (){
    int N;
    cin >> N;
    
    // 0!은 1입니다!
    int res = 1;
    if(N != 0){
        res = factorial(N);
    }
    cout << res << endl;
}