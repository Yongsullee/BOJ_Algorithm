#include <iostream>
#include <string>

using namespace std;

int main(){
    string A, B;
    cin >> A >> B;
    
    int A_size = A.size();
    int B_size = B.size();
    int ceiling = 0;
    string res;
    
    while(A_size>0 || B_size>0){
        int _A=0;
        if(A_size>0){
            _A = A[--A_size]-'0';
        }
        int _B=0;
        if(B_size>0){
            _B = B[--B_size]-'0';
        }
        int tmp_res = _A + _B + ceiling;
        ceiling = tmp_res/10;
        tmp_res%=10;
        char tmp_res2 = tmp_res + '0';
        res+=tmp_res2;
    }
    if(ceiling>0){
        res+= ceiling + '0';
    }
    for(int i=res.length()-1; i>=0; i--){
        cout << res[i];
    }
}