#include <iostream>
#include <cmath>
using namespace std;

int main (){
    int T;
    cin >> T;
    
    for(int i=0; i<T; i++){
        long long x, y;
        cin >> x >> y;
        
        long long max=0;
        long long move=0;
        while((max*max) <= (y-x)){
            max++;
        }
        max--;
        move = 2 * max -1;
        long long tmp = (y-x) - (max*max);
        tmp = (long long)ceil((double)tmp / (double)max);
        move += tmp;
        cout << move << endl;
    }
}