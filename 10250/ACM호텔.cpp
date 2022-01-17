#include <iostream>
using namespace std;

int main (){
    int T;
    cin >> T;
    
    for(int i=0; i<T; i++){
        int H=0, W=0, N=0;
        cin >> H >> W >> N;
        
        int h = ((N-1) % H)+1;
        int w = ((N-1) / H)+1;
        
        cout << (h*100)+w << endl;
    }
}