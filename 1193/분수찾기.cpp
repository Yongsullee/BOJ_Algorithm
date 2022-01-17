#include <iostream>
using namespace std;

int main (){
    int X;
    cin >> X;
    int min_boundary = 0;
    int max_boundary = 0;
    int cnt = 0;
    
    if(X == 1){
        cout << 1 << "/" << 1 << endl;
        return 0;
    }
    while(1){
        int sum = 0;
        min_boundary = max_boundary+1;
        max_boundary += cnt+1;
        if(max_boundary >= X){
            sum = max_boundary - min_boundary + 2;
            if(sum%2 == 0){        //짝수 상행
                cout << (sum-1) - (X - min_boundary) << "/" << 1+(X-min_boundary) << endl;
                break;    
            }else{                 //홀수 하행    
                cout << 1 + (X-min_boundary) << "/" << (sum-1)-(X-min_boundary) << endl;
                break;
            }
        }
        cnt++;
    }
}