#include <iostream>
using namespace std;

int main (){
    int A, B, V;
    cin >> A >> B >> V;
    
    int day = 1;
    day += (V-A)/(A-B);
    if((V-A)%(A-B) != 0){
        day++;
        cout << day << endl;
    }else if (A >= V){
        cout << "1" << endl;
    }
    else{
        cout << day << endl;
    }
}
